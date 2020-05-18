#pragma once

#include <thread>
#include <functional>

#include <framework_fengine.h>
#include <io/network/socket_client.hpp>
#include <io/network/emit/packet_builder.hpp>
#include <io/network/emit/message_handler.hpp>

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
		std::thread	main;
		Socket* _socket = nullptr;
		MODE_TRANSACTION	mode = MODE_TRANSACTION::MODE_UNKNOW;
		callbackOnMessage	onPacketMessage = nullptr;


		bool	runClient(void);
		void	loopReceive(SOCKET idClient);

	public:
		Transaction() = default;
		~Transaction() = default;

		// global
		bool	setSocket(Socket* s);
		void	setMode(MODE_TRANSACTION modeTransaction);
		bool	isMode(MODE_TRANSACTION modeTransaction);
		bool	run(callbackOnMessage callback);

		// emiter
		bool	sender(SOCKET idSocket, unsigned int size, const char* data);
		bool	sender(SOCKET idSocket, PacketBuilder& packet);
		PacketStructure* receiver(SOCKET idSocket);
		PacketStructure* receiver(SOCKET idSocket, unsigned int bufferSize);

		void	wait(bool waiting = true);
	};
}
