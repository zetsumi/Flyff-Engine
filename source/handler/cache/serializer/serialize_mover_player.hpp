#pragma once

#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	namespace serialize
	{
		struct SerializeMoverPlayer
		{

			char*				name = nullptr;
			uint8_t	sex = 0;
			uint8_t	skin = 0;
			uint8_t	hairMesh = 0;
			uint32_t	hairColor = 0x00;
			uint8_t	headMesh = 0;
			uint32_t	idPlayer = 0;
			uint8_t	job = 0;
			unsigned short	str = 0;
			unsigned short	sta = 0;
			unsigned short	dex = 0;
			unsigned short	intel = 0;
			unsigned short	level = 0;
			int32_t	fuel = 0;
			int32_t	timeAccFuel = 0;
			int32_t	guildId = 0;
			int32_t	warId = 0;
			int32_t	guildIdCloak = 0;
			int32_t	partyId = 0;
			int32_t	duelIdParty = 0;
			uint8_t	authorization = 0;
			uint32_t	mode = 0;
			uint32_t	stateMode = 0;
			uint32_t	useItemId = 0;
			uint32_t	pkTime = 0;
			int32_t	pkValue = 0;
			uint32_t	pkPropensity = 0;
			uint32_t	pkExp = 0;
			uint32_t	frame = 0;
			uint8_t	duel = 0;
			int32_t	honor = 0;

			SerializeMoverPlayer() = default;
			~SerializeMoverPlayer() = default;

			SerializeMoverPlayer& operator<<(fe::PacketBuilder& pb)
			{
				name = const_cast<char*>(pb.readString());

				pb >> sex >> skin >> hairMesh >> hairColor >> headMesh;
				pb >> idPlayer;
				pb >> job >> str >> sta >> dex >> intel >> level;
				pb >> fuel >> timeAccFuel;

				uint8_t uc;
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

			void	release()
			{
				delete name;
				name = nullptr;
			}
		};
	}
}