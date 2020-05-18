#pragma once

#include <winsock.h>
#include <io/network/emit/packet_structure.hpp>

typedef void	(*callbackOnMessage)(SOCKET id, fe::PacketStructure* ps);
