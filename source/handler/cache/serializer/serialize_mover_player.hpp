#pragma once

#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	namespace serialize
	{
		struct SerializeMoverPlayer
		{

			char*				name = nullptr;
			fe::type::_uchar	sex = 0;

			fe::type::_uchar	skin = 0;
			fe::type::_uchar	hairMesh = 0;
			fe::type::_32uint	hairColor = 0x00;
			fe::type::_uchar	headMesh = 0;

			fe::type::_32uint	idPlayer = 0;
			fe::type::_uchar	job = 0;
			fe::type::_ushort	str = 0;
			fe::type::_ushort	sta = 0;
			fe::type::_ushort	dex = 0;
			fe::type::_ushort	intel = 0;
			fe::type::_ushort	level = 0;
			fe::type::_32int	fuel = 0;
			fe::type::_32int	timeAccFuel = 0;

			fe::type::_32int	guildId = 0;
			fe::type::_32int	warId = 0;
			fe::type::_32int	guildIdCloak = 0;
			fe::type::_32int	partyId = 0;
			fe::type::_32int	uelIdParty = 0;

			fe::type::_uchar	authorization = 0;
			fe::type::_32uint	mode = 0;
			fe::type::_32uint	stateMode = 0;

			fe::type::_32uint	useItemId = 0;

			fe::type::_32uint	pkTime = 0;
			fe::type::_32int	pkValue = 0;
			fe::type::_32uint	pkPropensity = 0;
			fe::type::_32uint	pkExp = 0;

			fe::type::_32uint	frame = 0;
			fe::type::_uchar	duel = 0;
			fe::type::_32int	honor = 0;

			SerializeMoverPlayer() = default;
			~SerializeMoverPlayer() = default;

			SerializeMoverPlayer& operator<<(fe::PacketBuilder& pb)
			{
				name = const_cast<char*>(pb.readString());
				sex = pb.read<fe::type::_uchar>();
				skin = pb.read<fe::type::_uchar>();
				hairMesh = pb.read<fe::type::_uchar>();
				hairColor = pb.read<fe::type::_32uint>();
				headMesh = pb.read<fe::type::_uchar>();

				idPlayer = pb.read<fe::type::_uchar>();
				job = pb.read<fe::type::_uchar>();
				str = pb.read<fe::type::_uchar>();
				sta = pb.read<fe::type::_uchar>();
				dex = pb.read<fe::type::_uchar>();
				intel = pb.read<fe::type::_uchar>();
				level = pb.read<fe::type::_uchar>();

				fuel = pb.read<fe::type::_32int>();
				timeAccFuel = pb.read<fe::type::_32int>();

				fe::type::_uchar uc;
				uc = pb.read<fe::type::_uchar>();
				if (uc == 1)
				{
					guildId = pb.read<fe::type::_32int>();
					warId = pb.read<fe::type::_32int>();
				}
				guildIdCloak = pb.read<fe::type::_32int>();
				uc = pb.read<fe::type::_uchar>();
				if (uc == 1)
				{
					partyId = pb.read<fe::type::_32int>();
					uelIdParty = pb.read<fe::type::_32int>();
				}

				authorization = pb.read<fe::type::_uchar>();
				mode = pb.read<fe::type::_32uint>();
				stateMode = pb.read<fe::type::_32uint>();
				useItemId = pb.read<fe::type::_32uint>();

				pkTime = pb.read<fe::type::_32uint>();
				pkValue = pb.read<fe::type::_32int>();
				pkPropensity = pb.read<fe::type::_32uint>();
				pkExp = pb.read<fe::type::_32uint>();

				frame = pb.read<fe::type::_32uint>();
				duel = pb.read<fe::type::_uchar>();
				honor = pb.read<fe::type::_32int>();

				return *this;
			}
		};
	}
}