#include "./header.hpp"

fe::Transaction			transCertifier{};
fe::Transaction			transLogin{};
fe::Transaction			transCache{};

fe::SocketClient			_socketCert{};
fe::SocketClient			_socketLog{};
fe::SocketClient			_socketCache{};

fe::HandlerCertifier		certifier{};
fe::HandlerLogin			login{};
fe::HandlerCache			cache{};



int main()
{
	std::thread tcert(handler_certifier);
	std::thread	console(prompt);

	tcert.join();
	console.join();
	return 0;
}