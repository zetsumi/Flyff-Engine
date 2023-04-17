namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC RemoveGuildMember final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			fe::type::_32uint idGuild = 0;

			RemoveGuildMember() = default;
			~RemoveGuildMember() = default;
			RemoveGuildMember(RemoveGuildMember const&) = delete;
			RemoveGuildMember(RemoveGuildMember&&) = delete;

			RemoveGuildMember& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				pb >> idGuild;
				return *this;
			}

			RemoveGuildMember& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.write<fe::type::_32uint>(idGuild);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
