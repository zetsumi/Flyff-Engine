#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotMoverCorr : public Snapshot
		{
			fe::util::Vector3D<float>	pos{ 0, 0, 0 };
			fe::util::Vector3D<float>	delta{ 0, 0, 0 };

			std::uint32_t state = 0;
			std::uint32_t flag = 0;
			std::uint32_t motion = 0;
			std::uint32_t motionExtend = 0;
			std::int32_t loop = 0;
			std::uint32_t motionOption = 0;
			std::int64_t tick = 0;

			SnapshotMoverCorr() = default;
			~SnapshotMoverCorr() = default;
			SnapshotMoverCorr& operator<<(fe::PacketBuilder& pb) override
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();

				delta.x = pb.read<float>();
				delta.y = pb.read<float>();
				delta.z = pb.read<float>();

				std::uint32_t state = pb.read<std::uint32_t>();
				std::uint32_t flag = pb.read<std::uint32_t>();
				std::uint32_t motion = pb.read<std::uint32_t>();
				std::uint32_t motionExtend = pb.read<std::uint32_t>();
				std::int32_t loop = pb.read<std::int32_t>();
				std::uint32_t motionOption = pb.read<std::uint32_t>();
				std::int64_t tick = pb.read<std::uint32_t>();

				return *this;
			}
		};
	}
}