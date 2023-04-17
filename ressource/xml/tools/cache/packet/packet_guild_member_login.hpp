namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildMemberLogin final : public fe::PacketMessage
		{
			fe::type::_uchar login = 0;
			fe::type::_32uint playerId = 0;
			fe::type::_32uint multiNo = 0;

			GuildMemberLogin() = default;
			~GuildMemberLogin() = default;
			GuildMemberLogin(GuildMemberLogin const&) = delete;
			GuildMemberLogin(GuildMemberLogin&&) = delete;

			GuildMemberLogin& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> login;
				pb >> playerId;
				pb >> multiNo;
				return *this;
			}

			GuildMemberLogin& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_uchar>(login);
				pb.write<fe::type::_32uint>(playerId);
				pb.write<fe::type::_32uint>(multiNo);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
