namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC AddGuildMember final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			fe::type::_uchar multiNo = 0;
			fe::type::_32uint idGuild = 0;
			char* playerName = nullptr;

			AddGuildMember() = default;
			~AddGuildMember() = default;
			AddGuildMember(AddGuildMember const&) = delete;
			AddGuildMember(AddGuildMember&&) = delete;

			AddGuildMember& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				pb >> multiNo;
				pb >> idGuild;
				playerName = pb.readString();
				return *this;
			}

			AddGuildMember& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.write<fe::type::_uchar>(multiNo);
				pb.write<fe::type::_32uint>(idGuild);
				pb.writeString(playerName);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
