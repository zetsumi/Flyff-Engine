#pragma once

#include <pch_fnetwork.h>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/packet_builder.hpp>

#include <handler/certifier/packets/packets_serveur_list.hpp>

namespace fe
{
	namespace packettype
	{
		[[nodiscard]] inline fe::PacketMessage* serveurList(void) { return new fe::PacketServerList(); }
	}
}