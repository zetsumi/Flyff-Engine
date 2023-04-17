namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendLogout final : public fe::PacketMessage
		{
			fe::type::_32uint idFriend = 0;

			FriendLogout() = default;
			~FriendLogout() = default;
			FriendLogout(FriendLogout const&) = delete;
			FriendLogout(FriendLogout&&) = delete;

			FriendLogout& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idFriend;
				return *this;
			}

			FriendLogout& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idFriend);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
