#pragma once

namespace fe
{
    typedef uint32_t word32;
    typedef unsigned char byte;
    constexpr word32 CRC32_NEGL = 0xffffffffL;

    //template <class T>
    //inline bool IsPowerOf2(T n)
    //{
    //	return n > 0 && (n & (n - 1)) == 0;
    //}

    //template <class T1, class T2>
    //inline T2 ModPowerOf2(T1 a, T2 b)
    //{
    //	return T2(a) & (b - 1);
    //}

    //bool IsAlignedOn(const void* p, uint32_t alignment)
    //{
    //	return IsPowerOf2(alignment) ? ModPowerOf2((uint32_t)p, alignment) == 0 : (uint32_t)p % alignment == 0;
    //}

    //template <class T>
    //inline uint32_t GetAlignment(T* dummy = NULL)
    //{
    //	return __alignof(T);
    //}

    //template <class T>
    //inline bool IsAligned(const void* p, T* dummy = NULL)
    //{
    //	return IsAlignedOn(p, GetAlignment<T>());
    //}

    void encryptCrc32(const fe::byte* s, uint32_t n);
}

#define CRC32_INDEX(c) (c & 0xff)
#define CRC32_SHIFTED(c) (c >> 8)
