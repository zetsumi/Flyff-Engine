namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GameRate final : public fe::PacketMessage
		{
			float rate = 0;
			fe::type::_uchar flag = 0;

			GameRate() = default;
			~GameRate() = default;
			GameRate(GameRate const&) = delete;
			GameRate(GameRate&&) = delete;

			GameRate& operator<<(fe::PacketBuilder& pb) override final
			{
				rate = pb.read<float>();
				pb >> flag;
				return *this;
			}

			GameRate& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<float>(rate);
				pb.write<fe::type::_uchar>(flag);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
