#pragma once

#include <pch_fnetwork.h>
#include <queue>
#include <mutex>
#include <cstddef>

#include <io/network/emit/packet_structure.hpp>

namespace fe
{
	enum class HANDLER_PACKET_TYPE : unsigned short
	{
		UNKNOW,
		CERTIFIER,
		LOGIN,
		CACHE
	};

	class API_DECLSPEC PacketBuilder
	{
		std::mutex	locker;
		unsigned int offset = 0;
		PacketStructure* packet = new PacketStructure();

		template<typename T>
		inline void writeFront(T val)
		{
			unsigned int length = packet->size + sizeof(T);
			unsigned char* tmp = new unsigned char[length]();
			::memcpy_s(tmp, length, &val, sizeof(T));
			::memcpy_s(tmp + sizeof(T), length, packet->data, packet->size);
			delete packet->data;
			packet->data = nullptr;
			packet->data = tmp;

			packet->size = length;
		}

	public:
		PacketBuilder() = default;
		~PacketBuilder() = default;

		[[noreturn]] void					reset(void);
		[[noreturn]] void					debug(void) const;
		[[nodiscard]] const unsigned char*	getData(void) const;
		unsigned int						getSize(void) const;
		[[nodiscard]] bool					setPacket(PacketStructure* ps);
		[[noreturn]] void					writeHeader(fe::type::_32uint sessionID, HANDLER_PACKET_TYPE handlerType);
		[[noreturn]] void					writeString(const char* var);
		[[noreturn]] void					writeString(const char* var, unsigned int length);
		[[nodiscard]] const char*			readString(void);
		unsigned int						getOffset(void) const;

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

