#include <pch_fnetwork.h>

void fe::HandlerCache::sendJoin(SOCKET id, fe::type::_32uint idWorld, fe::type::_32uint idPlayer, fe::type::_32uint authKey,
	fe::type::_32uint idParty, fe::type::_32uint idGuild, fe::type::_32uint idWar,
	fe::type::_32uint idOfMulti, fe::type::_uchar slot,
	const char* playerName, const char* account, const char* password
)
{
	lockerSend.lock();
	fe::PacketBuilder pb;

	pb.write<fe::type::_32uint>(PACKETTYPE_JOIN);

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
	transaction->sender(pb);

	lockerSend.unlock();
}