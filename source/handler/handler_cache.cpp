#include <pch_fnetwork.h>

void fe::HandlerCache::initialize(void)
{
	handlerType = HANDLER_PACKET_TYPE::CACHE;

	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR, &fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING, &fe::HandlerMessage::onErrorString);
}
