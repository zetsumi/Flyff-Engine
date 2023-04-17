namespace fe
{
	namespace packet
	{
		struct API_DECLSPEC CacheAddr final : public fe::PacketMessage
		{
			char* cacheServerAddr = nullptr;

			CacheAddr() = default;
			~CacheAddr() = default;
			CacheAddr(CacheAddr const&) = delete;
			CacheAddr(CacheAddr&&) = delete;

			CacheAddr& operator<<(fe::PacketBuilder& pb) override final
			{
				cacheServerAddr = pb.readString();
				return *this;
			}

			CacheAddr& operator>>(fe::PacketBuilder& pb) override final
			{
				pb.writeString(cacheServerAddr);
				return *this;
			}

			void release() override final
			{
				delete cacheServerAddr;
				cacheServerAddr = nullptr;
			}
		};
	}
}
