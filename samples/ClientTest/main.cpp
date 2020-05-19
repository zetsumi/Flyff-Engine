#include <framework_fengine.h>
#include <pch_fnetwork.h>



fe::Network			network{};
fe::SocketClient	_socket{};
fe::Transaction		trans{};

bool	testCo = false;
unsigned int session_id = 0;




static bool	handler_certifier(void)
{
	if (trans.setSocket(&_socket) == false)
		return false;
	trans.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

	if (_socket.connect(network) == false)
		return false;

	fe::HandlerCertifier certifier;
	certifier.initialize();

	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &certifier, std::placeholders::_1, std::placeholders::_2);
	if (trans.run(onMsg) == false)
		return false;
	trans.wait();
	return true;
}

int main()
{
	network.setIP("127.0.0.1");
	network.setPort(23000);

	if (network.isValid() == false)
		return 1;
	if (handler_certifier() == false)
		return 2;
	return 0;
}