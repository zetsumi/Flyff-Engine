#pragma once

#include <pch_fnetwork.h>
#include <queue>
#include <mutex>
#include <cstddef>

#include <io/network/emit/packet_structure.hpp>

#pragma warning( disable: 4251 )
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
		std::mutex	locker{};
		unsigned int offset = 0;
		PacketStructure* packet = new PacketStructure();

		template<typename T>
		inline void writeFront(T val)
		{
			unsigned int length = packet->size + sizeof(T);
			unsigned char* tmp = new unsigned char[length]();
#if defined(_WIN64)
			::memcpy_s(tmp, length, &val, sizeof(T));
			::memcpy_s(tmp + sizeof(T), length, packet->data, packet->size);
#elif defined(__APPLE__)
			::memcpy(tmp, &val, sizeof(T));
			::memcpy(tmp + sizeof(T), packet->data, packet->size);
#endif
			delete packet->data;
			packet->data = tmp;
			packet->size = length;
		}

	public:
		PacketBuilder() = default;
		~PacketBuilder();


		[[noreturn]] void					reset(void);
		[[noreturn]] void					debug(void) const;
		[[nodiscard]] const unsigned char*	getData(void) const;
		unsigned int						getSize(void) const;
		[[nodiscard]] bool					setPacket(PacketStructure* ps);
		[[noreturn]] void					writeHeader(fe::type::_32uint sessionID, HANDLER_PACKET_TYPE handlerType);
		[[noreturn]] void					writeString(const char* var);
		[[noreturn]] void					writeString(const char* var, fe::type::_32uint length);
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
#if defined(_WIN64)
				::memcpy_s(packet->data, length, &var, length);
#elif defined(__APPLE__)
				::memcpy(packet->data, &var, length);
#endif
			}
			else
			{
				packet->data = (unsigned char*)::realloc(packet->data, packet->size + length);
				if (packet->data == nullptr)
					return;
#if defined(_WIN64)
				::memcpy_s(packet->data + packet->size, length, &var, length);
#elif defined(__APPLE__)
				::memcpy(packet->data + packet->size, &var, length);
#endif
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

		template<typename T>
		inline PacketBuilder& operator>>(fe::Vector3D<T> v)
		{
			v.x = read<T>();
			v.y = read<T>();
			v.z = read<T>();
			return *this;
		}

		template<typename T>
		inline PacketBuilder& operator>>(T& var)
		{
			var = read<T>();
			return *this;
		}

		template<typename T>
		inline PacketBuilder& operator<<(T& var)
		{
			var = write<T>();
			return *this;
		}

	};
}
#pragma warning( default : 4251 )
