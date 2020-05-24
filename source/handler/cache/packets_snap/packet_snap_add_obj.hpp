#pragma once

namespace fe
{
	struct SnapshotAddObj : public PacketMessage
	{
		fe::type::_32uint typeObj = 0;
		fe::type::_32uint indexObj = 0;

		SnapshotAddObj() = default;
		~SnapshotAddObj() = default;
		SnapshotAddObj& operator<<(fe::PacketBuilder& pb)
		{
			fe::type::_32uint typeObj = pb.read<fe::type::_32uint>();
			fe::type::_32uint indexObj = pb.read<fe::type::_32uint>();
			FE_CONSOLELOG("typeObj{%u} indexObj{%u}", typeObj, indexObj);
			return *this;
		}
	};
}