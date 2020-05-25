#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::sendKeepAlive(fe::type::_SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_KEEP_ALIVE);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}


void fe::HandlerMessage::sendError(fe::type::_SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_ERROR);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerMessage::sendPing(fe::type::_SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_PING);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);
	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}