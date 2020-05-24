#pragma once

namespace fe
{
	struct PacketQueryTick : public PacketMessage
	{
		fe::type::_32int timer = 0;
		fe::type::_int tick = 0;

		PacketQueryTick() = default;
		~PacketQueryTick() = default;
		PacketQueryTick& operator<<(fe::PacketBuilder& pb)
		{
			timer = pb.read<fe::type::_32uint>();
			tick = pb.read<fe::type::_int>();

			FE_CONSOLELOG("TIME local[%u] server[%d]", timer, tick);
			return *this;
		}
	};
}