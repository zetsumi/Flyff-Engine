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
		void writeFront(T val)
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


		void					reset();
		void					debug() const;
		const unsigned char*	getData() const;
		unsigned int						getSize() const;
		[[nodiscard]] bool					setPacket(PacketStructure* ps);
		void					writeHeader(uint32_t sessionID, HANDLER_PACKET_TYPE handlerType);
		void					writeString(const char* var);
		void					writeString(const char* var, uint32_t length);
		[[nodiscard]] const char*			readString();
		unsigned int						getOffset() const;

		template<typename T>
		void	write(T var)
		{
			unsigned int length = sizeof(T);
			write<T>(var, length);
		}

		template<typename T>
		void	write(T var, unsigned int length)
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
		T	read()
		{
			unsigned int size = sizeof(T);
			T var;
			unsigned char* cur = packet->data + offset;
			::memcpy(&var, cur, size);
			offset += size;
			return var;
		}

		template<typename T>
		PacketBuilder& operator>>(fe::util::Vector3D<T> v)
		{
			v.x = read<T>();
			v.y = read<T>();
			v.z = read<T>();
			return *this;
		}

		template<typename T>
		PacketBuilder& operator>>(T& var)
		{
			var = read<T>();
			return *this;
		}

		template<typename T>
		PacketBuilder& operator<<(T& var)
		{
			var = write<T>();
			return *this;
		}

	};
}
#pragma warning( default : 4251 )
