#include <pch_fnetwork.h>
#include <io/network/message/handler_certifier.hpp>

void fe::HandlerCertifier::sendCertify(SOCKET id, const char* buildVersion, const char* account, const char* password)
{
	fe::PacketBuilder pb;

	pb.write<unsigned int>(PACKETTYPE_CERTIFY);
	pb.writeString(buildVersion);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID);

	FE_SEND(pb);
}

void fe::HandlerCertifier::sendKeepAlive(SOCKET id)
{
	fe::PacketBuilder pb;

	pb.write<unsigned int>(PACKETTYPE_KEEP_ALIVE);
	pb.writeHeader(sessionID);

	FE_SEND(pb);
}
