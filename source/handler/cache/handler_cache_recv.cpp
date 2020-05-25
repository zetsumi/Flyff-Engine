#include <pch_fnetwork.h>

fe::PacketMessage* fe::HandlerCache::onSnapShot(fe::type::_SOCKET id)
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
		{
			FE_CONSOLELOG("snapshotType{%#04x} unknow", snapshotType);
			break;
		}
		return it->second(id, objid);
	}
	return nullptr;
}
