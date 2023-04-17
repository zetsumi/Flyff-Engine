namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC FriendNameRequest final : public fe::PacketMessage
		{
			fe::type::_32uint leader = 0;
			fe::type::_32uint member = 0;
			fe::type::_32int leaderJob = 0;
			fe::type::_uchar leaderSex = 0;
			char* leaderName = nullptr;

			FriendNameRequest() = default;
			~FriendNameRequest() = default;
			FriendNameRequest(FriendNameRequest const&) = delete;
			FriendNameRequest(FriendNameRequest&&) = delete;

			FriendNameRequest& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> leader;
				pb >> member;
				pb >> leaderJob;
				pb >> leaderSex;
				leaderName = pb.readString();
				return *this;
			}

			FriendNameRequest& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_32uint>(leader);
				pb.write<fe::type::_32uint>(member);
				pb.write<fe::type::_32int>(leaderJob);
				pb.write<fe::type::_uchar>(leaderSex);
				pb.writeString(leaderName);
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
