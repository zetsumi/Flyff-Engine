#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>

fe::PacketMessage* fe::HandlerLogin::onQueryTickCount()
{
	fe::PacketQueryTick* p = new fe::PacketQueryTick();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onCacheAddr()
{
	fe::PacketCacheAddr* p = new fe::PacketCacheAddr();
	*p << packetBuilder;
	size_t len = strlen(p->cacheServerAddr);
	cacheServerAddr = new char[len + 1];
#if defined(_WIN64)
	::memcpy_s(cacheServerAddr, len, p->cacheServerAddr, len);
#elif defined(__APPLE__)
	::memcpy(cacheServerAddr, p->cacheServerAddr, len);
#endif
	cacheServerAddr[len] = '\0';
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onPlayerList()
{
	fe::PacketListPlayer* p = new fe::PacketListPlayer();
	*p << packetBuilder;
	authKey = p->authKey;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectNumPad()
{
	fe::PacketProtectNumPad* p = new fe::PacketProtectNumPad();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectLoginCert()
{
	fe::PacketProtectLoginCert* p = new fe::PacketProtectLoginCert();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onPreJoin()
{
	return nullptr;
}
