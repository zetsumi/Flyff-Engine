#pragma once

#include <io/network/emit/packet_builder.hpp>
#include <handler/cache/serializer/serialize_mover.hpp>

namespace fe
{
    namespace snapshot
    {
        struct SnapshotAddObj : public Snapshot
        {
            uint32_t typeObj = 0;
            uint32_t indexObj = 0;
            fe::serialize::SerializeMover mover{};

            SnapshotAddObj() = default;
            ~SnapshotAddObj() = default;
            SnapshotAddObj& operator<<(fe::PacketBuilder& pb) override
            {
                uint32_t typeObj = pb.read<uint32_t>();
                uint32_t indexObj = pb.read<uint32_t>();
                FE_CONSOLELOG("typeObj{%u} indexObj{%u}", typeObj, indexObj);

                mover << pb;
                return *this;
            }
        };
    }
}