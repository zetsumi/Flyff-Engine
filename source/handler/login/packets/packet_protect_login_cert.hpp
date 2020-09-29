#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketProtectLoginCert : public PacketMessage
		{
			fe::type::_32uint logged = 0;
			fe::type::_32uint idNumPad = 0;

			PacketProtectLoginCert() = default;
			~PacketProtectLoginCert() = default;
			PacketProtectLoginCert& operator<<(fe::PacketBuilder& pb) override
			{
				logged = pb.read<fe::type::_32uint>();
				idNumPad = pb.read<fe::type::_32uint>();
				FE_CONSOLELOG("logged:{%u} idNumPad:{%u}", logged, idNumPad);
				return *this;
			}
		};
	}
}