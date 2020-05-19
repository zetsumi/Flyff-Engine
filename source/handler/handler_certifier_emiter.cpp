#include <pch_fnetwork.h>
#include <chrono>
#include <handler/handler_certifier.hpp>


void fe::HandlerCertifier::processPing(SOCKET id)
{
	FE_CONSOLELOG("process ping");
	std::chrono::minutes min = std::chrono::minutes(1);
	while (true)
	{
		std::this_thread::sleep_for(min);
		sendPing(id);
	}
}

void fe::HandlerCertifier::sendDisconnectAccount(SOCKET id, const char* account, const char* password)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_CLOSE_EXISTING_CONNECTION);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID);
	FE_SEND(pb);

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

	builder.writeHeader(sessionID);

	FE_SEND(builder);

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendKeepAlive(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_KEEP_ALIVE);

	builder.writeHeader(sessionID);
	FE_SEND(builder);

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendPing(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_PING);

	builder.writeHeader(sessionID);
	FE_SEND(builder);
	FE_CONSOLELOG("sending ping at <%u>", id);

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendError(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_ERROR);

	builder.writeHeader(sessionID);
	FE_SEND(builder);

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendNewAccount(SOCKET id, const char* account, const char* password)
{
	lockerSend.lock();

	fe::PacketBuilder pb;
	pb.write<fe::type::_32uint>(PACKETTYPE_NEW_ACCOUNT);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID);
	FE_SEND(pb);

	lockerSend.unlock();
}
