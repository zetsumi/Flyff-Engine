namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC Snoop final : public fe::PacketMessage
		{
			char* message = nullptr;

			Snoop() = default;
			~Snoop() = default;
			Snoop(Snoop const&) = delete;
			Snoop(Snoop&&) = delete;

			Snoop& operator<<(fe::PacketBuilder& pb) override final
			{
				message = pb.readString();
				return *this;
			}

			Snoop& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.writeString(message);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
