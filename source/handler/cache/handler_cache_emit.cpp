#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::sendJoin(
	fe::type::_SOCKET id,
	std::uint32_t idWorld,
	std::uint32_t idPlayer,
	std::uint32_t authKey,
	std::uint32_t idParty,
	std::uint32_t idGuild,
	std::uint32_t idWar,
	std::uint32_t idOfMulti,
	std::uint8_t slot,
	char const* playerName,
	char const* account,
	char const* password
)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::JOIN);

	pb.write<std::uint32_t>(idWorld);
	pb.write<std::uint32_t>(idPlayer);
	pb.write<std::uint32_t>(authKey);
	pb.write<std::uint32_t>(idParty);
	pb.write<std::uint32_t>(idGuild);
	pb.write<std::uint32_t>(idWar);
	pb.write<std::uint32_t>(idOfMulti);
	pb.write<std::uint8_t>(slot);

	pb.writeString(playerName);
	pb.writeString(account);
	pb.writeString(password);

	// skip list friend
	pb.write<std::uint32_t>(0);
	pb.write<std::int32_t>(0);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerCache::sendGetPosition(fe::type::_SOCKET id, std::uint32_t idMover)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::QUERYGETPOS);

	pb.write<std::uint32_t>(idMover);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerCache::sendDestinationPosition(fe::type::_SOCKET id, const fe::util::Vector3D<float>& destination, std::uint8_t forward)
{
	lockerSend.lock();

	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::SNAPSHOT);

	pb.write<std::uint8_t>(1);
	pb.write<unsigned short>(static_cast<unsigned short>(fe::snapshot::SNAPSHOTTYPE::DESTPOS));

	pb.write<float>(destination.x);
	pb.write<float>(destination.y);
	pb.write<float>(destination.z);
	pb.write<std::uint8_t>(forward);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}
