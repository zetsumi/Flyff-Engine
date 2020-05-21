#include <pch_fnetwork.h>

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
}

void fe::HandlerCache::onSnapShot(SOCKET id)
{
	fe::type::_32uint objIdPlayer = packetBuilder.read<fe::type::_32uint>();
	short count = packetBuilder.read<short>();
	FE_CONSOLELOG("objIdPlayer{%#010x}{%u} header{%u}", objIdPlayer, objIdPlayer, count);

	fe::type::_32uint objid = 0;
	unsigned short snapshotType = 0;
	for (short i = 0; i < count; ++i)
	{
		objid = packetBuilder.read<fe::type::_32uint>();
		snapshotType = packetBuilder.read<unsigned short>();

		FE_CONSOLELOG("objid{%#010x}{%u} snapshotType{%#04x}{%u}", objid, objid, snapshotType);
	}
}

void fe::HandlerCache::onJoin(SOCKET id)
{
	FE_CONSOLELOG("");
}


