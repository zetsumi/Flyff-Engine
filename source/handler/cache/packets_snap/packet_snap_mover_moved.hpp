#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotMoverMoved : public Snapshot
		{
			fe::util::Vector3D<float>	pos{0.f, 0.f, 0.f};
			fe::util::Vector3D<float>	delta{0.f, 0.f, 0.f};
			float angle = 0.f;
			std::uint32_t	state = 0;
			std::uint32_t	stateFlag = 0;
			std::uint32_t	motion = 0;
			std::int32_t	motionExtend = 0;
			std::int32_t	loop = 0;
			std::uint32_t	motionOption = 0;
			std::int64_t		tickCount = 0;


			SnapshotMoverMoved() = default;
			~SnapshotMoverMoved() = default;
			SnapshotMoverMoved& operator<<(fe::PacketBuilder& pb) override
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();
				delta.x = pb.read<float>();
				delta.y = pb.read<float>();
				delta.z = pb.read<float>();

				pb >> angle;
				pb >> state >> stateFlag >> motion;
				pb >> motionExtend >> loop;
				pb >> motionOption >> tickCount;

				return *this;
			}
		};
	}
}