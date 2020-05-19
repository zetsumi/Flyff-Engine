#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::sendKeepAlive(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_KEEP_ALIVE);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN)
		builder.write<fe::type::_32uint>(dpid);

	builder.writeHeader(sessionID, handlerType);
	FE_SEND(builder, id);

	lockerSend.unlock();
}


void fe::HandlerMessage::sendError(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_ERROR);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN)
		builder.write<fe::type::_32uint>(dpid);

	builder.writeHeader(sessionID, handlerType);

	FE_SEND(builder, id);

	lockerSend.unlock();
}

void fe::HandlerMessage::sendPing(SOCKET id)
{
	lockerSend.lock();
	fe::PacketBuilder builder;

	builder.write<fe::type::_32uint>(PACKETTYPE_PING);
	if (handlerType == HANDLER_PACKET_TYPE::LOGIN)
		builder.write<fe::type::_32uint>(dpid);
	builder.writeHeader(sessionID, handlerType);
	FE_SEND(builder, id);

	lockerSend.unlock();
}