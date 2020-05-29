#include <pch_fnetwork.h>
#include <handler/certifier/handler_certifier.hpp>


void fe::HandlerCertifier::initialize(void)
{

	handlerType = HANDLER_PACKET_TYPE::CERTIFIER;
	fe::HandlerMessage::initialize();

	packetOperator[PACKETTYPE_SRVR_LIST] = std::bind(fe::packettype::serveurList);
}
