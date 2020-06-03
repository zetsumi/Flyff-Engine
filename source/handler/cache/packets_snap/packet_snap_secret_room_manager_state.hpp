#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotSecretRoomManagerState : public Snapshot
		{
			fe::type::_32int	state = 0;
			fe::type::_32uint	time = 0;

			SnapshotSecretRoomManagerState() = default;
			~SnapshotSecretRoomManagerState() = default;
			inline SnapshotSecretRoomManagerState& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> state >> time;
				return *this;
			}
		};
	}
}