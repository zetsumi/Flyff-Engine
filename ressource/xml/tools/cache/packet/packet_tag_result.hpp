namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC TagResult final : public fe::PacketMessage
		{
			fe::type::_uchar result = 0;

			TagResult() = default;
			~TagResult() = default;
			TagResult(TagResult const&) = delete;
			TagResult(TagResult&&) = delete;

			TagResult& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> result;
				return *this;
			}

			TagResult& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_uchar>(result);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
