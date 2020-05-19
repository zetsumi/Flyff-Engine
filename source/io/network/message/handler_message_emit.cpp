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
	FE_SEND(builder);

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

	FE_SEND(builder);

	lockerSend.unlock();
}

bool fe::HandlerMessage::sendPing(SOCKET id)
{
	try
	{
		lockerSend.lock();
		fe::PacketBuilder builder;

		builder.write<fe::type::_32uint>(PACKETTYPE_PING);
		if (handlerType == HANDLER_PACKET_TYPE::LOGIN)
			builder.write<fe::type::_32uint>(dpid);

		builder.writeHeader(sessionID, handlerType);

		FE_SEND(builder);
		FE_CONSOLELOG("sending ping at <%u>", id);

		lockerSend.unlock();
		return true;
	}
	catch (const std::exception& e)
	{
		FE_CONSOLELOG("error {%s}", e.what());
	}
	return false;
}