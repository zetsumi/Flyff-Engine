#include <pch_fnetwork.h>
#include <handler/certifier/handler_certifier.hpp>


void fe::HandlerCertifier::initialize()
{

    handlerType = HANDLER_PACKET_TYPE::CERTIFIER;
    fe::HandlerMessage::initialize();

    pushAction(fe::packet::PACKETTYPE::SRVR_LIST, std::bind(&fe::HandlerCertifier::onServerList, this));

}
