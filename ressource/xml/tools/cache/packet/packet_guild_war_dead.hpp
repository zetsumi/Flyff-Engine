namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildWarDead final : public fe::PacketMessage
		{
			fe::type::_32uint idWar = 0;
			char* namePlayerDie = nullptr;
			int isFromGuildDeclared = 0;

			GuildWarDead() = default;
			~GuildWarDead() = default;
			GuildWarDead(GuildWarDead const&) = delete;
			GuildWarDead(GuildWarDead&&) = delete;

			GuildWarDead& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idWar;
				namePlayerDie = pb.readString();
				isFromGuildDeclared = pb.read<int>();
				return *this;
			}

			GuildWarDead& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idWar);
				pb.writeString(namePlayerDie);
				pb.write<int>(isFromGuildDeclared);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
