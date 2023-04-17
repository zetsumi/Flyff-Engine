namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC DefinedText final : public fe::PacketMessage
		{
			fe::type::_32uint textId = 0;
			char* textMessage = nullptr;

			DefinedText() = default;
			~DefinedText() = default;
			DefinedText(DefinedText const&) = delete;
			DefinedText(DefinedText&&) = delete;

			DefinedText& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> textId;
				textMessage = pb.readString();
				return *this;
			}

			DefinedText& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(textId);
				pb.writeString(textMessage);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
