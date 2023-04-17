#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotQueryPlayerData : public Snapshot
		{

			std::uint32_t	idPlayer = 0;
			const char* playerName = nullptr;
			std::uint8_t	job = 0;
			std::uint8_t	level = 0;
			std::uint8_t	sex = 0;
			std::int32_t	ver = 0;
			std::int32_t	login = 0;

			SnapshotQueryPlayerData() = default;
			~SnapshotQueryPlayerData() = default;
			SnapshotQueryPlayerData& operator<<(fe::PacketBuilder& pb) override
			{
				std::uint32_t idPlayer = pb.read<std::uint32_t>();
				const char* playerName = pb.readString();

				std::uint8_t	job = pb.read<std::uint8_t>();
				std::uint8_t	level = pb.read<std::uint8_t>();
				std::uint8_t	sex = pb.read<std::uint8_t>();
				pb.read<std::uint8_t>();
				std::int32_t	ver = pb.read<std::int32_t>();
				std::int32_t	login = pb.read<std::int32_t>();

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