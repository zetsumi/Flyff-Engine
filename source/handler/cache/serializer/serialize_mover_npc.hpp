#pragma once

#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	namespace serialize
	{
		struct SerializeMoverNPC
		{
			SerializeMoverNPC() = default;
			~SerializeMoverNPC() = default;

			SerializeMoverNPC& operator<<(fe::PacketBuilder& pb)
			{
				return *this;
			}
		};
	}
}