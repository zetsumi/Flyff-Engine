#include <pch_fnetwork.h>
#include <chrono>
#include <handler/handler_certifier.hpp>


void fe::HandlerCertifier::sendDisconnectAccount(SOCKET id, const char* account, const char* password)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_CLOSE_EXISTING_CONNECTION);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID, handlerType);
	FE_SEND(pb, id);

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendCertify(SOCKET id, const char* buildVersion, const char* account, const char* password)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_CERTIFY);
	builder.writeString(buildVersion);
	builder.writeString(account);
	builder.writeString(password);

	builder.writeHeader(sessionID, handlerType);

	FE_SEND(builder, id);

	lockerSend.unlock();
}


void fe::HandlerCertifier::sendNewAccount(SOCKET id, const char* account, const char* password)
{
	lockerSend.lock();

	fe::PacketBuilder pb;
	pb.write<fe::type::_32uint>(PACKETTYPE_NEW_ACCOUNT);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID, handlerType);
	FE_SEND(pb, id);

	lockerSend.unlock();
}
