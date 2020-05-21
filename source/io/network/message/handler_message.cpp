#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::processPing(SOCKET id)
{
	std::chrono::seconds sec = std::chrono::seconds(30);
	while (true)
	{
		std::this_thread::sleep_for(sec);
		sendPing(id);
	}
}

void fe::HandlerMessage::loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length, fe::type::_32uint& packettype)
{
	mark = packetBuilder.read<fe::type::_uchar>();
	length = packetBuilder.read<fe::type::_32uint>();
	packettype = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("header {%#02x} length{%#010x}{%u} packettype{%#08x}", mark, length, length, packettype);
}

bool fe::HandlerMessage::pushAction(fe::type::_32uint packetType, std::function<void(SOCKET id)> action)
{
	if (action == nullptr)
		return false;
	actions[packetType] = action;
	return true;
}

