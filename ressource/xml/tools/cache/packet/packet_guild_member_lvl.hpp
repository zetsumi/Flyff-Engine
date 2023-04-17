namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildMemberLvl final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			fe::type::_32int memberLevel = 0;

			GuildMemberLvl() = default;
			~GuildMemberLvl() = default;
			GuildMemberLvl(GuildMemberLvl const&) = delete;
			GuildMemberLvl(GuildMemberLvl&&) = delete;

			GuildMemberLvl& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				pb >> memberLevel;
				return *this;
			}

			GuildMemberLvl& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.write<fe::type::_32int>(memberLevel);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
