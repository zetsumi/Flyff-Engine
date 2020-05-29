#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>


const char* fe::HandlerLogin::getCacheServerAddr(void) const
{
	return cacheServerAddr;
}


void fe::HandlerLogin::initialize(void)
{
	fe::HandlerMessage::initialize();

	handlerType = HANDLER_PACKET_TYPE::LOGIN;

	ON_PACKETTYPE(PACKETTYPE_QUERYTICKCOUNT,		&fe::HandlerLogin::onQueryTickCount);
	ON_PACKETTYPE(PACKETTYPE_CACHE_ADDR,			&fe::HandlerLogin::onCacheAddr);
	ON_PACKETTYPE(PACKETTYPE_PLAYER_LIST,			&fe::HandlerLogin::onPlayerList);
	ON_PACKETTYPE(PACKETTYPE_LOGIN_PROTECT_NUMPAD,	&fe::HandlerLogin::onProtectNumPad);
	ON_PACKETTYPE(PACKETTYPE_LOGIN_PROTECT_CERT,	&fe::HandlerLogin::onProtectLoginCert);
	ON_PACKETTYPE(PACKETTYPE_PRE_JOIN,				&fe::HandlerLogin::onPreJoin);
}
