namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC Caption final : public fe::PacketMessage
		{
			fe::type::_32int smallCaption = 0;
			fe::type::_32uint worldId = 0;
			char* caption = nullptr;

			Caption() = default;
			~Caption() = default;
			Caption(Caption const&) = delete;
			Caption(Caption&&) = delete;

			Caption& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> smallCaption;
				pb >> worldId;
				caption = pb.readString();
				return *this;
			}

			Caption& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32int>(smallCaption);
				pb.write<fe::type::_32uint>(worldId);
				pb.writeString(caption);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
