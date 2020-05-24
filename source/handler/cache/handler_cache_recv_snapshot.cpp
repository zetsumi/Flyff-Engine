#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::initializeSnapshop(void)
{
	addSnapShot(SNAPSHOTTYPE_ENVIRONMENTALL, &fe::HandlerCache::onEnvironmentAll);
	addSnapShot(SNAPSHOTTYPE_WORLD_READINFO, &fe::HandlerCache::onWorldReadInfo);
	addSnapShot(SNAPSHOTTYPE_QUERY_PLAYER_DATA, &fe::HandlerCache::onQueryPlayerData);
	addSnapShot(SNAPSHOTTYPE_DESTPOS, &fe::HandlerCache::onDestPos);
	addSnapShot(SNAPSHOTTYPE_MOVERCORR, &fe::HandlerCache::onMoverCorr);
	addSnapShot(SNAPSHOTTYPE_GETPOS, &fe::HandlerCache::onGetPosition);
}

fe::PacketMessage* fe::HandlerCache::onEnvironmentAll(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotEnvironmentAll* s = new fe::SnapshotEnvironmentAll();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onWorldReadInfo(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotWorldReadInfo* s = new fe::SnapshotWorldReadInfo();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onAddObj(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotAddObj* s = new fe::SnapshotAddObj();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onQueryPlayerData(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotQueryPlayerData* s = new fe::SnapshotQueryPlayerData();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onDestPos(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotDestPos* s = new fe::SnapshotDestPos();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onMoverCorr(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotMoverCorr* s = new fe::SnapshotMoverCorr();
	*s << packetBuilder;
	return s;
}

fe::PacketMessage* fe::HandlerCache::onGetPosition(PARAMETERS_FUNCTION_SNAPSHOT)
{
	fe::SnapshotGetPosition* s = new fe::SnapshotGetPosition();
	*s << packetBuilder;
	return s;
}
