#include <pch_fnetwork.h>
#include <util/log.hpp>
#include <io/network/emit/packet_builder.hpp>
#include <crypto/crc32.hpp>

fe::PacketBuilder::~PacketBuilder()
{
	delete packet;
	packet = nullptr;
}


void fe::PacketBuilder::reset()
{
	offset = 0;
	delete packet;
	packet = nullptr;
}

void	fe::PacketBuilder::debug() const
{
	FE_CONSOLELOG("======DEBUG======");
	FE_CONSOLELOG("size[%u]", packet->size);
	for (fe::type::_32uint i = 0; i < packet->size; ++i)
		FE_CONSOLELOG("data[%u]: decimal:{%d} hexa:{0x{%#02x}}", i, packet->data[i], packet->data[i]);
	FE_CONSOLELOG("======DEBUG======");
}

const unsigned char* fe::PacketBuilder::getData() const
{
	if (packet == nullptr)
		return nullptr;
	if (packet->size == 0)
		return nullptr;
	return packet->data;
}

unsigned int fe::PacketBuilder::getSize() const
{
	if (packet == nullptr)
		return 0;
	return packet->size;
}

void fe::PacketBuilder::writeHeader(fe::type::_32uint sessionID, HANDLER_PACKET_TYPE handlerType)
{
	fe::type::_uchar mark = 0x5e;
	fe::type::_32uint length = packet->size;

	if (handlerType == HANDLER_PACKET_TYPE::LOGIN || handlerType == HANDLER_PACKET_TYPE::CACHE)
	{
		writeFront<fe::type::_32uint>(0xffffffff);
		length = packet->size;
	}

	// session ID
	writeFront<fe::type::_32uint>(sessionID);
	writeFront<fe::type::_32uint>(length);
	writeFront<fe::type::_32uint>(sessionID);
	writeFront<fe::type::_uchar>(mark);
}

bool	fe::PacketBuilder::setPacket(PacketStructure* ps)
{
	if (ps == nullptr)
		return false;
	delete packet;
	packet = ps;
	return true;
}

void	fe::PacketBuilder::writeString(const char* var)
{
	size_t length = ::strlen(var);
	writeString(var, static_cast<fe::type::_32uint>(length));
}

void	fe::PacketBuilder::writeString(const char* var, fe::type::_32uint length)
{
	write<unsigned int>(length);
	packet->data = reinterpret_cast<unsigned char*>(::realloc(packet->data, packet->size + length));
	if (packet->data != nullptr)
	{
#if defined(_WIN64)
		::memcpy_s(packet->data + packet->size, length, var, length);
#elif defined(__APPLE__)
		::memcpy(packet->data + packet->size, var, length);
#endif
		packet->size += length;
	}
}

const char* fe::PacketBuilder::readString()
{
	fe::type::_32uint length = read<fe::type::_32uint>();
	fe::type::_uchar* cur = packet->data + offset;
	char* var = new char[length + 1]();
#if defined(_WIN64)
	::memcpy_s(var, length, cur, length);
#elif defined(__APPLE__)
	::memcpy(var, cur, length);
#endif
	var[length] = '\0';
	offset += length;
	return var;
}

unsigned int	fe::PacketBuilder::getOffset() const
{
	return offset;
}