#pragma once

namespace fe
{
    namespace snapshot
    {
        struct SnapshotEnvironmentAll : public Snapshot
        {
            int32_t season = 0;

            SnapshotEnvironmentAll() = default;
            ~SnapshotEnvironmentAll() = default;
            SnapshotEnvironmentAll& operator<<(fe::PacketBuilder& pb) override
            {
                season = pb.read<uint32_t>();
                FE_CONSOLELOG("season{%d}", season);
                return *this;
            }
        };
    }
}