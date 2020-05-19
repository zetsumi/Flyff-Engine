#include <pch_fnetwork.h>
#include <handler/handler_login.hpp>

void fe::HandlerLogin::initialize(void)
{
	handlerType = HANDLER_PACKET_TYPE::LOGIN;

	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);
}
