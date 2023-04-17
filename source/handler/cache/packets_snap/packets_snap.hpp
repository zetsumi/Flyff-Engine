#pragma once

#include <pch_fnetwork.h>
#include <assert.h>
#include <io/network/message/snapshot_type.hpp>
#include <io/network/message/packet_message.hpp>
#include <io/network/emit/packet_builder.hpp>

namespace fe
{
	namespace snapshot
	{
		struct Snapshot
		{
			std::uint32_t objid = 0;
			std::uint32_t objIdPlayer = 0;
			fe::snapshot::SNAPSHOTTYPE snapshotType = fe::snapshot::SNAPSHOTTYPE::MAX_ERROR;

			Snapshot(Snapshot&&) = delete;
			Snapshot& operator=(const Snapshot&) = delete;
			Snapshot(const Snapshot&) = delete;
			Snapshot(Snapshot* s) = delete;

			Snapshot() = default;
			virtual ~Snapshot() = default;
			virtual Snapshot& operator<<(fe::PacketBuilder&) = 0;

			virtual void	release() {}
		};

		struct SnapshotList : public PacketMessage
		{
			unsigned short count = 0;
			Snapshot** snaps = nullptr;

			SnapshotList(const SnapshotList&) = delete;
			SnapshotList(SnapshotList&&) = delete;
			SnapshotList(SnapshotList*) = delete;
			SnapshotList& operator=(const SnapshotList) = delete;

			SnapshotList() = default;
			~SnapshotList() = default;
			SnapshotList& operator<<(fe::PacketBuilder&) { assert(false); return *this; }

			void	release() override final
			{
				for (unsigned short i = 0; i < count; ++i)
				{
					snaps[i]->release();
					delete snaps[i];
					snaps[i] = nullptr;
				}
				delete[] snaps;
				snaps = nullptr;
			}

		};
	}

}

#include <handler/cache/packets_snap/packet_snap_world_read_info.hpp>
#include <handler/cache/packets_snap/packet_snap_environment_all.hpp>
#include <handler/cache/packets_snap/packet_snap_add_obj.hpp>
#include <handler/cache/packets_snap/packet_snap_query_player_data.hpp>
#include <handler/cache/packets_snap/packet_snap_dest_pos.hpp>
#include <handler/cache/packets_snap/packet_snap_mover_corr.hpp>
#include <handler/cache/packets_snap/packet_snap_get_position.hpp>
#include <handler/cache/packets_snap/packet_snap_state_machine_mode_all.hpp>
#include <handler/cache/packets_snap/packet_snap_game_timer.hpp>
#include <handler/cache/packets_snap/packet_snap_all_action.hpp>
#include <handler/cache/packets_snap/packet_snap_secret_room_manager_state.hpp>
#include <handler/cache/packets_snap/packet_snap_chat.hpp>
#include <handler/cache/packets_snap/packet_snap_mover_moved.hpp>
#include <handler/cache/packets_snap/packet_snap_mover_moved_2.hpp>
#include <handler/cache/packets_snap/packet_snap_mover_behavior.hpp>
#include <handler/cache/packets_snap/packet_snap_mover_behavior_2.hpp>


namespace fe
{
	namespace snapshot
	{
		namespace factory
		{
			[[nodiscard]] inline fe::snapshot::Snapshot* workReadInfo() { return new fe::snapshot::SnapshotWorldReadInfo(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* environmentAll() { return new fe::snapshot::SnapshotEnvironmentAll(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* addObj() { return new fe::snapshot::SnapshotAddObj(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* queryPlayerData() { return new fe::snapshot::SnapshotQueryPlayerData(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* destPos() { return new fe::snapshot::SnapshotDestPos(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* moverCorr() { return new fe::snapshot::SnapshotMoverCorr(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* getPosition() { return new fe::snapshot::SnapshotGetPosition(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* stateMachineModeAll() { return new fe::snapshot::SnapshotStateMachineModeAll(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* gameTimer() { return new fe::snapshot::SnapshotGameTimer(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* allAction() { return new fe::snapshot::SnapshotAllAction(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* secretRoomManagerState() { return new fe::snapshot::SnapshotSecretRoomManagerState(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* chat() { return new fe::snapshot::SnapshotChat(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* moverMoved() { return new fe::snapshot::SnapshotMoverMoved(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* moverMoved2() { return new fe::snapshot::SnapshotMoverMoved2(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* moverBehavior() { return new fe::snapshot::SnapshotMoverBehavior(); }
			[[nodiscard]] inline fe::snapshot::Snapshot* moverBehavior2() { return new fe::snapshot::SnapshotMoverBehavior2(); }
		}
	}
}