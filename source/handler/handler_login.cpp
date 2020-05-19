#include <pch_fnetwork.h>
#include <handler/handler_login.hpp>



void fe::HandlerLogin::initialize(void)
{
	handlerType = HANDLER_PACKET_TYPE::LOGIN;

	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);

	ON_PACKETTYPE(PACKETTYPE_QUERYTICKCOUNT, &fe::HandlerLogin::onQueryTickCount);
}

void fe::HandlerLogin::onQueryTickCount(SOCKET id)
{
	fe::type::_32int timer = packetBuilder.read<fe::type::_32uint>();
	fe::type::_int tick = packetBuilder.read<fe::type::_int>();

	FE_CONSOLELOG("TIME local[%u] server[%d]", timer, tick);
}
