namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildSetName final : public fe::PacketMessage
		{
			fe::type::_32uint idGuild = 0;
			char* name = nullptr;

			GuildSetName() = default;
			~GuildSetName() = default;
			GuildSetName(GuildSetName const&) = delete;
			GuildSetName(GuildSetName&&) = delete;

			GuildSetName& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idGuild;
				name = pb.readString();
				return *this;
			}

			GuildSetName& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idGuild);
				pb.writeString(name);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
