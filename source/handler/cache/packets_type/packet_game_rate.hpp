#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketGameRate : public fe::PacketMessage
		{
			float				rate = 0.f;
			uint8_t	flag = 0;

			PacketGameRate() = default;
			~PacketGameRate() = default;
			PacketGameRate(const PacketGameRate&) = delete;
			PacketGameRate(PacketGameRate&&) = delete;

			PacketGameRate& operator<<(fe::PacketBuilder& pb)
			{
				pb >> rate >> flag;
				return *this;
			}
		};
#pragma warning( default : 4251 )
	}
}
