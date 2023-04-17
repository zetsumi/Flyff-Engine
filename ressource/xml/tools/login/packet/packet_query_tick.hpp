namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC QueryTick final : public fe::PacketMessage
		{
			fe::type::_32int timer = 0;
			fe::type::_int tick = 0;

			QueryTick() = default;
			~QueryTick() = default;
			QueryTick(QueryTick const&) = delete;
			QueryTick(QueryTick&&) = delete;

			QueryTick& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> timer;
				pb >> tick;
				return *this;
			}

			QueryTick& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32int>(timer);
				pb.write<fe::type::_int>(tick);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
