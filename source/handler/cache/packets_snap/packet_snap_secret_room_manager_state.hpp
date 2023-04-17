#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotSecretRoomManagerState : public Snapshot
		{
			std::int32_t	state = 0;
			std::int32_t	time = 0;

			SnapshotSecretRoomManagerState() = default;
			~SnapshotSecretRoomManagerState() = default;
			SnapshotSecretRoomManagerState& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> state >> time;
				return *this;
			}
		};
	}
}