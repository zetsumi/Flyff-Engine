#pragma once

#include <io/network/emit/packet_builder.hpp>
#include <handler/cache/serializer/serialize_mover.hpp>

namespace fe
{
	namespace snapshot
	{
		struct SnapshotAddObj : public Snapshot
		{
			fe::type::_32uint typeObj = 0;
			fe::type::_32uint indexObj = 0;

			fe::serialize::SerializeMover mover;

			SnapshotAddObj() = default;
			~SnapshotAddObj() = default;
			inline SnapshotAddObj& operator<<(fe::PacketBuilder& pb) override
			{
				fe::type::_32uint typeObj = pb.read<fe::type::_32uint>();
				fe::type::_32uint indexObj = pb.read<fe::type::_32uint>();
				FE_CONSOLELOG("typeObj{%u} indexObj{%u}", typeObj, indexObj);

				mover << pb;
				return *this;
			}
		};
	}
}