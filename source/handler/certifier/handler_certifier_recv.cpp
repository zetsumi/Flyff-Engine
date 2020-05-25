#include <pch_fnetwork.h>
#include <handler/certifier/handler_certifier.hpp>


fe::PacketMessage* fe::HandlerCertifier::onServerList(fe::type::_SOCKET id)
{
	fe::PacketServerList* psl = new PacketServerList();
	*psl << packetBuilder;
	authKey = psl->authKey;
	return psl;
}