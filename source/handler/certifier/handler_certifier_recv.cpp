#include <pch_fnetwork.h>
#include <handler/certifier/handler_certifier.hpp>


fe::PacketMessage* fe::HandlerCertifier::onServerList()
{
    fe::packet::PacketServerList* psl = new fe::packet::PacketServerList();
    *psl << packetBuilder;
    authKey = psl->authKey;
    return psl;
}
