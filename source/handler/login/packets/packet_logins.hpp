#pragma once

#include <pch_fnetwork.h>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/packet_builder.hpp>

#include <handler/login/packets/packet_query_tick.hpp>
#include <handler/login/packets/packet_cache_addr.hpp>
#include <handler/login/packets/packet_player_list.hpp>
#include <handler/login/packets/packet_protect_num_pad.hpp>
#include <handler/login/packets/packet_protect_login_cert.hpp>


namespace fe
{
    namespace packettype
    {
        [[nodiscard]] inline fe::PacketMessage* queryTick() { return new fe::packet::PacketQueryTick(); }
        [[nodiscard]] inline fe::PacketMessage* playerList() { return new fe::packet::PacketListPlayer(); }
        [[nodiscard]] inline fe::PacketMessage* protectNumPad() { return new fe::packet::PacketProtectNumPad(); }
        [[nodiscard]] inline fe::PacketMessage* protectLoginCert() { return new fe::packet::PacketProtectLoginCert(); }
        [[nodiscard]] inline fe::PacketMessage* preJoin() { return nullptr; }
    }
}