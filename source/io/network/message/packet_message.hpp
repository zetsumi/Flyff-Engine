#pragma once
#include <framework_fengine.h>
#include <assert.h>


namespace fe
{
#pragma warning( disable: 4251 )
	struct API_DECLSPEC PacketMessage
	{
		fe::type::_32uint	type = 0;

		PacketMessage(PacketMessage&& pm) = delete;
		PacketMessage(const PacketMessage& pm) = delete;
		inline PacketMessage(PacketMessage* pm) = delete;
		PacketMessage& operator=(const PacketMessage& pm) = delete;

		PacketMessage() = default;
		virtual ~PacketMessage() = default;
		virtual PacketMessage& operator<<(fe::PacketBuilder&) = 0;
	};
#pragma warning( default : 4251 )

}