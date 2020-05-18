#include <pch_fnetwork.h>
#include <util/log.hpp>
#include <io/network/emit/packet_builder.hpp>
#include <crypto/crc32.hpp>


void	fe::PacketBuilder::debug(void) const
{
	FE_CONSOLELOG("============");
	FE_CONSOLELOG("size[%u]", packet->size);
	for (unsigned int i = 0; i < packet->size; ++i)
	{
		FE_CONSOLELOG("data[%u] = [%d] = 0x{%#02x}",
			i, packet->data[i], packet->data[i]);
	}
	FE_CONSOLELOG("============");
}

const unsigned char* fe::PacketBuilder::getData(void) const
{
	if (packet == nullptr)
		return nullptr;
	if (packet->size == 0)
		return nullptr;
	return packet->data;
}

unsigned int fe::PacketBuilder::getSize(void) const
{
	if (packet == nullptr)
		return 0;
	return packet->size;
}

void fe::PacketBuilder::setHeader(void)
{
	unsigned char* tmp = nullptr;
	unsigned int destSize = packet->size + sizeof(unsigned int) + sizeof(unsigned char);

	tmp = new unsigned char[destSize]();

	// copy header
	::memcpy_s(tmp, sizeof(unsigned int), (unsigned char*)0x5e, sizeof(unsigned char));
	// copy size
	//fe::crc32Update((const fe::byte*)(&packet->size), sizeof(packet->size));
	::memcpy_s(tmp + sizeof(unsigned char), sizeof(unsigned int) + sizeof(unsigned char), &packet->size, sizeof(unsigned int));
	// data
	::memcpy_s(tmp + sizeof(unsigned int) + sizeof(unsigned char), destSize, packet->data, packet->size);

	delete packet->data;
	packet->data = nullptr;

	packet->size += sizeof(unsigned int);
	packet->data = tmp;
}

void	fe::PacketBuilder::setPacket(PacketStructure* ps)
{
	if (ps != nullptr)
		packet = ps;
}

void	fe::PacketBuilder::writeString(const char* var)
{
	size_t length = ::strlen(var);
	writeString(var, length);
}

void	fe::PacketBuilder::writeString(const char* var, unsigned int length)
{
	write<unsigned int>(length);
	packet->data = (unsigned char*)::realloc(packet->data, packet->size + length);
	if (packet->data == nullptr)
		return;
	::memcpy_s(packet->data + packet->size, length, var, length);
	packet->size += length;
}

const char* fe::PacketBuilder::readString(void)
{
	unsigned int length = read<unsigned int>();
	unsigned char* cur = packet->data + offset;
	char* var = new char[length + 1]();
	::memcpy_s(var, length, cur, length);
	var[length] = '\0';
	offset += length;

	FE_CONSOLELOG("length:[%u] string[%s]", length, var);

	return var;
}

unsigned int	fe::PacketBuilder::getOffset(void) const
{
	return offset;
}