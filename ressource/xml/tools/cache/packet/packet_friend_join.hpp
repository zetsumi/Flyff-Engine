namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendJoin final : public fe::PacketMessage
		{
			fe::type::_32uint idFriend = 0;
			fe::type::_32uint state = 0;
			fe::type::_32uint login = 0;

			FriendJoin() = default;
			~FriendJoin() = default;
			FriendJoin(FriendJoin const&) = delete;
			FriendJoin(FriendJoin&&) = delete;

			FriendJoin& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> idFriend;
				pb >> state;
				pb >> login;
				return *this;
			}

			FriendJoin& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(idFriend);
				pb.write<fe::type::_32uint>(state);
				pb.write<fe::type::_32uint>(login);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
