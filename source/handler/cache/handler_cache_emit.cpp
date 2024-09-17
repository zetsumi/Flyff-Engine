#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::sendJoin(
    fe::type::_SOCKET id,
    uint32_t idWorld,
    uint32_t idPlayer,
    uint32_t authKey,
    uint32_t idParty,
    uint32_t idGuild,
    uint32_t idWar,
    uint32_t idOfMulti,
    uint8_t slot,
    char const* playerName,
    char const* account,
    char const* password
)
{
    lockerSend.lock();
    fe::PacketBuilder pb;

    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::JOIN);

    pb.write<uint32_t>(idWorld);
    pb.write<uint32_t>(idPlayer);
    pb.write<uint32_t>(authKey);
    pb.write<uint32_t>(idParty);
    pb.write<uint32_t>(idGuild);
    pb.write<uint32_t>(idWar);
    pb.write<uint32_t>(idOfMulti);
    pb.write<uint8_t>(slot);

    pb.writeString(playerName);
    pb.writeString(account);
    pb.writeString(password);

    // skip list friend
    pb.write<uint32_t>(0);
    pb.write<int32_t>(0);

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}

void fe::HandlerCache::sendGetPosition(fe::type::_SOCKET id, uint32_t idMover)
{
    lockerSend.lock();
    fe::PacketBuilder pb;

    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::QUERYGETPOS);

    pb.write<uint32_t>(idMover);

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}

void fe::HandlerCache::sendDestinationPosition(fe::type::_SOCKET id, const fe::util::Vector3D<float>& destination, uint8_t forward)
{
    lockerSend.lock();

    fe::PacketBuilder pb;

    pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::SNAPSHOT);

    pb.write<uint8_t>(1);
    pb.write<unsigned short>(static_cast<unsigned short>(fe::snapshot::SNAPSHOTTYPE::DESTPOS));

    pb.write<float>(destination.x);
    pb.write<float>(destination.y);
    pb.write<float>(destination.z);
    pb.write<uint8_t>(forward);

    pb.writeHeader(sessionID, handlerType);
    if (transaction->sender(pb) == false)
        FE_CONSOLELOG("fail send");

    lockerSend.unlock();
}
