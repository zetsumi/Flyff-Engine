#include "./header.hpp"

extern fe::Transaction			transCertifier;
extern fe::Transaction			transLogin;
extern fe::HandlerCertifier		certifier;
extern fe::SocketClient			_socketCert;
extern fe::HandlerLogin			login;


bool	handler_login(void)
{
	fe::Network network;
	fe::SocketClient _socket;

	network.setIP("127.0.0.1");
	network.setPort(28000);
	if (network.isValid() == false)
		return false;

	if (transLogin.setSocket(&_socket) == false)
		return false;
	transLogin.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socket.connect(network) == false)
		return false;

	login.initialize();

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &login, std::placeholders::_1, std::placeholders::_2);
	if (transLogin.run(onMsg) == false)
		return false;
	transLogin.wait();
	FE_CONSOLELOG("out");
	return true;
}