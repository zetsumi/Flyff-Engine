#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotWorldReadInfo : public Snapshot
		{
			fe::type::_32uint idWorld = 0;
			fe::util::Vector3D<float> pos{ 0, 0, 0 };

			SnapshotWorldReadInfo() = default;
			~SnapshotWorldReadInfo() = default;
			SnapshotWorldReadInfo& operator<<(fe::PacketBuilder& pb) override
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
}