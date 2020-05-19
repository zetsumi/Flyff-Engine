#include <framework_fengine.h>
#include <pch_fnetwork.h>


fe::Transaction		transCertifier{};
fe::Transaction		transLogin{};


static bool	handler_certifier(void)
{
	fe::Network network;
	fe::SocketClient _socket;

	network.setIP("127.0.0.1");
	network.setPort(23000);
	if (network.isValid() == false)
		return false;

	if (transCertifier.setSocket(&_socket) == false)
		return false;
	transCertifier.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socket.connect(network) == false)
		return false;

	fe::HandlerCertifier certifier;
	certifier.initialize();

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &certifier, std::placeholders::_1, std::placeholders::_2);
	if (transCertifier.run(onMsg) == false)
		return false;
	FE_CONSOLELOG("out");
	return true;
}


static bool	handler_login(void)
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

	fe::HandlerLogin login;
	login.initialize();

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &login, std::placeholders::_1, std::placeholders::_2);
	if (transLogin.run(onMsg) == false)
		return false;
	FE_CONSOLELOG("out");
	return true;
}

int main()
{
	if (handler_certifier() == false)
		return 2;
	if (handler_login() == false)
		return 3;

	transCertifier.wait();
	transLogin.wait();
	return 0;
}