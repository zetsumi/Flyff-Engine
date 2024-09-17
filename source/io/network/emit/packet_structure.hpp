#pragma once

#pragma warning( disable: 4251 )
namespace fe
{
    struct API_DECLSPEC  PacketStructure
    {
        uint32_t size = 0;
        unsigned char* data = nullptr;

        PacketStructure() = default;
        ~PacketStructure()
        {
        }
    };

    [[nodiscard]] inline bool	isValid(PacketStructure* ps) { return ps != nullptr && ps->size > 0 && ps->data != nullptr; }
    [[nodiscard]] inline bool	isInValid(PacketStructure* ps) { return !isValid(ps); }
}
#pragma warning( default : 4251 )
