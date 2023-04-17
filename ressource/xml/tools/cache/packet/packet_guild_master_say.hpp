namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildMastersay final : public fe::PacketMessage
		{
			char* playerFrom = nullptr;
			char* playerTo = nullptr;
			char* message = nullptr;

			GuildMastersay() = default;
			~GuildMastersay() = default;
			GuildMastersay(GuildMastersay const&) = delete;
			GuildMastersay(GuildMastersay&&) = delete;

			GuildMastersay& operator<<(fe::PacketBuilder& pb) override final
			{
				playerFrom = pb.readString();
				playerTo = pb.readString();
				message = pb.readString();
				return *this;
			}

			GuildMastersay& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.writeString(playerFrom);
				pb.writeString(playerTo);
				pb.writeString(message);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
