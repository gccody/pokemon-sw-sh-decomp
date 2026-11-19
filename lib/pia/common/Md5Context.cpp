// Scope: common
// MD5 (RFC 1321) over a 64-byte block buffer.
#include "pia/common/Md5Context.h"

#include <string.h>

namespace nn {
namespace pia {
namespace common {

namespace {
const u8 s_Padding = 0x80;
}

#define MD5_F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | ~(z)))
#define MD5_ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define MD5_STEP(f, a, b, c, d, x, s, ac) \
    (a) += f((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = MD5_ROTL((a), (s));                  \
    (a) += (b)

// 0x710165ca40
// NON_MATCHING: the order of the additions in each step (clang's reassociation
// ranks: the original adds F to a before x[i]), so the registers differ.
void Md5Context::vf5() {
    u32 a = m_State[0];
    u32 b = m_State[1];
    u32 c = m_State[2];
    u32 d = m_State[3];
    const u32* x = reinterpret_cast<const u32*>(m_Buffer);

    MD5_STEP(MD5_F, a, b, c, d, x[0], 7, 0xd76aa478);
    MD5_STEP(MD5_F, d, a, b, c, x[1], 12, 0xe8c7b756);
    MD5_STEP(MD5_F, c, d, a, b, x[2], 17, 0x242070db);
    MD5_STEP(MD5_F, b, c, d, a, x[3], 22, 0xc1bdceee);
    MD5_STEP(MD5_F, a, b, c, d, x[4], 7, 0xf57c0faf);
    MD5_STEP(MD5_F, d, a, b, c, x[5], 12, 0x4787c62a);
    MD5_STEP(MD5_F, c, d, a, b, x[6], 17, 0xa8304613);
    MD5_STEP(MD5_F, b, c, d, a, x[7], 22, 0xfd469501);
    MD5_STEP(MD5_F, a, b, c, d, x[8], 7, 0x698098d8);
    MD5_STEP(MD5_F, d, a, b, c, x[9], 12, 0x8b44f7af);
    MD5_STEP(MD5_F, c, d, a, b, x[10], 17, 0xffff5bb1);
    MD5_STEP(MD5_F, b, c, d, a, x[11], 22, 0x895cd7be);
    MD5_STEP(MD5_F, a, b, c, d, x[12], 7, 0x6b901122);
    MD5_STEP(MD5_F, d, a, b, c, x[13], 12, 0xfd987193);
    MD5_STEP(MD5_F, c, d, a, b, x[14], 17, 0xa679438e);
    MD5_STEP(MD5_F, b, c, d, a, x[15], 22, 0x49b40821);

    MD5_STEP(MD5_G, a, b, c, d, x[1], 5, 0xf61e2562);
    MD5_STEP(MD5_G, d, a, b, c, x[6], 9, 0xc040b340);
    MD5_STEP(MD5_G, c, d, a, b, x[11], 14, 0x265e5a51);
    MD5_STEP(MD5_G, b, c, d, a, x[0], 20, 0xe9b6c7aa);
    MD5_STEP(MD5_G, a, b, c, d, x[5], 5, 0xd62f105d);
    MD5_STEP(MD5_G, d, a, b, c, x[10], 9, 0x02441453);
    MD5_STEP(MD5_G, c, d, a, b, x[15], 14, 0xd8a1e681);
    MD5_STEP(MD5_G, b, c, d, a, x[4], 20, 0xe7d3fbc8);
    MD5_STEP(MD5_G, a, b, c, d, x[9], 5, 0x21e1cde6);
    MD5_STEP(MD5_G, d, a, b, c, x[14], 9, 0xc33707d6);
    MD5_STEP(MD5_G, c, d, a, b, x[3], 14, 0xf4d50d87);
    MD5_STEP(MD5_G, b, c, d, a, x[8], 20, 0x455a14ed);
    MD5_STEP(MD5_G, a, b, c, d, x[13], 5, 0xa9e3e905);
    MD5_STEP(MD5_G, d, a, b, c, x[2], 9, 0xfcefa3f8);
    MD5_STEP(MD5_G, c, d, a, b, x[7], 14, 0x676f02d9);
    MD5_STEP(MD5_G, b, c, d, a, x[12], 20, 0x8d2a4c8a);

    MD5_STEP(MD5_H, a, b, c, d, x[5], 4, 0xfffa3942);
    MD5_STEP(MD5_H, d, a, b, c, x[8], 11, 0x8771f681);
    MD5_STEP(MD5_H, c, d, a, b, x[11], 16, 0x6d9d6122);
    MD5_STEP(MD5_H, b, c, d, a, x[14], 23, 0xfde5380c);
    MD5_STEP(MD5_H, a, b, c, d, x[1], 4, 0xa4beea44);
    MD5_STEP(MD5_H, d, a, b, c, x[4], 11, 0x4bdecfa9);
    MD5_STEP(MD5_H, c, d, a, b, x[7], 16, 0xf6bb4b60);
    MD5_STEP(MD5_H, b, c, d, a, x[10], 23, 0xbebfbc70);
    MD5_STEP(MD5_H, a, b, c, d, x[13], 4, 0x289b7ec6);
    MD5_STEP(MD5_H, d, a, b, c, x[0], 11, 0xeaa127fa);
    MD5_STEP(MD5_H, c, d, a, b, x[3], 16, 0xd4ef3085);
    MD5_STEP(MD5_H, b, c, d, a, x[6], 23, 0x04881d05);
    MD5_STEP(MD5_H, a, b, c, d, x[9], 4, 0xd9d4d039);
    MD5_STEP(MD5_H, d, a, b, c, x[12], 11, 0xe6db99e5);
    MD5_STEP(MD5_H, c, d, a, b, x[15], 16, 0x1fa27cf8);
    MD5_STEP(MD5_H, b, c, d, a, x[2], 23, 0xc4ac5665);

    MD5_STEP(MD5_I, a, b, c, d, x[0], 6, 0xf4292244);
    MD5_STEP(MD5_I, d, a, b, c, x[7], 10, 0x432aff97);
    MD5_STEP(MD5_I, c, d, a, b, x[14], 15, 0xab9423a7);
    MD5_STEP(MD5_I, b, c, d, a, x[5], 21, 0xfc93a039);
    MD5_STEP(MD5_I, a, b, c, d, x[12], 6, 0x655b59c3);
    MD5_STEP(MD5_I, d, a, b, c, x[3], 10, 0x8f0ccc92);
    MD5_STEP(MD5_I, c, d, a, b, x[10], 15, 0xffeff47d);
    MD5_STEP(MD5_I, b, c, d, a, x[1], 21, 0x85845dd1);
    MD5_STEP(MD5_I, a, b, c, d, x[8], 6, 0x6fa87e4f);
    MD5_STEP(MD5_I, d, a, b, c, x[15], 10, 0xfe2ce6e0);
    MD5_STEP(MD5_I, c, d, a, b, x[6], 15, 0xa3014314);
    MD5_STEP(MD5_I, b, c, d, a, x[13], 21, 0x4e0811a1);
    MD5_STEP(MD5_I, a, b, c, d, x[4], 6, 0xf7537e82);
    MD5_STEP(MD5_I, d, a, b, c, x[11], 10, 0xbd3af235);
    MD5_STEP(MD5_I, c, d, a, b, x[2], 15, 0x2ad7d2bb);
    MD5_STEP(MD5_I, b, c, d, a, x[9], 21, 0xeb86d391);

    m_State[0] += a;
    m_State[1] += b;
    m_State[2] += c;
    m_State[3] += d;

}

// 0x710165d420
void Md5Context::vf0() {
    m_State[0] = 0x67452301;
    m_State[1] = 0xefcdab89;
    m_State[2] = 0x98badcfe;
    m_State[3] = 0x10325476;
    m_Count = 0;
}

// 0x710165d450
// NON_MATCHING: the block loop's counter (the original counts a 64-bit value
// down from blocks + 1) and the registers around it.
void Md5Context::vf1(const void* data, u32 size) {
    const u8* p = static_cast<const u8*>(data);
    u32 index = m_Count % 64;
    m_Count += size;
    u32 rest = 64 - index;
    if (size < rest) {
        if (size > 0) {
            memcpy(&m_Buffer[index], p, size);
        }
    } else {
        memcpy(&m_Buffer[index], p, rest);
        vf5();
        p += rest;
        size -= rest;
        s32 blocks = size / 64;
        for (s32 i = 0; i < blocks; i++) {
            memcpy(m_Buffer, p + i * 64, 64);
            vf5();
        }
        p += blocks * 64;
        size %= 64;
        if (size > 0) {
            memcpy(m_Buffer, p, size);
        }
    }
}

// 0x710165d560
// NON_MATCHING: the original keeps m_Buffer's address in x22 across the first
// block's memset and vf5.
void Md5Context::vf4(void* digest) {
    u64 bits = m_Count << 3;
    vf1(&s_Padding, 1);
    u32 index = m_Count % 64;
    u32 rest = 64 - index;
    u32 zeros;
    if (rest < 8) {
        memset(m_Buffer + index, 0, rest);
        vf5();
        index = 0;
        zeros = 56;
    } else {
        zeros = rest - 8;
    }
    if (zeros > 0) {
        memset(m_Buffer + index, 0, zeros);
    }
    *reinterpret_cast<u64*>(&m_Buffer[56]) = bits;
    vf5();
    u32* out = static_cast<u32*>(digest);
    out[0] = m_State[0];
    out[1] = m_State[1];
    out[2] = m_State[2];
    out[3] = m_State[3];
}

// 0x710165d640
u32 Md5Context::vf2() {
    return 16;
}

// 0x710165d650
u32 Md5Context::vf3() {
    return 64;
}

}  // namespace common
}  // namespace pia
}  // namespace nn
