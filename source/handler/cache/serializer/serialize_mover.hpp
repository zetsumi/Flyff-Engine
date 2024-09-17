#pragma once

#include <io/network/emit/packet_builder.hpp>
#include <handler/cache/serializer/serialize_mover_player.hpp>
#include <handler/cache/serializer/serialize_mover_npc.hpp>

namespace fe
{
	namespace serialize
	{
		struct SerializeMover
		{

			unsigned short		motion = 0;
			uint8_t	player = 0;
			int32_t	hitPoint = 0;
			uint32_t	forceState = 0;
			uint32_t	stateFlag = 0;
			uint8_t	belliGerence = 0;
			uint32_t	sfxId = 0;

			fe::serialize::SerializeMoverPlayer	moverPlayer{};
			fe::serialize::SerializeMoverNPC	moverNPC{};

			SerializeMover() = default;
			~SerializeMover() = default;

			SerializeMover& operator<<(fe::PacketBuilder& pb)
			{
				motion = pb.read<unsigned char>();
				player = pb.read<uint8_t>();
				hitPoint = pb.read<int32_t>();
				forceState = pb.read<uint32_t>();
				stateFlag = pb.read<uint32_t>();
				belliGerence = pb.read<uint8_t>();
				sfxId = pb.read<uint32_t>();

				if (player == 1)
					moverPlayer << pb;
				else
					moverNPC << pb;

				return *this;
			}
		};
	}
}