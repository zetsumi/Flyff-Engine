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

	// test connection
	certifier.sendCertify(_socket.getSocket(), TEST_DEFAULT_BUILD_VERSION, TEST_DEFAULT_ACCOUNT, TEST_DEFAULT_PASSWORD);

	transCertifier.wait();
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
	transLogin.wait();
	FE_CONSOLELOG("out");
	return true;
}

int main()
{
	std::thread tcert(handler_certifier);
	std::thread tlogin(handler_login);

	tcert.join();
	tlogin.join();

	return 0;
}