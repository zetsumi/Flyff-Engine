#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>



void fe::HandlerMessage::loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length)
{
	mark = pb.read<fe::type::_uchar>();
	length = pb.read<fe::type::_32uint>();
}

bool fe::HandlerMessage::pushAction(fe::type::_uint packetType, std::function<void(SOCKET id)> action)
{
	if (action == nullptr)
		return false;
	actions[packetType] = action;
	return true;
}

void fe::HandlerMessage::onMsg(SOCKET id, fe::PacketStructure* ps)
{
	fe::type::_uchar	mark = 0;
	fe::type::_32uint	length = 0;
	fe::type::_32uint	packetType = 0;


	FE_CONSOLELOG("****************");
	pb.reset();
	if (pb.setPacket(ps) == false)
	{
		FE_CONSOLELOG("fail on setPacket");
		return;
	}


	loadHeader(mark, length);
	FE_CONSOLELOG("header {%#02x} length{%#010x}{%u}", mark, length, length);

	packetType = pb.read<fe::type::_32uint>();
	FE_CONSOLELOG("packet type{%#08x}", packetType);

	auto it = actions.find(packetType);
	if (it != actions.end())
		it->second(id);
	else
		FE_CONSOLELOG("packet type unknow<%#010x>", packetType);

	FE_CONSOLELOG("****************");
}
