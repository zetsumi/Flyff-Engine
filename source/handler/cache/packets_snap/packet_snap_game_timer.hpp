#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotGameTimer : public Snapshot
		{
			double	currentTime = 0;

			SnapshotGameTimer() = default;
			~SnapshotGameTimer() = default;
			SnapshotGameTimer& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> currentTime;
				return *this;
			}
		};
	}
}