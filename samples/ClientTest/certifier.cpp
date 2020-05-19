#include "./header.hpp"


extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;


bool	handler_certifier(void)
{
	fe::Network network;

	network.setIP("127.0.0.1");
	network.setPort(23000);
	if (network.isValid() == false)
		return false;

	if (transCertifier.setSocket(&_socketCert) == false)
		return false;
	transCertifier.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socketCert.connect(network) == false)
		return false;

	certifier.initialize();

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &certifier, std::placeholders::_1, std::placeholders::_2);
	if (transCertifier.run(onMsg) == false)
		return false;

	transCertifier.wait();
	FE_CONSOLELOG("out");
	return true;
}