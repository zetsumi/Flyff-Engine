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

	assert(pushAction(PACKETTYPE_CACHE_ADDR, std::bind(&fe::HandlerLogin::onCacheAddr, this)));

	packetOperator[PACKETTYPE_QUERYTICKCOUNT] = std::bind(fe::packettype::queryTick);
	packetOperator[PACKETTYPE_PLAYER_LIST] = std::bind(fe::packettype::playerList);
	packetOperator[PACKETTYPE_LOGIN_PROTECT_NUMPAD] = std::bind(fe::packettype::protectNumPad);
	packetOperator[PACKETTYPE_LOGIN_PROTECT_CERT] = std::bind(fe::packettype::protectLoginCert);
	packetOperator[PACKETTYPE_PRE_JOIN] = std::bind(fe::packettype::preJoin);

}
