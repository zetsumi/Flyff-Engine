#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;
extern fe::SocketClient			_socketLog;


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
