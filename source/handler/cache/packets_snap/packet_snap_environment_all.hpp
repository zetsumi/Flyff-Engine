#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotEnvironmentAll : public Snapshot
		{
			fe::type::_32int season = 0;

			SnapshotEnvironmentAll() = default;
			~SnapshotEnvironmentAll() = default;
			inline SnapshotEnvironmentAll& operator<<(fe::PacketBuilder& pb) override
			{
				season = pb.read<fe::type::_32uint>();
				FE_CONSOLELOG("season{%d}", season);
				return *this;
			}
		};
	}
}