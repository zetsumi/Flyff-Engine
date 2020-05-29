#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::initialize(void)
{
	fe::HandlerMessage::initialize();

	handlerType = HANDLER_PACKET_TYPE::CACHE;
	initializePacketType();
	initializeSnapshop();
}

void fe::HandlerCache::initializePacketType(void)
{
	pushAction(PACKETTYPE_JOIN, std::bind(&fe::HandlerCache::onSnapShot, this));
	pushAction(PACKETTYPE_SNAPSHOT, std::bind(&fe::HandlerCache::onSnapShot, this));
}

void fe::HandlerCache::initializeSnapshop(void)
{
	snapshotPacket[SNAPSHOTTYPE_ENVIRONMENTALL] = std::bind(fe::snapshot::factory::environmentAll);
	snapshotPacket[SNAPSHOTTYPE_WORLD_READINFO] = std::bind(fe::snapshot::factory::workReadInfo);
	snapshotPacket[SNAPSHOTTYPE_QUERY_PLAYER_DATA] = std::bind(fe::snapshot::factory::queryPlayerData);
	snapshotPacket[SNAPSHOTTYPE_DESTPOS] = std::bind(fe::snapshot::factory::destPos);
	snapshotPacket[SNAPSHOTTYPE_MOVERCORR] = std::bind(fe::snapshot::factory::moverCorr);
	snapshotPacket[SNAPSHOTTYPE_GETPOS] = std::bind(fe::snapshot::factory::getPosition);
}
