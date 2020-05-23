#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>

fe::PacketMessage* fe::HandlerLogin::onQueryTickCount(SOCKET id)
{
	fe::PacketQueryTick* pqt = new fe::PacketQueryTick();
	*pqt << packetBuilder;
	return pqt;
}

fe::PacketMessage* fe::HandlerLogin::onCacheAddr(SOCKET id)
{
	fe::PacketCacheAddr* p = new fe::PacketCacheAddr();
	*p << packetBuilder;
	size_t len = strlen(p->cacheServerAddr);
	cacheServerAddr = new char[len + 1];
	memcpy_s(cacheServerAddr, len, p->cacheServerAddr, len);
	cacheServerAddr[len] = '\0';
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onPlayerList(SOCKET id)
{
	fe::PacketListPlayer* p = new fe::PacketListPlayer();
	*p << packetBuilder;
	authKey = p->authKey;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectNumPad(SOCKET id)
{
	fe::PacketProtectNumPad* p = new fe::PacketProtectNumPad();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectLoginCert(SOCKET id)
{
	fe::PacketProtectLoginCert* p = new fe::PacketProtectLoginCert();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onPreJoin(SOCKET id)
{
	return nullptr;
}
