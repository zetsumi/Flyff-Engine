namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildChangeMaster final : public fe::PacketMessage
		{
			fe::type::_32uint oldPlayerMasterId = 0;
			fe::type::_32uint newPlayerMasterId = 0;

			GuildChangeMaster() = default;
			~GuildChangeMaster() = default;
			GuildChangeMaster(GuildChangeMaster const&) = delete;
			GuildChangeMaster(GuildChangeMaster&&) = delete;

			GuildChangeMaster& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> oldPlayerMasterId;
				pb >> newPlayerMasterId;
				return *this;
			}

			GuildChangeMaster& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(oldPlayerMasterId);
				pb.write<fe::type::_32uint>(newPlayerMasterId);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
