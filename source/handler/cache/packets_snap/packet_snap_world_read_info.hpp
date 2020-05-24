#pragma once

namespace fe
{
	struct SnapshotWorldReadInfo : public PacketMessage
	{
		fe::type::_32uint idWorld = 0;
		fe::Vector3D<float> pos{ 0, 0, 0 };

		SnapshotWorldReadInfo() = default;
		~SnapshotWorldReadInfo() = default;
		SnapshotWorldReadInfo& operator<<(fe::PacketBuilder& pb)
		{
			idWorld = pb.read<fe::type::_32uint>();
			pos.x = pb.read<float>();
			pos.y = pb.read<float>();
			pos.z = pb.read<float>();

			FE_CONSOLELOG("idWorld{%d}", idWorld);
			FE_CONSOLELOG("pos(%f, %f, %f)", pos.x, pos.y, pos.z);
			return *this;
		}
	};
}