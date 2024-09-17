#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

fe::PacketMessage* fe::HandlerCache::onSnapShot()
{
	uint32_t objIdPlayer = packetBuilder.read<uint32_t>();
	short count = packetBuilder.read<short>();

	uint32_t objid = 0;
	FE_CONSOLELOG("objIdPlayer{%#010x}{%u} count{%u}", objIdPlayer, objIdPlayer, count);

	// Initialise le tableau de snapshot
	snapshot::SnapshotList* snapList = new snapshot::SnapshotList();
	snapList->snaps = new snapshot::Snapshot*[count]();
	for (unsigned short i = 0; i < count; ++i)
		snapList->snaps[i] = nullptr;

	fe::snapshot::SNAPSHOTTYPE snapshotType = fe::snapshot::SNAPSHOTTYPE::MAX_ERROR;
	for (unsigned short i = 0; i < count; ++i)
	{
		objid = packetBuilder.read<uint32_t>();
		snapshotType = packetBuilder.read<fe::snapshot::SNAPSHOTTYPE>();
		FE_CONSOLELOG("objid{%#010x}{%u} snapshotType{%#04x}{%u}", objid, objid, snapshotType, snapshotType);

		auto it = snapshotPacket.find(snapshotType);
		if (it == snapshotPacket.end())
		{
			FE_CONSOLELOG("snapshotType{%#04x} unknow", snapshotType);
			break;
		}

		// Set snapshot
		snapList->snaps[i] = it->second();
		if (snapList->snaps[i] == nullptr)
			return nullptr;
		snapList->snaps[i]->objid = objid;
		snapList->snaps[i]->objIdPlayer = objIdPlayer;
		snapList->snaps[i]->snapshotType = snapshotType;
		*(snapList->snaps[i]) << packetBuilder;
		snapList->count += 1;
		snapList->snaps[i] = it->second();
	}
	return snapList;
}
