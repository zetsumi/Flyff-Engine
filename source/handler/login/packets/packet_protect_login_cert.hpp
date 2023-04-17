#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketProtectLoginCert : public PacketMessage
		{
			std::uint32_t logged = 0;
			std::uint32_t idNumPad = 0;

			PacketProtectLoginCert() = default;
			~PacketProtectLoginCert() = default;
			PacketProtectLoginCert& operator<<(fe::PacketBuilder& pb) override
			{
				logged = pb.read<std::uint32_t>();
				idNumPad = pb.read<std::uint32_t>();
				FE_CONSOLELOG("logged:{%u} idNumPad:{%u}", logged, idNumPad);
				return *this;
			}
		};
	}
}