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
			fe::type::_uchar	player = 0;
			fe::type::_32int	hitPoint = 0;
			fe::type::_32uint	forceState = 0;
			fe::type::_32uint	stateFlag = 0;
			fe::type::_uchar	belliGerence = 0;
			fe::type::_32uint	sfxId = 0;

			fe::serialize::SerializeMoverPlayer	moverPlayer{};
			fe::serialize::SerializeMoverNPC	moverNPC{};

			SerializeMover() = default;
			~SerializeMover() = default;

			SerializeMover& operator<<(fe::PacketBuilder& pb)
			{
				motion = pb.read<unsigned char>();
				player = pb.read<fe::type::_uchar>();
				hitPoint = pb.read<fe::type::_32int>();
				forceState = pb.read<fe::type::_32uint>();
				stateFlag = pb.read<fe::type::_32uint>();
				belliGerence = pb.read<fe::type::_uchar>();
				sfxId = pb.read<fe::type::_32uint>();

				if (player == 1)
					moverPlayer << pb;
				else
					moverNPC << pb;

				return *this;
			}
		};
	}
}