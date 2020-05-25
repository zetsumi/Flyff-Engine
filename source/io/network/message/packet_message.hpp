#pragma once
#include <framework_fengine.h>


namespace fe
{
#pragma warning( disable: 4251 )
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
#pragma warning( default : 4251 )

}