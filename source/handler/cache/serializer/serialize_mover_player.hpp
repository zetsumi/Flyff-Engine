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
			fe::type::_32int	duelIdParty = 0;
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

				pb >> sex >> skin >> hairMesh >> hairColor >> headMesh;
				pb >> idPlayer;
				pb >> job >> str >> sta >> dex >> intel >> level;
				pb >> fuel >> timeAccFuel;

				fe::type::_uchar uc;
				pb >> uc;
				if (uc == 1)
					pb >> guildId >> warId;
				pb >> guildIdCloak;
				pb >> uc;
				if (uc == 1)
					pb >> partyId >> duelIdParty;

				pb >> authorization >> mode >> stateMode;
				pb >> useItemId;
				pb >> pkTime >> pkValue >> pkPropensity >> pkExp;
				pb >> frame >> duel >> honor;

				return *this;
			}

			void	release(void)
			{
				delete name;
				name = nullptr;
			}
		};
	}
}