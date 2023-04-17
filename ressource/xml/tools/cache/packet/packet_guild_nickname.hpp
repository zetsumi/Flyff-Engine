namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildNickname final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			char* nickname = nullptr;

			GuildNickname() = default;
			~GuildNickname() = default;
			GuildNickname(GuildNickname const&) = delete;
			GuildNickname(GuildNickname&&) = delete;

			GuildNickname& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				nickname = pb.readString();
				return *this;
			}

			GuildNickname& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.writeString(nickname);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
