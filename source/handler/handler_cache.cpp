#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::addSnapShot(unsigned short type, fe::HandlerCache::callbackSnap action)
{
	if (action != nullptr)
	{
		auto fct = std::bind(action, this, std::placeholders::_1, std::placeholders::_2);
		snapshots[type] = fct;
	}
}


void fe::HandlerCache::initialize(void)
{
	handlerType = HANDLER_PACKET_TYPE::CACHE;

	ON_PACKETTYPE(PACKETTYPE_WELCOME, &fe::HandlerMessage::onWelcome);
	ON_PACKETTYPE(PACKETTYPE_KEEP_ALIVE, &fe::HandlerMessage::onKeepAlive);
	ON_PACKETTYPE(PACKETTYPE_PING, &fe::HandlerMessage::onPing);
	ON_PACKETTYPE(PACKETTYPE_ERROR, &fe::HandlerMessage::onError);
	ON_PACKETTYPE(PACKETTYPE_ERROR_STRING, &fe::HandlerMessage::onErrorString);

	ON_PACKETTYPE(PACKETTYPE_JOIN, &fe::HandlerCache::onJoin);
	ON_PACKETTYPE(PACKETTYPE_SNAPSHOT, &fe::HandlerCache::onSnapShot);

	addSnapShot(SNAPSHOTTYPE_QUERY_PLAYER_DATA, &fe::HandlerCache::onQueryPlayerData);
}

void fe::HandlerCache::onSnapShot(SOCKET id)
{
	fe::type::_32uint objIdPlayer = packetBuilder.read<fe::type::_32uint>();
	short count = packetBuilder.read<short>();

	fe::type::_32uint objid = 0;
	FE_CONSOLELOG("objIdPlayer{%#010x}{%u} count{%u}", objIdPlayer, objIdPlayer, count);
	unsigned short snapshotType = 0;
	for (short i = 0; i < count; ++i)
	{
		objid = packetBuilder.read<fe::type::_32uint>();
		snapshotType = packetBuilder.read<unsigned short>();

		FE_CONSOLELOG("objid{%#010x}{%u} snapshotType{%#04x}{%u}", objid, objid, snapshotType, snapshotType);
		auto it = snapshots.find(snapshotType);
		if (it == snapshots.end())
			break;
		it->second(id, objid);
	}
}

void fe::HandlerCache::onJoin(SOCKET id)
{
	FE_CONSOLELOG("");
}


