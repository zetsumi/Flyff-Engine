namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC GetCorePlayer final : public fe::PacketMessage
		{
			fe::type::_uchar playersName_count = 0;
			char** playersName = nullptr;

			GetCorePlayer() = default;
			~GetCorePlayer() = default;
			GetCorePlayer(GetCorePlayer const&) = delete;
			GetCorePlayer(GetCorePlayer&&) = delete;

			GetCorePlayer& operator<<(fe::PacketBuilder& pb) override final
			{
				pb >> playersName_count;
				playersName = new char*[playersName_count]();
				for (fe::type::_u32int i = 0; i <playersName_count; ++i)
					playersName[i] = const_cast<char*>(pb.readString());
				return *this;
			}

			GetCorePlayer& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.write<fe::type::_uchar>(playersName_count);
				playersName = new char* [playersName_count]();
				for (std::uint32_t i = 0; i <playersName_count; ++i)
					pb.writeString(playersName[i])
				return *this;
			}

			void release() override final
			{
			}
		};
	}
}
