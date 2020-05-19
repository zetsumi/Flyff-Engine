#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::processPing(SOCKET id)
{
	FE_CONSOLELOG("process ping");
	//std::chrono::minutes min = std::chrono::minutes(1);
	std::chrono::seconds min = std::chrono::seconds(5);
	while (true)
	{
		std::this_thread::sleep_for(min);
		if (sendPing(id) == false)
			break;
	}
}

void fe::HandlerMessage::loadHeader(fe::type::_uchar& mark, fe::type::_32uint& length)
{
	mark = packetBuilder.read<fe::type::_uchar>();
	length = packetBuilder.read<fe::type::_32uint>();
}

bool fe::HandlerMessage::pushAction(fe::type::_32uint packetType, std::function<void(SOCKET id)> action)
{
	if (action == nullptr)
		return false;
	actions[packetType] = action;
	return true;
}

