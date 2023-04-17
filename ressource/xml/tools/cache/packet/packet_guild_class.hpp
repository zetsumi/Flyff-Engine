namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildClass final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			fe::type::_32int guildClass = 0;

			GuildClass() = default;
			~GuildClass() = default;
			GuildClass(GuildClass const&) = delete;
			GuildClass(GuildClass&&) = delete;

			GuildClass& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				pb >> guildClass;
				return *this;
			}

			GuildClass& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.write<fe::type::_32int>(guildClass);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
