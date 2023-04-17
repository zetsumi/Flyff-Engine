namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GetClock final : public fe::PacketMessage
		{
			fe::type::_uchar clockOfClient = 0;

			GetClock() = default;
			~GetClock() = default;
			GetClock(GetClock const&) = delete;
			GetClock(GetClock&&) = delete;

			GetClock& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> clockOfClient;
				return *this;
			}

			GetClock& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_uchar>(clockOfClient);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
