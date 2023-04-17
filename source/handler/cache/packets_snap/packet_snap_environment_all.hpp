#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotEnvironmentAll : public Snapshot
		{
			std::int32_t season = 0;

			SnapshotEnvironmentAll() = default;
			~SnapshotEnvironmentAll() = default;
			SnapshotEnvironmentAll& operator<<(fe::PacketBuilder& pb) override
			{
				season = pb.read<std::uint32_t>();
				FE_CONSOLELOG("season{%d}", season);
				return *this;
			}
		};
	}
}