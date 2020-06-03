#pragma once

namespace fe
{
	namespace packet
	{
#pragma warning( disable: 4251 )
		struct API_DECLSPEC PacketReplace : public fe::PacketMessage
		{

			fe::type::_32uint	worldId = 0;
			fe::Vector3D<float>	pos{ 0, 0, 0 };

			PacketReplace() = default;
			~PacketReplace() = default;
			PacketReplace(const PacketReplace&) = delete;
			PacketReplace(PacketReplace&&) = delete;

			PacketReplace& operator<<(fe::PacketBuilder& pb)
			{
				pb >> worldId;
				pb >> pos;
				return *this;
			}
		};
#pragma warning( default : 4251 )
	}
}
