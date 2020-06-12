#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotMoverCorr : public Snapshot
		{
			fe::util::Vector3D<float>	pos{ 0, 0, 0 };
			fe::util::Vector3D<float>	delta{ 0, 0, 0 };

			fe::type::_32uint state = 0;
			fe::type::_32uint flag = 0;
			fe::type::_32uint motion = 0;
			fe::type::_32uint motionExtend = 0;
			fe::type::_32int loop = 0;
			fe::type::_32uint motionOption = 0;
			fe::type::_int tick = 0;

			SnapshotMoverCorr() = default;
			~SnapshotMoverCorr() = default;
			inline SnapshotMoverCorr& operator<<(fe::PacketBuilder& pb) override
			{
				pos.x = pb.read<float>();
				pos.y = pb.read<float>();
				pos.z = pb.read<float>();

				delta.x = pb.read<float>();
				delta.y = pb.read<float>();
				delta.z = pb.read<float>();

				fe::type::_32uint state = pb.read<fe::type::_32uint>();
				fe::type::_32uint flag = pb.read<fe::type::_32uint>();
				fe::type::_32uint motion = pb.read<fe::type::_32uint>();
				fe::type::_32uint motionExtend = pb.read<fe::type::_32uint>();
				fe::type::_32int loop = pb.read<fe::type::_32int>();
				fe::type::_32uint motionOption = pb.read<fe::type::_32uint>();
				fe::type::_int tick = pb.read<fe::type::_32uint>();

				return *this;
			}
		};
	}
}