#pragma once
#include <framework_fengine.h>


namespace fe
{
	struct API_DECLSPEC PacketMessage
	{
		fe::type::_32uint	type = 0;

		PacketMessage() = default;
		virtual ~PacketMessage() = default;
		PacketMessage(PacketMessage&& pm) = default;
		PacketMessage(const PacketMessage& pm) = default;
		PacketMessage(PacketMessage* pm) : PacketMessage(*pm) {};
		PacketMessage& operator=(const PacketMessage& pm) = default;
	};
}