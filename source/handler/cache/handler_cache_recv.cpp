#include <pch_fnetwork.h>

fe::PacketMessage* fe::HandlerCache::onSnapShot(void)
{
	fe::type::_32uint objIdPlayer = packetBuilder.read<fe::type::_32uint>();
	short count = packetBuilder.read<short>();

	fe::type::_32uint objid = 0;
	FE_CONSOLELOG("objIdPlayer{%#010x}{%u} count{%u}", objIdPlayer, objIdPlayer, count);

	// Initialise le tableau de snapshot
	snapshot::SnapshotList* snapList = new snapshot::SnapshotList();
	snapList->snaps = new snapshot::Snapshot*[count]();
	for (unsigned short i = 0; i < count; ++i)
		snapList->snaps[i] = nullptr;

	unsigned short snapshotType = 0;
	for (unsigned short i = 0; i < count; ++i)
	{
		objid = packetBuilder.read<fe::type::_32uint>();
		snapshotType = packetBuilder.read<unsigned short>();

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
