#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotStateMachineModeAll : public Snapshot
		{
			struct StateMachine
			{
				StateMachine() = default;
				~StateMachine() = default;
				fe::type::_32int	type = 0;
				fe::type::_32uint	time = 0;
			};

			fe::type::_short	count = 0;
			StateMachine*		stateMachine = nullptr;



			SnapshotStateMachineModeAll() = default;
			~SnapshotStateMachineModeAll() = default;
			inline SnapshotStateMachineModeAll& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> count;
				if (count == 0)
					return *this;
				stateMachine = new StateMachine[count];
				for (auto i = 0; i < count; ++i)
				{
					stateMachine[i].type = pb.read<fe::type::_32int>();
					stateMachine[i].time = pb.read<fe::type::_32uint>();
				}
				return *this;
			}
		};
	}
}