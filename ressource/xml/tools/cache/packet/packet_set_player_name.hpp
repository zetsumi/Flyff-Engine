namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC SetPlayerName final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			char* name = nullptr;

			SetPlayerName() = default;
			~SetPlayerName() = default;
			SetPlayerName(SetPlayerName const&) = delete;
			SetPlayerName(SetPlayerName&&) = delete;

			SetPlayerName& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				name = pb.readString();
				return *this;
			}

			SetPlayerName& operator>>(fe::PacketBuilder& pb) override final
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
