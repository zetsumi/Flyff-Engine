#pragma once

namespace fe
{
	struct PacketProtectNumPad : public PacketMessage
	{
		fe::type::_32uint idNumPad = 0;

		PacketProtectNumPad() = default;
		~PacketProtectNumPad() = default;
		inline PacketProtectNumPad& operator<<(fe::PacketBuilder& pb) override
		{
			idNumPad = pb.read<fe::type::_32uint>();
			FE_CONSOLELOG("idNumPad {%u}", idNumPad);
			return *this;
		}
	};
}