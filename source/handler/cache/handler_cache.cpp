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
	ON_PACKETTYPE(PACKETTYPE_JOIN, &fe::HandlerCache::onSnapShot);
	ON_PACKETTYPE(PACKETTYPE_SNAPSHOT, &fe::HandlerCache::onSnapShot);
}

void fe::HandlerCache::initializeSnapshop(void)
{

	this->snapshotPacket[SNAPSHOTTYPE_ENVIRONMENTALL] = std::bind(fe::snapshot::factory::environmentAll);
	this->snapshotPacket[SNAPSHOTTYPE_WORLD_READINFO] = std::bind(fe::snapshot::factory::workReadInfo);
	this->snapshotPacket[SNAPSHOTTYPE_QUERY_PLAYER_DATA] = std::bind(fe::snapshot::factory::queryPlayerData);
	this->snapshotPacket[SNAPSHOTTYPE_DESTPOS] = std::bind(fe::snapshot::factory::destPos);
	this->snapshotPacket[SNAPSHOTTYPE_MOVERCORR] = std::bind(fe::snapshot::factory::moverCorr);
	this->snapshotPacket[SNAPSHOTTYPE_GETPOS] = std::bind(fe::snapshot::factory::getPosition);
}
