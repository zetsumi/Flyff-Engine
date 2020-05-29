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

	pushAction(fe::packet::PACKETTYPE::CACHE_ADDR, std::bind(&fe::HandlerLogin::onCacheAddr, this));

	packetOperator[fe::packet::PACKETTYPE::QUERYTICKCOUNT] = std::bind(fe::packettype::queryTick);
	packetOperator[fe::packet::PACKETTYPE::PLAYER_LIST] = std::bind(fe::packettype::playerList);
	packetOperator[fe::packet::PACKETTYPE::LOGIN_PROTECT_NUMPAD] = std::bind(fe::packettype::protectNumPad);
	packetOperator[fe::packet::PACKETTYPE::LOGIN_PROTECT_CERT] = std::bind(fe::packettype::protectLoginCert);
	packetOperator[fe::packet::PACKETTYPE::PRE_JOIN] = std::bind(fe::packettype::preJoin);
}
