#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>

fe::PacketMessage* fe::HandlerLogin::onQueryTickCount(SOCKET id)
{
	fe::type::_32int timer = packetBuilder.read<fe::type::_32uint>();
	fe::type::_int tick = packetBuilder.read<fe::type::_int>();

	FE_CONSOLELOG("TIME local[%u] server[%d]", timer, tick);

	return nullptr;
}

fe::PacketMessage* fe::HandlerLogin::onCacheAddr(SOCKET id)
{
	cacheServerAddr = const_cast<char*>(packetBuilder.readString());
	FE_CONSOLELOG("cacheServerAddr:{%s}", cacheServerAddr);
	return nullptr;
}

fe::PacketMessage* fe::HandlerLogin::onPlayerList(SOCKET id)
{
	authKey = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32int	countPlayer = packetBuilder.read<fe::type::_32int>();
	FE_CONSOLELOG("authKey{%u} countPlayer{%d}",
		authKey, countPlayer
	);
	for (fe::type::_32int i = 0; i < countPlayer; ++i)
	{
#pragma region Information slot
		fe::type::_32int	slot = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	block = packetBuilder.read<fe::type::_32int>();
		fe::type::_32uint	worldID = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	index = packetBuilder.read<fe::type::_32uint>();
		const char* playerName = packetBuilder.readString();
		FE_CONSOLELOG("slot{%d} block{%u} worldID{%u} index{%u} playerName{%s}",
			slot, block, worldID, index, playerName
		);
#pragma endregion

#pragma region Position
		float x = packetBuilder.read<float>();
		float y = packetBuilder.read<float>();
		float z = packetBuilder.read<float>();
		FE_CONSOLELOG("Position(%f, %f, %f)",
			x, y, z
		);
#pragma endregion


#pragma region Idendifiant
		fe::type::_32uint	idPlayer = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	idParty = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	idGuild = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	idWar = packetBuilder.read<fe::type::_32uint>();
		FE_CONSOLELOG("idPlayer{%u} idParty{%u} idGuild{%u} idWar{%u}",
			idPlayer, idParty, idGuild, idWar
		);
#pragma endregion


#pragma region Model
		fe::type::_32uint	skinSet = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	hairMesh = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	hairColor = packetBuilder.read<fe::type::_32uint>();
		fe::type::_32uint	headMesh = packetBuilder.read<fe::type::_32uint>();
		FE_CONSOLELOG("skinSet{%u} hairMesh{%u} hairColor{%#010x} headMesh{%u}",
			skinSet, hairMesh, hairColor, headMesh
		);
#pragma endregion

#pragma region Caracteristiques
		fe::type::_uchar	sex = packetBuilder.read<fe::type::_uchar>();
		fe::type::_32int	job = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	level = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	jobLevel = packetBuilder.read<fe::type::_32int>();
		FE_CONSOLELOG("sex{%#02x} job{%d} level{%d} jobLevel{%d}",
			sex, job, level, jobLevel
		);
#pragma endregion

#pragma region Statistiques
		fe::type::_32int	str = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	sta = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	dex = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	intel = packetBuilder.read<fe::type::_32int>();
		fe::type::_32int	mode = packetBuilder.read<fe::type::_32int>();
		FE_CONSOLELOG("str{%d} sta{%d} dex{%d} intel{%d} mode{%d}",
			str, sta, dex, intel, mode
		);
#pragma endregion

#pragma region Equipement
		fe::type::_32uint	countEquip = packetBuilder.read<fe::type::_32uint>();
		FE_CONSOLELOG("countEquip{%u}",
			countEquip
		);
		for (fe::type::_32uint j = 0; j < countEquip; ++j)
		{
			fe::type::_32uint	idItem = packetBuilder.read<fe::type::_32uint>();
			FE_CONSOLELOG("idItem{%u}",
				idItem
			);
		}
#pragma endregion

#pragma region Messagerie
		fe::type::_32int	countMessage = packetBuilder.read<fe::type::_32int>();
		for (fe::type::_32int j = 0; j < countMessage; ++j)
		{
			fe::type::_uchar indexSlot = packetBuilder.read<fe::type::_uchar>();
			fe::type::_32uint state = packetBuilder.read<fe::type::_32uint>();

#pragma region Message d amis
			fe::type::_32int numberFriend = packetBuilder.read<fe::type::_32int>();
			FE_CONSOLELOG("indexSlot{%0#2x} state{%u} numberFriend{%u}",
				indexSlot, state, numberFriend
			);
			if (numberFriend > 200)
				break;
			for (fe::type::_32int k = 0; k < numberFriend; ++k)
			{
				fe::type::_32uint idFriend = packetBuilder.read<fe::type::_32uint>();
				fe::type::_32uint val1 = packetBuilder.read<fe::type::_32uint>();
				fe::type::_32uint val2 = packetBuilder.read<fe::type::_32uint>();
				FE_CONSOLELOG("idFriend{%u} val1{%u} val2{%u}",
					idFriend, val1, val2
				);

			}
#pragma endregion
		}
#pragma endregion
	}
	return nullptr;
}

fe::PacketMessage* fe::HandlerLogin::onProtectNumPad(SOCKET id)
{
	fe::type::_32uint idNumPad = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("idNumPad {%u}", idNumPad);
	return nullptr;
}

fe::PacketMessage* fe::HandlerLogin::onProtectLoginCert(SOCKET id)
{
	fe::type::_32uint logged = packetBuilder.read<fe::type::_32uint>();
	fe::type::_32uint idNumPad = packetBuilder.read<fe::type::_32uint>();
	FE_CONSOLELOG("logged:{%u} idNumPad:{%u}", logged, idNumPad);
	return nullptr;
}

fe::PacketMessage* fe::HandlerLogin::onPreJoin(SOCKET id)
{
	FE_CONSOLELOG("");
	return nullptr;
}
