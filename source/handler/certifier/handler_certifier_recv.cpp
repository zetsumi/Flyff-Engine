#include <pch_fnetwork.h>
#include <handler/certifier/handler_certifier.hpp>


fe::PacketMessage* fe::HandlerCertifier::onServerList(SOCKET id)
{
	fe::PacketServerList* psl = new PacketServerList();
	*psl << packetBuilder;
	return nullptr;
}