#pragma once

namespace fe
{
	typedef unsigned int word32;
	typedef unsigned char byte;
	constexpr word32 CRC32_NEGL = 0xffffffffL;

	template <class T>
	inline bool IsPowerOf2(T n)
	{
		return n > 0 && (n & (n - 1)) == 0;
	}

	template <class T1, class T2>
	inline T2 ModPowerOf2(T1 a, T2 b)
	{
		return T2(a) & (b - 1);
	}

	inline bool IsAlignedOn(const void* p, unsigned int alignment)
	{
		return IsPowerOf2(alignment) ? ModPowerOf2((unsigned int)p, alignment) == 0 : (unsigned int)p % alignment == 0;
	}

	template <class T>
	inline unsigned int GetAlignment(T* dummy = NULL)
	{
		return __alignof(T);
	}

	template <class T>
	inline bool IsAligned(const void* p, T* dummy = NULL)
	{
		return IsAlignedOn(p, GetAlignment<T>());
	}

	void crc32Update(const fe::byte* s, unsigned int n);
}

#define CRC32_INDEX(c) (c & 0xff)
#define CRC32_SHIFTED(c) (c >> 8)
