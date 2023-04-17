namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendIntercept final : public fe::PacketMessage
		{
			fe::type::_32uint idPlayer = 0;
			fe::type::_32uint idFriend = 0;

			FriendIntercept() = default;
			~FriendIntercept() = default;
			FriendIntercept(FriendIntercept const&) = delete;
			FriendIntercept(FriendIntercept&&) = delete;

			FriendIntercept& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idPlayer;
				pb >> idFriend;
				return *this;
			}

			FriendIntercept& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idPlayer);
				pb.write<fe::type::_32uint>(idFriend);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
