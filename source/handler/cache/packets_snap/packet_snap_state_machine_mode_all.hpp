#pragma once

namespace fe
{
	namespace snapshot
	{
		struct SnapshotStateMachineModeAll : public Snapshot
		{
			struct StateMachine
			{
				int32_t	type = 0;
				uint32_t	time = 0;
				StateMachine() = default;
				~StateMachine() = default;
			};

			short	count = 0;
			StateMachine*		stateMachine = nullptr;

			SnapshotStateMachineModeAll() = default;
			~SnapshotStateMachineModeAll() = default;
			SnapshotStateMachineModeAll& operator<<(fe::PacketBuilder& pb) override
			{
				pb >> count;
				if (count == 0)
					return *this;
				stateMachine = new StateMachine[count];
				for (auto i = 0; i < count; ++i)
				{
					stateMachine[i].type = pb.read<int32_t>();
					stateMachine[i].time = pb.read<uint32_t>();
				}
				return *this;
			}

			void	release() override final
			{
				delete stateMachine;
				stateMachine = nullptr;
			}
		};
	}
}