namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC Block final : public fe::PacketMessage
		{
			fe::type::_uchar gu = 0;
			char* name = nullptr;

			Block() = default;
			~Block() = default;
			Block(Block const&) = delete;
			Block(Block&&) = delete;

			Block& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> gu;
				name = pb.readString();
				return *this;
			}

			Block& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_uchar>(gu);
				pb.writeString(name);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
