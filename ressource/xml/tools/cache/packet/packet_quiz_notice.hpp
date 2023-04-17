namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC QuizNotice final : public fe::PacketMessage
		{
			fe::type::_32int definedTextId = 0;
			fe::type::_int all = 0;
			fe::type::_32int channel = 0;
			fe::type::_32int time = 0;

			QuizNotice() = default;
			~QuizNotice() = default;
			QuizNotice(QuizNotice const&) = delete;
			QuizNotice(QuizNotice&&) = delete;

			QuizNotice& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> definedTextId;
				pb >> all;
				pb >> channel;
				pb >> time;
				return *this;
			}

			QuizNotice& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32int>(definedTextId);
				pb.write<fe::type::_int>(all);
				pb.write<fe::type::_32int>(channel);
				pb.write<fe::type::_32int>(time);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
