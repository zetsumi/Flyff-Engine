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
	FE_CONSOLELOG("****");
	fe::type::_uchar	mark;
	fe::type::_32uint		length;
	fe::type::_32uint		packetType;

	pb.setPacket(ps);

	loadHeader(mark, length);

	packetType = pb.read<fe::type::_32uint>();

	FE_CONSOLELOG("header {%#08x}{%#08x}", mark, length);
	FE_CONSOLELOG("packet type<%#08x>", packetType);

	auto it = actions.find(packetType);
	if (it != actions.end())
		it->second(id);
	else
		FE_CONSOLELOG("packet unknow<%#08x>", packetType);

	FE_CONSOLELOG("****");
}

void fe::HandlerMessage::onWelcome(SOCKET id)
{
	FE_CONSOLELOG("welcome");
	fe::type::_uint session = pb.read<fe::type::_uint>();
}
