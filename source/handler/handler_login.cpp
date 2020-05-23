#include <pch_fnetwork.h>
#include <handler/handler_login.hpp>


const char* fe::HandlerLogin::getCacheServerAddr(void) const
{
	return cacheServerAddr;
}


void fe::HandlerLogin::initialize(void)
{
	handlerType = HANDLER_PACKET_TYPE::LOGIN;


	ON_PACKETTYPE(PACKETTYPE_WELCOME,		&fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE,	&fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING,			&fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR,			&fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING,	&fe::HandlerMessage::onErrorString);


	ON_PACKETTYPE(PACKETTYPE_QUERYTICKCOUNT,		&fe::HandlerLogin::onQueryTickCount);
	ON_PACKETTYPE(PACKETTYPE_CACHE_ADDR,			&fe::HandlerLogin::onCacheAddr);
	ON_PACKETTYPE(PACKETTYPE_PLAYER_LIST,			&fe::HandlerLogin::onPlayerList);
	ON_PACKETTYPE(PACKETTYPE_LOGIN_PROTECT_NUMPAD,	&fe::HandlerLogin::onProtectNumPad);
	ON_PACKETTYPE(PACKETTYPE_LOGIN_PROTECT_CERT,	&fe::HandlerLogin::onProtectLoginCert);
	ON_PACKETTYPE(PACKETTYPE_PRE_JOIN,				&fe::HandlerLogin::onPreJoin);
}
