#pragma once

namespace fe
{
	struct SnapshotGetPosition : public PacketMessage
	{
		fe::Vector3D<float>		pos{0,0,0};
		float					angle = 0;

		SnapshotGetPosition() = default;
		~SnapshotGetPosition() = default;
		SnapshotGetPosition& operator<<(fe::PacketBuilder& pb)
		{
			pos.x = pb.read<float>();
			pos.y = pb.read<float>();
			pos.z = pb.read<float>();
			angle = pb.read<float>();
			return *this;
		}
	};
}