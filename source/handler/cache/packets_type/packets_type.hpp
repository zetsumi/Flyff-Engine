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

namespace fe
{
	namespace packet
	{
		namespace factory
		{
			[[nodiscard]] inline fe::PacketMessage* replace(void) { return new fe::packet::PacketReplace(); }
			[[nodiscard]] inline fe::PacketMessage* say(void) { return new fe::packet::PacketSay(); }
			[[nodiscard]] inline fe::PacketMessage* gmSay(void) { return new fe::packet::PacketGmSay(); }
			[[nodiscard]] inline fe::PacketMessage* getPlayerAddr(void) { return new fe::packet::PacketGetPlayerAddr(); }
			[[nodiscard]] inline fe::PacketMessage* getPlayerCount(void) { return new fe::packet::PacketGetPlayerCount(); }
			[[nodiscard]] inline fe::PacketMessage* getCorePlayer(void) { return new fe::packet::PacketGetCorePlayer(); }
			[[nodiscard]] inline fe::PacketMessage* system(void) { return new fe::packet::PacketSystem(); }
			[[nodiscard]] inline fe::PacketMessage* caption(void) { return new fe::packet::PacketCaption(); }
		}
	}
}