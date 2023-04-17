namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GuildError final : public fe::PacketMessage
		{
			fe::type::_32int error = 0;

			GuildError() = default;
			~GuildError() = default;
			GuildError(GuildError const&) = delete;
			GuildError(GuildError&&) = delete;

			GuildError& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> error;
				return *this;
			}

			GuildError& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32int>(error);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
