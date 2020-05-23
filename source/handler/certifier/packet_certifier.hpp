#pragma once

#include <pch_fnetwork.h>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	struct PacketServerList
	{
		fe::type::_32uint	authKey = 0;
		fe::type::_uchar	accountFlag = 0;
		char* account = nullptr;
		fe::type::_32uint	numberServer = 0;

		struct ServerInfo
		{
			fe::type::_32uint parent = 0;
			fe::type::_32uint id = 0;
			const char* name = nullptr;
			const char* addr = nullptr;
			fe::type::_32uint unknow = 0;
			fe::type::_32uint count = 0;
			fe::type::_32uint enable = 0;
			fe::type::_32uint max = 0;

			ServerInfo() = default;
			~ServerInfo() = default;
		};
		ServerInfo* servers;

		PacketServerList() = default;
		~PacketServerList() = default;
		PacketServerList(const PacketServerList& ps) = default;
		PacketServerList(PacketServerList&& ps) = default;
		PacketServerList& operator=(const PacketServerList& ps) = default;
		PacketServerList& operator<<(fe::PacketBuilder& pb)
		{
			authKey = pb.read<fe::type::_32uint>();
			accountFlag = pb.read<fe::type::_uchar>();
			account = const_cast<char*>(pb.readString());
			numberServer = pb.read<fe::type::_32uint>();

			servers = new ServerInfo[numberServer];
			for (fe::type::_32uint i = 0; i < numberServer; ++i)
			{
				servers[i].parent = pb.read<fe::type::_32uint>();
				servers[i].id = pb.read<fe::type::_32uint>();
				servers[i].name = pb.readString();
				servers[i].addr = pb.readString();
				servers[i].unknow = pb.read<fe::type::_32uint>();
				servers[i].count = pb.read<fe::type::_32uint>();
				servers[i].enable = pb.read<fe::type::_32uint>();
				servers[i].max = pb.read<fe::type::_32uint>();
			}
			return *this;
		}

	};
}