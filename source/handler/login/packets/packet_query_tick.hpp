#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketQueryTick : public PacketMessage
		{
			int32_t timer = 0;
			int64_t tick = 0;

			PacketQueryTick() = default;
			~PacketQueryTick() = default;
			PacketQueryTick& operator<<(fe::PacketBuilder& pb) override
			{
				timer = pb.read<uint32_t>();
				tick = pb.read<int64_t>();

				FE_CONSOLELOG("TIME local[%u] server[%d]", timer, tick);
				return *this;
			}

		};
	}
}