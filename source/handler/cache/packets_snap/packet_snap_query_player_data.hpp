#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotQueryPlayerData : public Snapshot
		{

			fe::type::_32uint	idPlayer = 0;
			const char* playerName = nullptr;
			fe::type::_uchar	job = 0;
			fe::type::_uchar	level = 0;
			fe::type::_uchar	sex = 0;
			fe::type::_32int	ver = 0;
			fe::type::_32int	login = 0;

			SnapshotQueryPlayerData() = default;
			~SnapshotQueryPlayerData() = default;
			SnapshotQueryPlayerData& operator<<(fe::PacketBuilder& pb) override
			{
				fe::type::_32uint idPlayer = pb.read<fe::type::_32uint>();
				const char* playerName = pb.readString();

				fe::type::_uchar	job = pb.read<fe::type::_uchar>();
				fe::type::_uchar	level = pb.read<fe::type::_uchar>();
				fe::type::_uchar	sex = pb.read<fe::type::_uchar>();
				pb.read<fe::type::_uchar>();
				fe::type::_32int	ver = pb.read<fe::type::_32int>();
				fe::type::_32int	login = pb.read<fe::type::_32int>();

				FE_CONSOLELOG("job{%02x}", job);
				FE_CONSOLELOG("level{%02x}", level);
				FE_CONSOLELOG("sex{%02x}", sex);
				FE_CONSOLELOG("ver{%d}", ver);
				FE_CONSOLELOG("login{%d}", login);

				return *this;
			}

			void	release() override final
			{
				delete playerName;
				playerName = nullptr;
			}
		};
	}
}