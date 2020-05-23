#include <pch_fnetwork.h>
#include <handler/handler_certifier.hpp>


void fe::HandlerCertifier::initialize(void)
{

	handlerType = HANDLER_PACKET_TYPE::CERTIFIER;

	ON_PACKETTYPE(PACKETTYPE_WELCOME,		&fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE,	&fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING,			&fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR,			&fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING,	&fe::HandlerMessage::onErrorString);

	ON_PACKETTYPE(PACKETTYPE_SRVR_LIST,		&fe::HandlerCertifier::onServerList);
}

