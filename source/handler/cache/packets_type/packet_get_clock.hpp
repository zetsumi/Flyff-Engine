#pragma once

namespace fe
{
    namespace packet
    {
#pragma warning( disable: 4251 )
        struct API_DECLSPEC PacketGetClock : public fe::PacketMessage
        {
            uint8_t	clockOfClient = 0;

            PacketGetClock() = default;
            ~PacketGetClock() = default;
            PacketGetClock(const PacketGetClock&) = delete;
            PacketGetClock(PacketGetClock&&) = delete;

            PacketGetClock& operator<<(fe::PacketBuilder& pb)
            {
                pb >> clockOfClient;
                return *this;
            }
        };
#pragma warning( default : 4251 )
    }
}
