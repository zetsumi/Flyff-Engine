#include <pch_fnetwork.h>
#include <io/network/socket_client.hpp>

fe::SocketClient::~SocketClient()
{
    shutdown();
    clean();
}

bool	fe::SocketClient::connect(const Network& network)
{
    if (network.isValid() == false)
        return false;
    int errorCode = 0;
    uint32_t nport = network.getPort();
    std::string stringPort = std::to_string(nport);
    const char* port = stringPort.c_str();
    const char* ip = network.getIP();

#if defined(_WIN64) || defined(_WIN32)
    WSADATA	wsa;
    errorCode = ::WSAStartup(MAKEWORD(2, 2), &wsa);
    if (errorCode != 0)
        return false;

    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo* result = nullptr;
    errorCode = ::getaddrinfo(ip, port, &hints, &result);
    if (errorCode != 0)
    {
        ::WSACleanup();
        return false;
    }

    struct addrinfo* ptr;
    for ( ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        _socket = ::socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (_socket == INVALID_SOCKET)
        {
            ::WSACleanup();
            return false;
        }

        errorCode = ::connect(_socket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (errorCode == SOCKET_ERROR)
        {
            closesocket(_socket);
            _socket = INVALID_SOCKET;
            continue;
        }
        break;
    }
    ::freeaddrinfo(result);
    if (_socket == INVALID_SOCKET)
        return false;
#else
    struct sockaddr_in in;
    socklen_t len;

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    len = sizeof(in);
    ::memset(&in, 0x00, len);
    in.sin_family = AF_INET;
    in.sin_port = htons(nport);
    ::inet_aton(ip, &in.sin_addr);
    errorCode = ::connect(_socket, (struct sockaddr *)&in, len);
    if (errorCode == -1)
    {
        ::close(_socket);
        return false;
    }
#endif
    return true;
}


void	fe::SocketClient::clean()
{
#if defined(_WIN64)
    closesocket(_socket);
    WSACleanup();
#elif defined(__APPLE__)
    ::close(_socket);
#endif
}

void	fe::SocketClient::shutdown()
{
#if defined(_WIN64)
    if (::shutdown(_socket, SD_SEND) == SOCKET_ERROR)
        clean();
#elif defined(__APPLE__)
    clean();
#endif
}
