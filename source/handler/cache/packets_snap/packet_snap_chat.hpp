#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotChat : public Snapshot
		{
			const char* message = nullptr;

			SnapshotChat() = default;
			~SnapshotChat() = default;
			SnapshotChat& operator<<(fe::PacketBuilder& pb) override
			{
				message = pb.readString();
				return *this;
			}
		};
	}
}