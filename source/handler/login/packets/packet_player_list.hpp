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
				fe::type::_32int	slot = 0;
				fe::type::_32int	block = 0;
				fe::type::_32uint	worldID = 0;
				fe::type::_32uint	index = 0;
#pragma endregion
#pragma region Info Joueur
				char* playerName = nullptr;
				fe::util::Vector3D<float>	pos{ 0, 0, 0 };
#pragma endregion
#pragma region Idendifiant
				fe::type::_32uint	idPlayer = 0;
				fe::type::_32uint	idParty = 0;
				fe::type::_32uint	idGuild = 0;
				fe::type::_32uint	idWar = 0;
#pragma endregion
#pragma region Model
				fe::type::_32uint	skinSet = 0;
				fe::type::_32uint	hairMesh = 0;
				fe::type::_32uint	hairColor = 0;
				fe::type::_32uint	headMesh = 0;
#pragma endregion
#pragma region Caracteristiques
				fe::type::_uchar	sex = 0;
				fe::type::_32int	job = 0;
				fe::type::_32int	level = 0;
				fe::type::_32int	jobLevel = 0;
#pragma endregion
#pragma region Statistiques
				fe::type::_32int	str = 0;
				fe::type::_32int	sta = 0;
				fe::type::_32int	dex = 0;
				fe::type::_32int	intel = 0;
				fe::type::_32int	mode = 0;
#pragma endregion
#pragma region Equipment
				fe::type::_32uint	countEquip = 0;
				std::vector<fe::type::_32uint>	equipment;
#pragma endregion

				SlotPlayer() = default;
				~SlotPlayer() = default;
				SlotPlayer& operator<<(fe::PacketBuilder& packetBuilder)
				{
#pragma region Information slot
					slot = packetBuilder.read<fe::type::_32int>();
					block = packetBuilder.read<fe::type::_32int>();
					worldID = packetBuilder.read<fe::type::_32uint>();
					index = packetBuilder.read<fe::type::_32uint>();
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
					idPlayer = packetBuilder.read<fe::type::_32uint>();
					idParty = packetBuilder.read<fe::type::_32uint>();
					idGuild = packetBuilder.read<fe::type::_32uint>();
					idWar = packetBuilder.read<fe::type::_32uint>();
					FE_CONSOLELOG("idPlayer{%u} idParty{%u} idGuild{%u} idWar{%u}",
						idPlayer, idParty, idGuild, idWar
					);
#pragma endregion
#pragma region Model
					skinSet = packetBuilder.read<fe::type::_32uint>();
					hairMesh = packetBuilder.read<fe::type::_32uint>();
					hairColor = packetBuilder.read<fe::type::_32uint>();
					headMesh = packetBuilder.read<fe::type::_32uint>();
					FE_CONSOLELOG("skinSet{%u} hairMesh{%u} hairColor{%#010x} headMesh{%u}",
						skinSet, hairMesh, hairColor, headMesh
					);
#pragma endregion
#pragma region Caracteristiques
					sex = packetBuilder.read<fe::type::_uchar>();
					job = packetBuilder.read<fe::type::_32int>();
					level = packetBuilder.read<fe::type::_32int>();
					jobLevel = packetBuilder.read<fe::type::_32int>();
					FE_CONSOLELOG("sex{%#02x} job{%d} level{%d} jobLevel{%d}",
						sex, job, level, jobLevel
					);
#pragma endregion
#pragma region Statistiques
					str = packetBuilder.read<fe::type::_32int>();
					sta = packetBuilder.read<fe::type::_32int>();
					dex = packetBuilder.read<fe::type::_32int>();
					intel = packetBuilder.read<fe::type::_32int>();
					mode = packetBuilder.read<fe::type::_32int>();
					FE_CONSOLELOG("str{%d} sta{%d} dex{%d} intel{%d} mode{%d}",
						str, sta, dex, intel, mode
					);
#pragma endregion
#pragma region Equipement
					countEquip = packetBuilder.read<fe::type::_32uint>();
					FE_CONSOLELOG("countEquip{%u}",
						countEquip
					);
					for (fe::type::_32uint j = 0; j < countEquip; ++j)
					{
						fe::type::_32uint	idItem = packetBuilder.read<fe::type::_32uint>();
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

					fe::type::_32uint idFriend = 0;
					fe::type::_32uint val1 = 0;
					fe::type::_32uint val2 = 0;

					MessageFriend() = default;
					~MessageFriend() = default;
					MessageFriend& operator<<(fe::PacketBuilder& packetBuilder)
					{
						idFriend = packetBuilder.read<fe::type::_32uint>();
						val1 = packetBuilder.read<fe::type::_32uint>();
						val2 = packetBuilder.read<fe::type::_32uint>();
						return *this;
					}
				};

				fe::type::_uchar indexSlot = 0;
				fe::type::_32uint state = 0;
				fe::type::_32int numberFriend = 0;
				MessageFriend* msgFriend = nullptr;

				MessagePlayer() = default;
				~MessagePlayer() = default;
				MessagePlayer& operator<<(fe::PacketBuilder& packetBuilder)
				{
					indexSlot = packetBuilder.read<fe::type::_uchar>();
					state = packetBuilder.read<fe::type::_32uint>();
					fe::type::_32int numberFriend = packetBuilder.read<fe::type::_32int>();
					if (numberFriend > 200)
						return *this;
					msgFriend = new MessageFriend[numberFriend];
					for (fe::type::_32int i = 0; i < numberFriend; ++i)
						msgFriend[i] << packetBuilder;
					return *this;
				}
			};

			fe::type::_32uint	authKey = 0;
			fe::type::_32int	countPlayer = 0;
			SlotPlayer* slots = nullptr;
			fe::type::_32int	countMessage = 0;
			MessagePlayer* msgBox = nullptr;

			PacketListPlayer() = default;
			~PacketListPlayer() = default;
			PacketListPlayer& operator<<(fe::PacketBuilder& packetBuilder) override
			{
				authKey = packetBuilder.read<fe::type::_32uint>();
				countPlayer = packetBuilder.read<fe::type::_32int>();
				FE_CONSOLELOG("authKey{%u} countPlayer{%d}",
					authKey, countPlayer
				);

				slots = new SlotPlayer[countPlayer]();
				msgBox = new MessagePlayer[countPlayer]();
				for (fe::type::_32int i = 0; i < countPlayer; ++i)
				{
					slots[i] << packetBuilder;
					countMessage = packetBuilder.read<fe::type::_32int>();
					for (fe::type::_32int i = 0; i < countMessage; ++i)
					{
						msgBox[i] << packetBuilder;
					}
				}
				return *this;
			}

			void	release() override final
			{
				for (fe::type::_32int i = 0; i < countPlayer; ++i)
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