#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketListPlayer : public PacketMessage
		{
			struct SlotPlayer
			{
#pragma region Information slot
				int32_t	slot = 0;
				int32_t	block = 0;
				uint32_t	worldID = 0;
				uint32_t	index = 0;
#pragma endregion
#pragma region Info Joueur
				char* playerName = nullptr;
				fe::util::Vector3D<float>	pos{ 0, 0, 0 };
#pragma endregion
#pragma region Idendifiant
				uint32_t	idPlayer = 0;
				uint32_t	idParty = 0;
				uint32_t	idGuild = 0;
				uint32_t	idWar = 0;
#pragma endregion
#pragma region Model
				uint32_t	skinSet = 0;
				uint32_t	hairMesh = 0;
				uint32_t	hairColor = 0;
				uint32_t	headMesh = 0;
#pragma endregion
#pragma region Caracteristiques
				uint8_t	sex = 0;
				int32_t	job = 0;
				int32_t	level = 0;
				int32_t	jobLevel = 0;
#pragma endregion
#pragma region Statistiques
				int32_t	str = 0;
				int32_t	sta = 0;
				int32_t	dex = 0;
				int32_t	intel = 0;
				int32_t	mode = 0;
#pragma endregion
#pragma region Equipment
				uint32_t	countEquip = 0;
				std::vector<uint32_t>	equipment;
#pragma endregion

				SlotPlayer() = default;
				~SlotPlayer() = default;
				SlotPlayer& operator<<(fe::PacketBuilder& packetBuilder)
				{
#pragma region Information slot
					slot = packetBuilder.read<int32_t>();
					block = packetBuilder.read<int32_t>();
					worldID = packetBuilder.read<uint32_t>();
					index = packetBuilder.read<uint32_t>();
#pragma endregion
#pragma region Info Joeur
					playerName = const_cast<char*>(packetBuilder.readString());
					pos.x = packetBuilder.read<float>();
					pos.y = packetBuilder.read<float>();
					pos.z = packetBuilder.read<float>();
					FE_CONSOLELOG("Name{%s} Position(%f, %f, %f)",
						playerName, pos.x, pos.y, pos.z
					);
#pragma endregion
#pragma region Idendifiant
					idPlayer = packetBuilder.read<uint32_t>();
					idParty = packetBuilder.read<uint32_t>();
					idGuild = packetBuilder.read<uint32_t>();
					idWar = packetBuilder.read<uint32_t>();
					FE_CONSOLELOG("idPlayer{%u} idParty{%u} idGuild{%u} idWar{%u}",
						idPlayer, idParty, idGuild, idWar
					);
#pragma endregion
#pragma region Model
					skinSet = packetBuilder.read<uint32_t>();
					hairMesh = packetBuilder.read<uint32_t>();
					hairColor = packetBuilder.read<uint32_t>();
					headMesh = packetBuilder.read<uint32_t>();
					FE_CONSOLELOG("skinSet{%u} hairMesh{%u} hairColor{%#010x} headMesh{%u}",
						skinSet, hairMesh, hairColor, headMesh
					);
#pragma endregion
#pragma region Caracteristiques
					sex = packetBuilder.read<uint8_t>();
					job = packetBuilder.read<int32_t>();
					level = packetBuilder.read<int32_t>();
					jobLevel = packetBuilder.read<int32_t>();
					FE_CONSOLELOG("sex{%#02x} job{%d} level{%d} jobLevel{%d}",
						sex, job, level, jobLevel
					);
#pragma endregion
#pragma region Statistiques
					str = packetBuilder.read<int32_t>();
					sta = packetBuilder.read<int32_t>();
					dex = packetBuilder.read<int32_t>();
					intel = packetBuilder.read<int32_t>();
					mode = packetBuilder.read<int32_t>();
					FE_CONSOLELOG("str{%d} sta{%d} dex{%d} intel{%d} mode{%d}",
						str, sta, dex, intel, mode
					);
#pragma endregion
#pragma region Equipement
					countEquip = packetBuilder.read<uint32_t>();
					FE_CONSOLELOG("countEquip{%u}",
						countEquip
					);
					for (uint32_t j = 0; j < countEquip; ++j)
					{
						uint32_t	idItem = packetBuilder.read<uint32_t>();
						equipment.emplace_back(idItem);
						FE_CONSOLELOG("idItem{%u}",
							idItem
						);
					}
#pragma endregion
					return *this;
				}
			};
			struct MessagePlayer
			{
				struct MessageFriend
				{

					uint32_t idFriend = 0;
					uint32_t val1 = 0;
					uint32_t val2 = 0;

					MessageFriend() = default;
					~MessageFriend() = default;
					MessageFriend& operator<<(fe::PacketBuilder& packetBuilder)
					{
						idFriend = packetBuilder.read<uint32_t>();
						val1 = packetBuilder.read<uint32_t>();
						val2 = packetBuilder.read<uint32_t>();
						return *this;
					}
				};

				uint8_t indexSlot = 0;
				uint32_t state = 0;
				int32_t numberFriend = 0;
				MessageFriend* msgFriend = nullptr;

				MessagePlayer() = default;
				~MessagePlayer() = default;
				MessagePlayer& operator<<(fe::PacketBuilder& packetBuilder)
				{
					indexSlot = packetBuilder.read<uint8_t>();
					state = packetBuilder.read<uint32_t>();
					int32_t numberFriend = packetBuilder.read<int32_t>();
					if (numberFriend > 200)
						return *this;
					msgFriend = new MessageFriend[numberFriend];
					for (int32_t i = 0; i < numberFriend; ++i)
						msgFriend[i] << packetBuilder;
					return *this;
				}
			};

			uint32_t	authKey = 0;
			int32_t	countPlayer = 0;
			SlotPlayer* slots = nullptr;
			int32_t	countMessage = 0;
			MessagePlayer* msgBox = nullptr;

			PacketListPlayer() = default;
			~PacketListPlayer() = default;
			PacketListPlayer& operator<<(fe::PacketBuilder& packetBuilder) override
			{
				authKey = packetBuilder.read<uint32_t>();
				countPlayer = packetBuilder.read<int32_t>();
				FE_CONSOLELOG("authKey{%u} countPlayer{%d}",
					authKey, countPlayer
				);

				slots = new SlotPlayer[countPlayer]();
				msgBox = new MessagePlayer[countPlayer]();
				for (int32_t i = 0; i < countPlayer; ++i)
				{
					slots[i] << packetBuilder;
					countMessage = packetBuilder.read<int32_t>();
					for (int32_t i = 0; i < countMessage; ++i)
					{
						msgBox[i] << packetBuilder;
					}
				}
				return *this;
			}

			void	release() override final
			{
				for (int32_t i = 0; i < countPlayer; ++i)
				{
					delete slots[i].playerName;
					slots[i].playerName = nullptr;
					delete[] msgBox[i].msgFriend;
					msgBox[i].msgFriend = nullptr;
				}
				delete[] slots;
				slots = nullptr;
				delete[] msgBox;
				msgBox = nullptr;
			}
		};
	}
}