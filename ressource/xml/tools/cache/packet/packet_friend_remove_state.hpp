namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendRemoveState final : public fe::PacketMessage
		{
			fe::type::_32uint name = 0;

			FriendRemoveState() = default;
			~FriendRemoveState() = default;
			FriendRemoveState(FriendRemoveState const&) = delete;
			FriendRemoveState(FriendRemoveState&&) = delete;

			FriendRemoveState& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> name;
				return *this;
			}

			FriendRemoveState& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(name);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
