#pragma once
#include <framework_fengine.h>
#include <io/network/message/packet_type.hpp>


namespace fe
{
#pragma warning( disable: 4251 )
	struct API_DECLSPEC PacketMessage
	{
		fe::packet::PACKETTYPE	type = fe::packet::PACKETTYPE::MAX_ERROR;

		PacketMessage(PacketMessage&& pm) = delete;
		PacketMessage(const PacketMessage& pm) = delete;
		PacketMessage(PacketMessage* pm) = delete;
		PacketMessage& operator=(const PacketMessage& pm) = delete;

		PacketMessage() = default;
		virtual ~PacketMessage() = default;
		virtual PacketMessage& operator<<(fe::PacketBuilder&) = 0;
		virtual void release() {}
	};
#pragma warning( default : 4251 )

}