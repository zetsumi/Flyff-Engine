#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketGetPlayerCount : public fe::PacketMessage
		{
			fe::type::_ushort	count = 0;

			PacketGetPlayerCount() = default;
			~PacketGetPlayerCount() = default;
			PacketGetPlayerCount(const PacketGetPlayerAddr&) = delete;
			PacketGetPlayerCount(PacketGetPlayerAddr&&) = delete;

			PacketGetPlayerCount& operator<<(fe::PacketBuilder& pb)
			{
				pb >> count;
				return *this;
			}
		};
#pragma warning( default : 4251 )
	}
}
