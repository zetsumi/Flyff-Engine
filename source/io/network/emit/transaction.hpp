#pragma once

#include <thread>
#include <functional>

#include <framework_fengine.h>
#include <io/network/socket_client.hpp>
#include <io/network/emit/packet_builder.hpp>

#define	DEFAULT_BUFFER_SIZE_RECEIVE 1000

namespace fe
{
	enum class MODE_TRANSACTION : unsigned int
	{
		MODE_UNKNOW,
		MODE_SERVER,
		MODE_CLIENT
	};

	class API_DECLSPEC Transaction
	{
		std::thread			main;
		Socket* _socket = nullptr;
		MODE_TRANSACTION	mode = MODE_TRANSACTION::MODE_UNKNOW;
		std::function<void(SOCKET id, fe::PacketStructure* ps)>	handlerMessageCallBack = nullptr;
		unsigned int	lengthBuffer = DEFAULT_BUFFER_SIZE_RECEIVE;


		[[noreturn]] void	loopReceive(SOCKET idClient);
		[[nodiscard]] bool	run(void);

	public:
		Transaction() = default;
		~Transaction() = default;

		// global
		[[nodiscard]] bool	setSocket(Socket* s);
		[[noreturn]] void	setMode(MODE_TRANSACTION modeTransaction);
		[[noreturn]] void	setLengthBuffer(unsigned int len);
		[[nodiscard]] const Socket const* getSocket(void) const;
		[[nodiscard]] bool	isMode(MODE_TRANSACTION modeTransaction);
		[[nodiscard]] bool	run(std::function<void(SOCKET id, fe::PacketStructure* ps)> callback);

		// emiter
		[[nodiscard]] bool	sender(SOCKET idSocket, unsigned int size, const char* data);
		[[nodiscard]] bool	sender(SOCKET idSocket, PacketBuilder& packet);
		[[nodiscard]] bool	sender(PacketBuilder& packet);
		[[nodiscard]] PacketStructure* receiver(SOCKET idSocket);
		[[nodiscard]] PacketStructure* receiver(SOCKET idSocket, unsigned int bufferSize);

		// thread manager
		[[noreturn]] void	wait(bool waiting = true);
	};
}
