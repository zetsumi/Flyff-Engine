namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC UpdatePlayerData final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			char* name = nullptr;

			UpdatePlayerData() = default;
			~UpdatePlayerData() = default;
			UpdatePlayerData(UpdatePlayerData const&) = delete;
			UpdatePlayerData(UpdatePlayerData&&) = delete;

			UpdatePlayerData& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				name = pb.readString();
				return *this;
			}

			UpdatePlayerData& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.writeString(name);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
