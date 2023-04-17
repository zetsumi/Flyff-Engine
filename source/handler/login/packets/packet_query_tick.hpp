#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketQueryTick : public PacketMessage
		{
			std::int32_t timer = 0;
			std::int64_t tick = 0;

			PacketQueryTick() = default;
			~PacketQueryTick() = default;
			PacketQueryTick& operator<<(fe::PacketBuilder& pb) override
			{
				timer = pb.read<std::uint32_t>();
				tick = pb.read<std::int64_t>();

				FE_CONSOLELOG("TIME local[%u] server[%d]", timer, tick);
				return *this;
			}

		};
	}
}