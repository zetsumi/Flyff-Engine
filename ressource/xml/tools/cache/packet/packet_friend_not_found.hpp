namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendNotFound final : public fe::PacketMessage
		{
			char* name = nullptr;

			FriendNotFound() = default;
			~FriendNotFound() = default;
			FriendNotFound(FriendNotFound const&) = delete;
			FriendNotFound(FriendNotFound&&) = delete;

			FriendNotFound& operator<<(fe::PacketBuilder& pb) override final
			{
				name = pb.readString();
				return *this;
			}

			FriendNotFound& operator>>(fe::PacketBuilder& pb) override final
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
