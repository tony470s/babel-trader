#include "ws_service.h"

#include <iostream>

#include "glog/logging.h"

WsService::WsService(QuoteService *quote_service, TradeService *trade_service)
	: quote_(quote_service)
	, trade_(trade_service)
{}

void WsService::onConnection(uWS::WebSocket<uWS::SERVER> *ws, uWS::HttpRequest &req)
{
	LOG(INFO) << "ws connection: " << ws->getAddress().address << ":" << ws->getAddress().port << ", url: " << req.getUrl().toString() << std::endl;
	if (req.getUrl().toString() != "/ws") {
		ws->close();
	}
}
void WsService::onDisconnection(uWS::WebSocket<uWS::SERVER> *ws, int code, char *message, size_t length)
{
	LOG(INFO) << "ws disconnection: " << ws->getAddress().address << ":" << ws->getAddress().port << std::endl;
}
void WsService::onMessage(uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode)
{}