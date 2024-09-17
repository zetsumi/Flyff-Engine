#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketProtectNumPad : public PacketMessage
		{
			uint32_t idNumPad = 0;

			PacketProtectNumPad() = default;
			~PacketProtectNumPad() = default;
			PacketProtectNumPad& operator<<(fe::PacketBuilder& pb) override
			{
				idNumPad = pb.read<uint32_t>();
				FE_CONSOLELOG("idNumPad {%u}", idNumPad);
				return *this;
			}
		};
	}
}