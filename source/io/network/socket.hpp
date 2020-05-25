#pragma once

#include <framework_fengine.h>
#if defined(_WIN64)
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Mswsock.lib")
#pragma comment(lib, "AdvApi32.lib")
#elif defined(__APPLE__)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h> /* pour memset */
#include <netinet/in.h> /* pour struct sockaddr_in */
#include <arpa/inet.h> /* pour htons et inet_aton */
#endif

#include <io/network/network.hpp>

#pragma warning( disable: 4251 )
namespace fe
{
	class API_DECLSPEC Socket
	{
	protected:
#if defined(_WIN64)
		fe::type::_SOCKET	_socket = INVALID_SOCKET;
#else
		fe::type::_SOCKET	_socket = 0;
#endif 

	public:
		virtual ~Socket() {}
		virtual void	clean(void) = 0;
		virtual void	shutdown(void) = 0;
		fe::type::_SOCKET	getSocket(void) const { return _socket; }
	};
}
#pragma warning( default : 4251 )
