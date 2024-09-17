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


bool	handler_login(void)
{
    fe::Network network;

    network.setIP("127.0.0.1");
    network.setPort(fe::portLoginServer);
    if (network.isValid() == false)
        return false;

    if (transLogin.setSocket(&_socketLog) == false)
        return false;
    transLogin.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);
    uint32_t headerLength = sizeof(uint8_t) + sizeof(uint32_t) + sizeof(uint32_t);
    transLogin.setLengthBuffer(headerLength);

    if (_socketLog.connect(network) == false)
        return false;

    login.initialize();
    login.setTransaction(&transLogin);

    auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &login, std::placeholders::_1);
    if (transLogin.run(onMsg) == false)
        return false;
    transLogin.wait();
    login.killPing();
    FE_CONSOLELOG("out");
    return true;
}
