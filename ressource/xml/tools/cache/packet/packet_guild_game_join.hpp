namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildGameJoin final : public fe::PacketMessage
		{
			fe::type::_32int maxLoginGuild = 0;
			char* loginPlayerIdGuild = nullptr;
			char* loginGuildMulti = nullptr;

			GuildGameJoin() = default;
			~GuildGameJoin() = default;
			GuildGameJoin(GuildGameJoin const&) = delete;
			GuildGameJoin(GuildGameJoin&&) = delete;

			GuildGameJoin& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> maxLoginGuild;
				loginPlayerIdGuild = pb.readString();
				loginGuildMulti = pb.readString();
				return *this;
			}

			GuildGameJoin& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32int>(maxLoginGuild);
				pb.writeString(loginPlayerIdGuild);
				pb.writeString(loginGuildMulti);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
