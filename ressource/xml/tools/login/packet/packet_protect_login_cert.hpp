namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC ProtectLoginCert final : public fe::PacketMessage
		{
			fe::type::_32uint logged = 0;
			fe::type::_32uint idNumPad = 0;

			ProtectLoginCert() = default;
			~ProtectLoginCert() = default;
			ProtectLoginCert(ProtectLoginCert const&) = delete;
			ProtectLoginCert(ProtectLoginCert&&) = delete;

			ProtectLoginCert& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> logged;
				pb >> idNumPad;
				return *this;
			}

			ProtectLoginCert& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(logged);
				pb.write<fe::type::_32uint>(idNumPad);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
