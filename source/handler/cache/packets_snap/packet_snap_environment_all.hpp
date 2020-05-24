#pragma once

namespace fe
{
	struct SnapshotEnvironmentAll : public PacketMessage
	{
		fe::type::_32int season = 0;

		SnapshotEnvironmentAll() = default;
		~SnapshotEnvironmentAll() = default;
		SnapshotEnvironmentAll& operator<<(fe::PacketBuilder& pb)
		{
			season = pb.read<fe::type::_32uint>();
			FE_CONSOLELOG("season{%d}", season);
			return *this;
		}
	};
}