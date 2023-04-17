namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC OneHourNotify final : public fe::PacketMessage
		{

			OneHourNotify() = default;
			~OneHourNotify() = default;
			OneHourNotify(OneHourNotify const&) = delete;
			OneHourNotify(OneHourNotify&&) = delete;

			OneHourNotify& operator<<(fe::PacketBuilder& pb) override final
			{
				return *this;
			}

			OneHourNotify& operator>>(fe::PacketBuilder& pb) override final
			{
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
