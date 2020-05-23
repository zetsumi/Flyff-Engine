#pragma once

namespace fe
{
	struct PacketProtectLoginCert : public PacketMessage
	{
		fe::type::_32uint logged = 0;
		fe::type::_32uint idNumPad = 0;

		PacketProtectLoginCert() = default;
		~PacketProtectLoginCert() = default;
		PacketProtectLoginCert& operator<<(fe::PacketBuilder& pb)
		{
			logged = pb.read<fe::type::_32uint>();
			idNumPad = pb.read<fe::type::_32uint>();
			FE_CONSOLELOG("logged:{%u} idNumPad:{%u}", logged, idNumPad);
			return *this;
		}
	};
}