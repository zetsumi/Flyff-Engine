#include <pch_fnetwork.h>
#include <chrono>
#include <handler/certifier/handler_certifier.hpp>


void fe::HandlerCertifier::sendDisconnectAccount(SOCKET id, const char* account, const char* password)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_CLOSE_EXISTING_CONNECTION);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerCertifier::sendCertify(SOCKET id, const char* buildVersion, const char* account, const char* password)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_CERTIFY);
	pb.writeString(buildVersion);
	pb.writeString(account);
	pb.writeString(password);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

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
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}