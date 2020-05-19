#include <pch_fnetwork.h>
#include <handler/handler_login.hpp>
#include <ctime>

void fe::HandlerLogin::sendPreJoin(SOCKET id)
{
}

void fe::HandlerLogin::sendQueryTickCount(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	std::time_t	tm = std::time(nullptr);
	pb.write<fe::type::_32uint>(PACKETTYPE_QUERYTICKCOUNT);
	pb.write<fe::type::_32int>(static_cast<fe::type::_32uint>(tm));
	pb.writeHeader(sessionID, handlerType);
	FE_SEND(pb, id);

	lockerSend.unlock();
}