namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC ProtectNumPad final : public fe::PacketMessage
		{
			fe::type::_32uint idNumPad = 0;

			ProtectNumPad() = default;
			~ProtectNumPad() = default;
			ProtectNumPad(ProtectNumPad const&) = delete;
			ProtectNumPad(ProtectNumPad&&) = delete;

			ProtectNumPad& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idNumPad;
				return *this;
			}

			ProtectNumPad& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idNumPad);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
