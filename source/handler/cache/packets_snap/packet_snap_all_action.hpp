#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotAllAction : public Snapshot
		{
			fe::type::_32int	isAllAction = false;
			fe::type::_32int	isCharacter = false;

			SnapshotAllAction() = default;
			~SnapshotAllAction() = default;
			inline SnapshotAllAction& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> isAllAction >> isCharacter;
				return *this;
			}
		};
	}
}