#pragma once

namespace fe
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
	};
}