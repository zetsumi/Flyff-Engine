#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotDestPos : public Snapshot
		{
			fe::util::Vector3D<float>	pos{ 0, 0, 0 };
			std::uint8_t	forward = 0;

			SnapshotDestPos() = default;
			~SnapshotDestPos() = default;
			SnapshotDestPos& operator<<(fe::PacketBuilder& pb) override
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();
				forward = pb.read<std::uint8_t>();
				return *this;
			}
		};
	}
}