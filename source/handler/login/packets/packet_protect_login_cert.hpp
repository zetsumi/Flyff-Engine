#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketProtectLoginCert : public PacketMessage
		{
			uint32_t logged = 0;
			uint32_t idNumPad = 0;

			PacketProtectLoginCert() = default;
			~PacketProtectLoginCert() = default;
			PacketProtectLoginCert& operator<<(fe::PacketBuilder& pb) override
			{
				logged = pb.read<uint32_t>();
				idNumPad = pb.read<uint32_t>();
				FE_CONSOLELOG("logged:{%u} idNumPad:{%u}", logged, idNumPad);
				return *this;
			}
		};
	}
}