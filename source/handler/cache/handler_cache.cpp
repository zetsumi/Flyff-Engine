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
	pushAction(fe::packet::PACKETTYPE::JOIN, std::bind(&fe::HandlerCache::onSnapShot, this));
	pushAction(fe::packet::PACKETTYPE::SNAPSHOT, std::bind(&fe::HandlerCache::onSnapShot, this));
}

void fe::HandlerCache::initializeSnapshop(void)
{
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::ENVIRONMENTALL] = std::bind(fe::snapshot::factory::environmentAll);
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::WORLD_READINFO] = std::bind(fe::snapshot::factory::workReadInfo);
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::QUERY_PLAYER_DATA] = std::bind(fe::snapshot::factory::queryPlayerData);
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::DESTPOS] = std::bind(fe::snapshot::factory::destPos);
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERCORR] = std::bind(fe::snapshot::factory::moverCorr);
	snapshotPacket[fe::snapshot::SNAPSHOTTYPE::GETPOS] = std::bind(fe::snapshot::factory::getPosition);
}
