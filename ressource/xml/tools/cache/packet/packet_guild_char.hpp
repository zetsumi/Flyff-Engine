namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildCHat final : public fe::PacketMessage
		{
			fe::type::_32uint objid = 0;
			char* playerName = nullptr;
			char* message = nullptr;

			GuildCHat() = default;
			~GuildCHat() = default;
			GuildCHat(GuildCHat const&) = delete;
			GuildCHat(GuildCHat&&) = delete;

			GuildCHat& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> objid;
				playerName = pb.readString();
				message = pb.readString();
				return *this;
			}

			GuildCHat& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(objid);
				pb.writeString(playerName);
				pb.writeString(message);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
