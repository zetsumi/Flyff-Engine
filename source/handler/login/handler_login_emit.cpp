#include <pch_fnetwork.h>
#include <handler/login/handler_login.hpp>
#include <ctime>


void fe::HandlerLogin::sendQueryTickCount(fe::type::_SOCKET id)
{
    lockerSend.lock();
    fe::PacketBuilder pb;

    std::time_t	tm = std::time(nullptr);
    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::QUERYTICKCOUNT);
    pb.write<int32_t>(static_cast<uint32_t>(tm));

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}

void fe::HandlerLogin::sendGetListPlayer(fe::type::_SOCKET id, const char* protocolVersion, uint32_t authKey,
                                        const char* account, const char* password, uint32_t idServer)
{
    lockerSend.lock();
    fe::PacketBuilder pb;

    std::time_t	tm = std::time(nullptr);
    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::GETPLAYERLIST);
    pb.writeString(protocolVersion);
    pb.write<uint32_t>(authKey);
    pb.writeString(account);
    pb.writeString(password);
    pb.write<uint32_t>(idServer);

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}

void fe::HandlerLogin::sendPreJoin(fe::type::_SOCKET id, const char* account, uint32_t idPlayer, const char* playerName, int32_t secretPIN)
{
    lockerSend.lock();
    fe::PacketBuilder pb;

    std::time_t	tm = std::time(nullptr);
    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::PRE_JOIN);
    pb.writeString(account);
    pb.write<uint32_t>(idPlayer);
    pb.writeString(playerName);
    pb.write<int32_t>(secretPIN);

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}
