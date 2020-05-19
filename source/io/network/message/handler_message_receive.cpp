#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::onMsg(SOCKET id, fe::PacketStructure* ps)
{
	fe::type::_uchar	mark = 0;
	fe::type::_32uint	length = 0;
	fe::type::_32uint	packetType = 0;


	FE_CONSOLELOG("****************");
	packetBuilder.reset();
	if (packetBuilder.setPacket(ps) == false)
	{
		FE_CONSOLELOG("fail on setPacket");
		return;
	}


	loadHeader(mark, length);
	FE_CONSOLELOG("header {%#02x} length{%#010x}{%u}", mark, length, length);

	packetType = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("packet type{%#08x}", packetType);

	auto it = actions.find(packetType);
	if (it != actions.end())
		it->second(id);
	else
		FE_CONSOLELOG("packet type unknow<%#010x>", packetType);

	FE_CONSOLELOG("****************");
}


void fe::HandlerMessage::onWelcome(SOCKET id)
{
	FE_CONSOLELOG("welcome");
	sessionID = packetBuilder.read<fe::type::_32uint>();

	auto fct = std::bind(&HandlerMessage::processPing, this, id);
	ping = std::thread(fct);
	ping.detach();
}

void fe::HandlerMessage::onKeepAlive(SOCKET id)
{
	FE_CONSOLELOG("keep alive");
	sendKeepAlive(id);
}

void fe::HandlerMessage::onPing(SOCKET id)
{
	FE_CONSOLELOG("ping");
}