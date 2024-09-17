#include <pch_fnetwork.h>
#include <io/network/message/handler_message.hpp>


void fe::HandlerMessage::onMsg(fe::PacketStructure* ps)
{
    fe::packet::PACKETTYPE	packetType = fe::packet::PACKETTYPE::MAX_ERROR;
    uint8_t		mark = 0;
    uint32_t		length = 0;
    fe::type::_SOCKET		idSocket = 0;
    uint32_t			lenData = 0;
    fe::PacketMessage*		msg = nullptr;
    mapAction::iterator		itAction = actions.end();
    mapOperator::iterator	itOperator = packetOperator.end();

    FE_CONSOLELOG("****************");
    packetBuilder.reset();
    if (packetBuilder.setPacket(ps) == false)
    {
        FE_CONSOLELOG("fail on setPacket");
        goto end;
    }

    loadHeader(mark, length, packetType);

    idSocket = transaction->getSocket()->getSocket();
    lenData = length - sizeof(packetType); // Taille moins sizeof() packettype
    if (lenData > 0)
    {
        fe::PacketStructure* psData = transaction->receiver(idSocket, lenData);
        packetBuilder.reset();
        if (packetBuilder.setPacket(psData) == false)
        {
            FE_CONSOLELOG("fail on setPacket");
            goto end;
        }
    }

    itAction = actions.find(packetType);
    if (itAction != actions.end())
    {
        msg = itAction->second();
        goto end;
    }

    itOperator = packetOperator.find(packetType);
    if (itOperator != packetOperator.end())
    {
        msg = itOperator->second();
        if (msg != nullptr)
            *msg << packetBuilder;
        goto end;
    }

    FE_CONSOLELOG("packet type unknow<%#010x>", packetType);

end:
    if (msg != nullptr)
    {
        msg->type = packetType;
        mtMessage.lock();
        messages.push(msg);
        mtMessage.unlock();
    }
    packetBuilder.reset();
    FE_CONSOLELOG("****************");
}


fe::PacketMessage* fe::HandlerMessage::onWelcome()
{
    sessionID = packetBuilder.read<uint32_t>();
    FE_CONSOLELOG("sessionID:{%u}{%#010x}", sessionID);

    auto fct = std::bind(&HandlerMessage::processPing, this);
    ping = std::thread(fct);
    ping.detach();
    return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onKeepAlive()
{
    sendKeepAlive();
    return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onPing()
{
    return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onError()
{
    uint32_t opcodeError = packetBuilder.read<uint32_t>();
    FE_CONSOLELOG("OP CODE: %#010x", opcodeError);
    sendError();
    return nullptr;
}

fe::PacketMessage* fe::HandlerMessage::onErrorString()
{
    const char* messageError = packetBuilder.readString();
    if (messageError != nullptr)
        FE_CONSOLELOG("Message Error: %s", messageError);
    sendError();
    return nullptr;
}
