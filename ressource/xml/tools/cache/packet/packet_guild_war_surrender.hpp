namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildWarSurrender final : public fe::PacketMessage
		{
			fe::type::_32uint idWar = 0;
			char* playerName = nullptr;
			fe::type::_32int isGuildDeclared = 0;

			GuildWarSurrender() = default;
			~GuildWarSurrender() = default;
			GuildWarSurrender(GuildWarSurrender const&) = delete;
			GuildWarSurrender(GuildWarSurrender&&) = delete;

			GuildWarSurrender& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idWar;
				playerName = pb.readString();
				pb >> isGuildDeclared;
				return *this;
			}

			GuildWarSurrender& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idWar);
				pb.writeString(playerName);
				pb.write<fe::type::_32int>(isGuildDeclared);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
