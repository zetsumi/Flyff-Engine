#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::sendKeepAlive()
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::KEEP_ALIVE);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}


void fe::HandlerMessage::sendError()
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::PERROR);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerMessage::sendPing()
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::PING);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
		pb.write<fe::type::_32uint>(dpid);
	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}