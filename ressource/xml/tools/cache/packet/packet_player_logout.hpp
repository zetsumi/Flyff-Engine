namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC PlayerLogout final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;

			PlayerLogout() = default;
			~PlayerLogout() = default;
			PlayerLogout(PlayerLogout const&) = delete;
			PlayerLogout(PlayerLogout&&) = delete;

			PlayerLogout& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				return *this;
			}

			PlayerLogout& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
