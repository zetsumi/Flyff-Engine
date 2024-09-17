#pragma once

#include <thread>
#include <functional>

#include <framework_fengine.h>
#include <io/network/socket_client.hpp>
#include <io/network/emit/packet_builder.hpp>

#define	DEFAULT_BUFFER_SIZE_RECEIVE 1000

#pragma warning( disable: 4251 )
namespace fe
{
    enum class MODE_TRANSACTION : uint32_t
    {
        MODE_UNKNOW,
        MODE_SERVER,
        MODE_CLIENT
    };

    class API_DECLSPEC Transaction
    {
        std::thread			main{};
        Socket* _socket = nullptr;
        MODE_TRANSACTION	mode = MODE_TRANSACTION::MODE_UNKNOW;
        std::function<void (fe::PacketStructure* ps)>	handlerMessageCallBack = nullptr;
        uint32_t	lengthBuffer = DEFAULT_BUFFER_SIZE_RECEIVE;


        void	loopReceive(fe::type::_SOCKET idClient);
        [[nodiscard]] bool	run();

    public:
        Transaction() = default;
        ~Transaction() = default;

        // global
        [[nodiscard]] bool	setSocket(Socket* s);
        void	setMode(MODE_TRANSACTION modeTransaction);
        void	setLengthBuffer(uint32_t len);
        [[nodiscard]] const Socket * const getSocket() const;
        [[nodiscard]] bool	isMode(MODE_TRANSACTION modeTransaction);
        [[nodiscard]] bool	run(std::function<void(fe::PacketStructure* ps)> callback);

        // emiter
        [[nodiscard]] bool	sender(fe::type::_SOCKET idSocket, uint32_t size, const char* data);
        [[nodiscard]] bool	sender(fe::type::_SOCKET idSocket, PacketBuilder& packet);
        [[nodiscard]] bool	sender(PacketBuilder& packet);
        [[nodiscard]] PacketStructure* receiver(fe::type::_SOCKET idSocket);
        [[nodiscard]] PacketStructure* receiver(fe::type::_SOCKET idSocket, uint32_t bufferSize);

        // thread manager
        void	wait(bool waiting = true);
    };
}
#pragma warning( default : 4251 )

