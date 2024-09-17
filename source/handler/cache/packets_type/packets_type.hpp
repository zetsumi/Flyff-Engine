#pragma once

#include <pch_fnetwork.h>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/packet_builder.hpp>

#include <handler/cache/packets_type/packet_replace.hpp>
#include <handler/cache/packets_type/packet_say.hpp>
#include <handler/cache/packets_type/packet_gm_say.hpp>
#include <handler/cache/packets_type/packet_get_player_addr.hpp>
#include <handler/cache/packets_type/packet_get_player_count.hpp>
#include <handler/cache/packets_type/packet_get_core_player.hpp>
#include <handler/cache/packets_type/packet_system.hpp>
#include <handler/cache/packets_type/packet_caption.hpp>
#include <handler/cache/packets_type/packet_defined_text.hpp>
#include <handler/cache/packets_type/packet_get_clock.hpp>
#include <handler/cache/packets_type/packet_game_rate.hpp>

namespace fe
{
    namespace packet
    {
        namespace factory
        {
            [[nodiscard]] inline fe::PacketMessage* replace() { return new fe::packet::PacketReplace(); }
            [[nodiscard]] inline fe::PacketMessage* say() { return new fe::packet::PacketSay(); }
            [[nodiscard]] inline fe::PacketMessage* gmSay() { return new fe::packet::PacketGmSay(); }
            [[nodiscard]] inline fe::PacketMessage* getPlayerAddr() { return new fe::packet::PacketGetPlayerAddr(); }
            [[nodiscard]] inline fe::PacketMessage* getPlayerCount() { return new fe::packet::PacketGetPlayerCount(); }
            [[nodiscard]] inline fe::PacketMessage* getCorePlayer() { return new fe::packet::PacketGetCorePlayer(); }
            [[nodiscard]] inline fe::PacketMessage* system() { return new fe::packet::PacketSystem(); }
            [[nodiscard]] inline fe::PacketMessage* caption() { return new fe::packet::PacketCaption(); }
            [[nodiscard]] inline fe::PacketMessage* definedText() { return new fe::packet::PacketDefinedText(); }
            [[nodiscard]] inline fe::PacketMessage* getClock() { return new fe::packet::PacketGetClock(); }
            [[nodiscard]] inline fe::PacketMessage* gameRate() { return new fe::packet::PacketGameRate(); }
        }
    }
}