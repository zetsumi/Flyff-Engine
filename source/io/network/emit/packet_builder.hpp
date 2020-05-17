#pragma once

#include <pch_fnetwork.h>
#include <queue>
#include <mutex>
#include <cstddef>

#include <io/network/emit/packet_structure.hpp>

namespace fe
{
	class API_DECLSPEC PacketBuilder
	{
		std::mutex	locker;
		unsigned int offset = 0;
		PacketStructure* packet = new PacketStructure();

	public:
		PacketBuilder() = default;
		~PacketBuilder() = default;

		void					debug(void) const;
		const unsigned char* getData(bool builder = true) const;
		unsigned int			getSize(void) const;
		void					setPacket(PacketStructure* ps);
		void					writeString(const char* var);
		void					writeString(const char* var, unsigned int length);
		const char* readString(void);
		unsigned int			getOffset(void) const;

		template<typename T>
		inline void	write(T var)
		{
			unsigned int length = sizeof(T);
			write<T>(var, length);
		}

		template<typename T>
		inline void	write(T var, unsigned int length)
		{
			if (packet->data == nullptr)
			{
				packet->data = new unsigned char[length]();
				::memcpy_s(packet->data, length, &var, length);
			}
			else
			{
				packet->data = (unsigned char*)::realloc(packet->data, packet->size + length);
				if (packet->data == nullptr)
					return;
				::memcpy_s(packet->data + packet->size, length, &var, length);
			}
			packet->size += length;
		}

		template<typename T>
		inline T	read(void)
		{
			unsigned int size = sizeof(T);
			T var;
			unsigned char* cur = packet->data + offset;
			::memcpy(&var, cur, size);
			offset += size;
			return var;
		}
	};
}

