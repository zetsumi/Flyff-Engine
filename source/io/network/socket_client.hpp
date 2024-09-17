#pragma once

#include <framework_fengine.h>
#include <io/network/socket.hpp>

namespace fe
{
    class API_DECLSPEC SocketClient : public fe::Socket
    {
    public:
        SocketClient() = default;
        ~SocketClient();

        bool	connect(const Network& network);
        void	clean() override;
        void	shutdown() override;
    };
}

