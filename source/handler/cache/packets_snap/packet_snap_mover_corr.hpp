#pragma once

namespace fe
{
    namespace snapshot
    {
        struct SnapshotMoverCorr : public Snapshot
        {
            fe::util::Vector3D<float>	pos{ 0, 0, 0 };
            fe::util::Vector3D<float>	delta{ 0, 0, 0 };

            uint32_t state = 0;
            uint32_t flag = 0;
            uint32_t motion = 0;
            uint32_t motionExtend = 0;
            int32_t loop = 0;
            uint32_t motionOption = 0;
            int64_t tick = 0;

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

                uint32_t state = pb.read<uint32_t>();
                uint32_t flag = pb.read<uint32_t>();
                uint32_t motion = pb.read<uint32_t>();
                uint32_t motionExtend = pb.read<uint32_t>();
                int32_t loop = pb.read<int32_t>();
                uint32_t motionOption = pb.read<uint32_t>();
                int64_t tick = pb.read<uint32_t>();

                return *this;
            }
        };
    }
}