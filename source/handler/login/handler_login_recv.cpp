#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>

fe::PacketMessage* fe::HandlerLogin::onQueryTickCount()
{
	fe::packet::PacketQueryTick* p = new fe::packet::PacketQueryTick();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onCacheAddr()
{
	fe::packet::PacketCacheAddr* p = new fe::packet::PacketCacheAddr();
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
	fe::packet::PacketListPlayer* p = new fe::packet::PacketListPlayer();
	*p << packetBuilder;
	authKey = p->authKey;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectNumPad()
{
	fe::packet::PacketProtectNumPad* p = new fe::packet::PacketProtectNumPad();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onProtectLoginCert()
{
	fe::packet::PacketProtectLoginCert* p = new fe::packet::PacketProtectLoginCert();
	*p << packetBuilder;
	return p;
}

fe::PacketMessage* fe::HandlerLogin::onPreJoin()
{
	return nullptr;
}
