#pragma once

namespace fe
{
	struct SnapshotDestPos : public PacketMessage
	{
		fe::Vector3D<float>		pos{0,0,0};
		fe::type::_uchar	forward = 0;

		SnapshotDestPos() = default;
		~SnapshotDestPos() = default;
		SnapshotDestPos& operator<<(fe::PacketBuilder& pb)
		{
			pos.x = pb.read<float>();
			pos.y = pb.read<float>();
			pos.z = pb.read<float>();
			forward = pb.read<fe::type::_uchar>();
			return *this;
		}
	};
}