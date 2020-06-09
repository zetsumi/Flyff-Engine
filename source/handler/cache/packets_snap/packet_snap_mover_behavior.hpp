#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotMoverBehavior : public Snapshot
		{
			fe::Vector3D<float>	pos{ 0.f, 0.f, 0.f };
			fe::Vector3D<float>	delta{ 0.f, 0.f, 0.f };
			float angle = 0.f;
			fe::type::_32uint	state = 0;
			fe::type::_32uint	stateFlag = 0;
			fe::type::_32uint	motion = 0;
			fe::type::_32int	motionExtend = 0;
			fe::type::_32int	loop = 0;
			fe::type::_32uint	motionOption = 0;
			fe::type::_int		tickCount = 0;

			SnapshotMoverBehavior() = default;
			~SnapshotMoverBehavior() = default;
			inline SnapshotMoverBehavior& operator<<(fe::PacketBuilder& pb) override
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