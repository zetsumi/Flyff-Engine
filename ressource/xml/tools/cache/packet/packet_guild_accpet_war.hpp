namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildAcceptWar final : public fe::PacketMessage
		{
			fe::type::_32uint idWar = 0;
			fe::type::_32uint idGuildDeclared = 0;
			fe::type::_32uint idGuildAccpted = 0;

			GuildAcceptWar() = default;
			~GuildAcceptWar() = default;
			GuildAcceptWar(GuildAcceptWar const&) = delete;
			GuildAcceptWar(GuildAcceptWar&&) = delete;

			GuildAcceptWar& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idWar;
				pb >> idGuildDeclared;
				pb >> idGuildAccpted;
				return *this;
			}

			GuildAcceptWar& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idWar);
				pb.write<fe::type::_32uint>(idGuildDeclared);
				pb.write<fe::type::_32uint>(idGuildAccpted);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
