#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotAllAction : public Snapshot
		{
			std::int32_t	isAllAction = false;
			std::int32_t	isCharacter = false;

			SnapshotAllAction() = default;
			~SnapshotAllAction() = default;
			SnapshotAllAction& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> isAllAction >> isCharacter;
				return *this;
			}
		};
	}
}