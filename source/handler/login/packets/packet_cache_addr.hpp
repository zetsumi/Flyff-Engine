#pragma once

namespace fe
{
	namespace packet
	{
		struct PacketCacheAddr : public PacketMessage
		{
			char* cacheServerAddr = nullptr;

			PacketCacheAddr() = default;
			~PacketCacheAddr() = default;
			PacketCacheAddr& operator<<(fe::PacketBuilder& pb)
			{
				cacheServerAddr = const_cast<char*>(pb.readString());
				FE_CONSOLELOG("cacheServerAddr:{%s}", cacheServerAddr);
				return *this;
			}

			void	release() override final
			{
				delete cacheServerAddr;
				cacheServerAddr = nullptr;
			}
		};
	}
}