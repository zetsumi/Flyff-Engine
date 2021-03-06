#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>
#include <ctime>


void fe::HandlerLogin::sendQueryTickCount(fe::type::_SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::QUERYTICKCOUNT);
	pb.write<fe::type::_32int>(static_cast<fe::type::_32uint>(tm));

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerLogin::sendGetListPlayer(fe::type::_SOCKET id, const char* protocolVersion, fe::type::_32uint authKey,
										const char* account, const char* password, fe::type::_32uint idServer)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::GETPLAYERLIST);
	pb.writeString(protocolVersion);
	pb.write<fe::type::_32uint>(authKey);
	pb.writeString(account);
	pb.writeString(password);
	pb.write<fe::type::_32uint>(idServer);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerLogin::sendPreJoin(fe::type::_SOCKET id, const char* account, fe::type::_32uint idPlayer, const char* playerName, fe::type::_32int secretPIN)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::PRE_JOIN);
	pb.writeString(account);
	pb.write<fe::type::_32uint>(idPlayer);
	pb.writeString(playerName);
	pb.write<fe::type::_32int>(secretPIN);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}
