namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC WantedName final : public fe::PacketMessage
		{
			char* name = nullptr;

			WantedName() = default;
			~WantedName() = default;
			WantedName(WantedName const&) = delete;
			WantedName(WantedName&&) = delete;

			WantedName& operator<<(fe::PacketBuilder& pb) override final
			{
				name = pb.readString();
				return *this;
			}

			WantedName& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.writeString(name);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
