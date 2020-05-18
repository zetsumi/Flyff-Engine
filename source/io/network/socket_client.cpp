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

	WSADATA	wsa;
	int errorCode = ::WSAStartup(MAKEWORD(2, 2), &wsa);
	if (errorCode != 0)
		return false;

	struct addrinfo hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	struct addrinfo* result = nullptr;
	std::string stringPort = std::to_string(network.getPort());
	const char* port = stringPort.c_str();
	const char* ip = network.getIP();
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
	return true;
}


void	fe::SocketClient::clean(void)
{
	closesocket(_socket);
	WSACleanup();
}

void	fe::SocketClient::shutdown(void)
{
	if (::shutdown(_socket, SD_SEND) == SOCKET_ERROR)
		clean();
}
