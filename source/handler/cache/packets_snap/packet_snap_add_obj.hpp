#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotAddObj : public Snapshot
		{
			fe::type::_32uint typeObj = 0;
			fe::type::_32uint indexObj = 0;

			SnapshotAddObj() = default;
			~SnapshotAddObj() = default;
			inline SnapshotAddObj& operator<<(fe::PacketBuilder& pb) override
			{
				fe::type::_32uint typeObj = pb.read<fe::type::_32uint>();
				fe::type::_32uint indexObj = pb.read<fe::type::_32uint>();
				FE_CONSOLELOG("typeObj{%u} indexObj{%u}", typeObj, indexObj);
				return *this;
			}
		};
	}
}