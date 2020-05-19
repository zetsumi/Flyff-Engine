#include "./header.hpp"

fe::Transaction			transCertifier{};
fe::Transaction			transLogin{};
fe::HandlerCertifier	certifier;
fe::SocketClient		_socketCert;
fe::HandlerLogin		login;


int main()
{
	std::thread tcert(handler_certifier);
	std::thread	console(prompt);

	tcert.join();
	console.join();
	return 0;
}