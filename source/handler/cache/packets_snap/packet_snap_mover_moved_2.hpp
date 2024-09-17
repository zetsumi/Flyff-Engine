#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotMoverMoved2 : public Snapshot
		{
			fe::util::Vector3D<float>	pos{ 0.f, 0.f, 0.f };
			fe::util::Vector3D<float>	delta{ 0.f, 0.f, 0.f };
			float angle = 0.f;
			float angleX = 0.f;
			float accPower = 0.f;
			float turnAngle = 0.f;
			uint32_t	state = 0;
			uint32_t	stateFlag = 0;
			uint32_t	motion = 0;
			int32_t	motionExtend = 0;
			int32_t	loop = 0;
			uint32_t	motionOption = 0;
			int64_t		tickCount = 0;
			uint8_t	frame = 0;


			SnapshotMoverMoved2() = default;
			~SnapshotMoverMoved2() = default;
			SnapshotMoverMoved2& operator<<(fe::PacketBuilder& pb) override
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();
				delta.x = pb.read<float>();
				delta.y = pb.read<float>();
				delta.z = pb.read<float>();

				pb >> angle >> angleX >> accPower >> turnAngle;
				pb >> state >> stateFlag >> motion;
				pb >> motionExtend >> loop;
				pb >> motionOption >> tickCount;
				pb >> frame;

				return *this;
			}
		};
	}
}