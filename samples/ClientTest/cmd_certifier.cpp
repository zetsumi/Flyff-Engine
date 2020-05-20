#include "./header.hpp"

extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::Transaction			transCache;

extern fe::SocketClient			_socketCert;
extern fe::SocketClient			_socketLog;
extern fe::SocketClient			_socketCache;

extern fe::HandlerCertifier		certifier;
extern fe::HandlerLogin			login;
extern fe::HandlerCache			cache;



void	certifier_connect(void)
{
	FE_LOG("connecting Certifier");
	std::thread tcert(handler_certifier);
	tcert.detach();
}

void	cert_disconnect(void)
{
	// TODO :
}
