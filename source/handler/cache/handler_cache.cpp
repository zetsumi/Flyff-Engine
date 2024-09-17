#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>


void fe::HandlerCache::initialize()
{
    fe::HandlerMessage::initialize();

    handlerType = HANDLER_PACKET_TYPE::CACHE;
    initializePacketType();
    initializeSnapshop();
}

void fe::HandlerCache::initializePacketType()
{
    // action
    pushAction(fe::packet::PACKETTYPE::JOIN, std::bind(&fe::HandlerCache::onSnapShot, this));
    pushAction(fe::packet::PACKETTYPE::SNAPSHOT, std::bind(&fe::HandlerCache::onSnapShot, this));

    // factory
    pushAction(fe::packet::PACKETTYPE::PCK_REPLACE, std::bind(fe::packet::factory::replace));
    pushAction(fe::packet::PACKETTYPE::SAY, std::bind(fe::packet::factory::say));
    pushAction(fe::packet::PACKETTYPE::GMSAY, std::bind(fe::packet::factory::gmSay));
    pushAction(fe::packet::PACKETTYPE::GETPLAYERADDR, std::bind(fe::packet::factory::getPlayerAddr));
    pushAction(fe::packet::PACKETTYPE::GETPLAYERCOUNT, std::bind(fe::packet::factory::getPlayerCount));
    pushAction(fe::packet::PACKETTYPE::GETCOREPLAYER, std::bind(fe::packet::factory::getCorePlayer));
    pushAction(fe::packet::PACKETTYPE::SYSTEM, std::bind(fe::packet::factory::system));
    pushAction(fe::packet::PACKETTYPE::CAPTION, std::bind(fe::packet::factory::caption));
    pushAction(fe::packet::PACKETTYPE::DEFINEDTEXT, std::bind(fe::packet::factory::definedText));
    pushAction(fe::packet::PACKETTYPE::GET_CLOCK, std::bind(fe::packet::factory::getClock));
    pushAction(fe::packet::PACKETTYPE::GAMERATE, std::bind(fe::packet::factory::gameRate));
}

void fe::HandlerCache::initializeSnapshop()
{
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::ENVIRONMENTALL] = std::bind(fe::snapshot::factory::environmentAll);
    //snapshotPacket[fe::snapshot::SNAPSHOTTYPE::ADD_OBJ] = std::bind(fe::snapshot::factory::addObj); // WIP
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::WORLD_READINFO] = std::bind(fe::snapshot::factory::workReadInfo);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::QUERY_PLAYER_DATA] = std::bind(fe::snapshot::factory::queryPlayerData);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::DESTPOS] = std::bind(fe::snapshot::factory::destPos);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERCORR] = std::bind(fe::snapshot::factory::moverCorr);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::GETPOS] = std::bind(fe::snapshot::factory::getPosition);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::SM_MODE_ALL] = std::bind(fe::snapshot::factory::stateMachineModeAll);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::GAMETIMER] = std::bind(fe::snapshot::factory::gameTimer);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::ALLACTION] = std::bind(fe::snapshot::factory::allAction);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::SECRETROOM_MNG_STATE] = std::bind(fe::snapshot::factory::secretRoomManagerState);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::CHAT] = std::bind(fe::snapshot::factory::chat);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERMOVED] = std::bind(fe::snapshot::factory::moverMoved);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERMOVED2] = std::bind(fe::snapshot::factory::moverMoved2);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERBEHAVIOR] = std::bind(fe::snapshot::factory::moverBehavior);
    snapshotPacket[fe::snapshot::SNAPSHOTTYPE::MOVERBEHAVIOR2] = std::bind(fe::snapshot::factory::moverBehavior2);
}
