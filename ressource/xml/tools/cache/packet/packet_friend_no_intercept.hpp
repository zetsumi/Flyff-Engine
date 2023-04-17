namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendNoIntercept final : public fe::PacketMessage
		{
			fe::type::_32uint idFriend = 0;

			FriendNoIntercept() = default;
			~FriendNoIntercept() = default;
			FriendNoIntercept(FriendNoIntercept const&) = delete;
			FriendNoIntercept(FriendNoIntercept&&) = delete;

			FriendNoIntercept& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idFriend;
				return *this;
			}

			FriendNoIntercept& operator>>(fe::PacketBuilder& pb) override final
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
