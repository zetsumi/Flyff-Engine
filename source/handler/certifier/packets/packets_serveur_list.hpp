#pragma once

namespace fe
{
	struct PacketServerList : public PacketMessage
	{
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
			inline ServerInfo operator<<(fe::PacketBuilder& pb)
			{
				parent = pb.read<fe::type::_32uint>();
				id = pb.read<fe::type::_32uint>();
				name = pb.readString();
				addr = pb.readString();
				unknow = pb.read<fe::type::_32uint>();
				count = pb.read<fe::type::_32uint>();
				enable = pb.read<fe::type::_32uint>();
				max = pb.read<fe::type::_32uint>();
				return *this;
			}
		};

		fe::type::_32uint	authKey = 0;
		fe::type::_uchar	accountFlag = 0;
		char*				account = nullptr;
		fe::type::_32uint	numberServer = 0;
		ServerInfo*			servers = nullptr;

		PacketServerList() = default;
		~PacketServerList() = default;

		inline PacketServerList& operator<<(fe::PacketBuilder& pb) override
		{
			authKey = pb.read<fe::type::_32uint>();
			accountFlag = pb.read<fe::type::_uchar>();
			account = const_cast<char*>(pb.readString());
			numberServer = pb.read<fe::type::_32uint>();

			servers = new ServerInfo[numberServer];
			for (fe::type::_32uint i = 0; i < numberServer; ++i)
				servers[i] << pb;
			return *this;
		}

	};
}