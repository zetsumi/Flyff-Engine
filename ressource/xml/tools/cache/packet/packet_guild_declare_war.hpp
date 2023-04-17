namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildDeclareWar final : public fe::PacketMessage
		{
			fe::type::_32uint idGuildDeclared = 0;
			char* guildMasterName = nullptr;

			GuildDeclareWar() = default;
			~GuildDeclareWar() = default;
			GuildDeclareWar(GuildDeclareWar const&) = delete;
			GuildDeclareWar(GuildDeclareWar&&) = delete;

			GuildDeclareWar& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idGuildDeclared;
				guildMasterName = pb.readString();
				return *this;
			}

			GuildDeclareWar& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idGuildDeclared);
				pb.writeString(guildMasterName);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
