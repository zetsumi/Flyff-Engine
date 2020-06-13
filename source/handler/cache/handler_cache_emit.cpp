#include <pch_fnetwork.h>
#include <io/network/message/snapshot_type.hpp>

void fe::HandlerCache::sendJoin(fe::type::_SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
	fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
	fe::type::_32uint idOfMulti, fe::type::_uchar slot,
	const char* playerName, const char* account, const char* password
)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::JOIN);

	pb.write<fe::type::_32uint>(idWorld);
	pb.write<fe::type::_32uint>(idPlayer);
	pb.write<fe::type::_32uint>(authKey);
	pb.write<fe::type::_32uint>(idParty);
	pb.write<fe::type::_32uint>(idGuild);
	pb.write<fe::type::_32uint>(idWar);
	pb.write<fe::type::_32uint>(idOfMulti);
	pb.write<fe::type::_uchar>(slot);

	pb.writeString(playerName);
	pb.writeString(account);
	pb.writeString(password);

	// skip list friend
	pb.write<fe::type::_32uint>(0);
	pb.write<fe::type::_32int>(0);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerCache::sendGetPosition(fe::type::_SOCKET id, fe::type::_32uint idMover)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::QUERYGETPOS);

	pb.write<fe::type::_32uint>(idMover);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}

void fe::HandlerCache::sendDestinationPosition(fe::type::_SOCKET id, const fe::util::Vector3D<float>& destination, fe::type::_uchar forward)
{
	lockerSend.lock();

	fe::PacketBuilder pb;

	pb.write<fe::packet::PACKETTYPE>(fe::packet::PACKETTYPE::SNAPSHOT);

	pb.write<fe::type::_uchar>(1);
	pb.write<unsigned short>(static_cast<unsigned short>(fe::snapshot::SNAPSHOTTYPE::DESTPOS));

	pb.write<float>(destination.x);
	pb.write<float>(destination.y);
	pb.write<float>(destination.z);
	pb.write<fe::type::_uchar>(forward);

	pb.writeHeader(sessionID, handlerType);
	if (transaction->sender(pb) == false)
		FE_CONSOLELOG("fail send");

	lockerSend.unlock();
}
