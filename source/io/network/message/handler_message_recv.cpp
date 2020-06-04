#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::onMsg(fe::PacketStructure* ps)
{
	fe::packet::PACKETTYPE	packetType = fe::packet::PACKETTYPE::MAX_ERROR;
	fe::type::_uchar		mark = 0;
	fe::type::_32uint		length = 0;
	fe::type::_SOCKET		idSocket = 0;
	unsigned int			lenData = 0;
	fe::PacketMessage*		msg = nullptr;
	mapAction::iterator		itAction = actions.end();
	mapOperator::iterator	itOperator = packetOperator.end();

	FE_CONSOLELOG("****************");
	packetBuilder.reset();
	if (packetBuilder.setPacket(ps) == false)
	{
		FE_CONSOLELOG("fail on setPacket");
		goto end;
	}

	loadHeader(mark, length, packetType);

	idSocket = transaction->getSocket()->getSocket();
	lenData = length - sizeof(packetType); // Taille moins sizeof() packettype
	if (lenData > 0)
	{
		fe::PacketStructure* psData = transaction->receiver(idSocket, lenData);
		packetBuilder.reset();
		if (packetBuilder.setPacket(psData) == false)
		{
			FE_CONSOLELOG("fail on setPacket");
			goto end;
		}
	}

	itAction = actions.find(packetType);
	if (itAction != actions.end())
	{
		msg = itAction->second();
		goto end;
	}

	itOperator = packetOperator.find(packetType);
	if (itOperator != packetOperator.end())
	{
		msg = itOperator->second();
		if (msg != nullptr)
			*msg << packetBuilder;
		goto end;
	}

	FE_CONSOLELOG("packet type unknow<%#010x>", packetType);

end:
	if (msg != nullptr)
	{
		msg->type = packetType;
		mtMessage.lock();
		messages.push(msg);
		mtMessage.unlock();
	}
	packetBuilder.reset();
	FE_CONSOLELOG("****************");
}


fe::PacketMessage* fe::HandlerMessage::onWelcome(void)
{
	sessionID = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("sessionID:{%u}{%#010x}", sessionID);

	auto fct = std::bind(&HandlerMessage::processPing, this);
	ping = std::thread(fct);
	ping.detach();
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onKeepAlive(void)
{
	sendKeepAlive();
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onPing(void)
{
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onError(void)
{
	fe::type::_32uint opcodeError = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("OP CODE: %#010x", opcodeError);
	sendError();
	return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onErrorString(void)
{
	const char* messageError = packetBuilder.readString();
	if (messageError != nullptr)
		FE_CONSOLELOG("Message Error: %s", messageError);
	sendError();
	return nullptr;
}
