#pragma once

namespace fe
{
    namespace packet
    {
#pragma warning( disable: 4251 )
        struct API_DECLSPEC PacketGetCorePlayer : public fe::PacketMessage
        {

            unsigned short count = 0;
            char ** playersName = nullptr;

            PacketGetCorePlayer() = default;
            ~PacketGetCorePlayer() = default;
            PacketGetCorePlayer(const PacketGetCorePlayer&) = delete;
            PacketGetCorePlayer(PacketGetCorePlayer&&) = delete;

            PacketGetCorePlayer& operator<<(fe::PacketBuilder& pb)
            {
                pb >> count;
                playersName = new char*[count]();
                for (unsigned short i = 0; i < count; ++i)
                    playersName[i] = const_cast<char*>(pb.readString());
                return *this;
            }

            void	release() override final
            {
                for (unsigned short i = 0; i < count; ++i)
                    delete playersName[i];
                delete[] playersName;
            }
        };
#pragma warning( default : 4251 )
    }
}
