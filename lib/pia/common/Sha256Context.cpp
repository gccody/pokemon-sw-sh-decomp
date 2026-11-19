// Scope: common
// SHA-256 (FIPS 180-4) on ShaBlock512BitContext's buffering.
#include "pia/common/Sha256Context.h"

namespace nn {
namespace pia {
namespace common {

namespace {
const u32 s_K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};

inline u32 RotateRight(u32 x, int n) {
    return (x >> n) | (x << (32 - n));
}
}  // namespace

// 0x7101661000
void Sha256Context::vf0() {
    m_BufferUsed = 0;
    m_BlockCountLow = 0;
    m_BlockCountHigh = 0;
    m_State[0] = 0x6a09e667;
    m_State[1] = 0xbb67ae85;
    m_State[2] = 0x3c6ef372;
    m_State[3] = 0xa54ff53a;
    m_State[4] = 0x510e527f;
    m_State[5] = 0x9b05688c;
    m_State[6] = 0x1f83d9ab;
    m_State[7] = 0x5be0cd19;
}

// 0x7101661060
void Sha256Context::vf1(const void* data, u32 size) {
    Unk_16613e0(data, size);
}

// 0x7101661070
void Sha256Context::vf4(void* digest) {
    Unk_1661360();
    u32* out = static_cast<u32*>(digest);
    for (int i = 0; i < 8; i++) {
        out[i] = __builtin_bswap32(m_State[i]);
    }
}

// 0x7101661100
// NON_MATCHING: the original reloads w[i - 16] in the schedule loop; here it's
// carried from the previous iteration's w[i - 15].
void Sha256Context::vf5() {
    u32 a = m_State[0];
    u32 b = m_State[1];
    u32 c = m_State[2];
    u32 d = m_State[3];
    u32 e = m_State[4];
    u32 f = m_State[5];
    u32 g = m_State[6];
    u32 h = m_State[7];
    u32 w[64];
    const u32* block = reinterpret_cast<const u32*>(m_Buffer);
    for (int i = 0; i < 16; i++) {
        w[i] = __builtin_bswap32(block[i]);
    }
    for (u32 i = 16; i < 64; i++) {
        u32 s0 = RotateRight(w[i - 15], 7) ^ RotateRight(w[i - 15], 18) ^ (w[i - 15] >> 3);
        u32 s1 = RotateRight(w[i - 2], 17) ^ RotateRight(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    for (int i = 0; i < 64; i++) {
        u32 s1 = RotateRight(e, 6) ^ RotateRight(e, 11) ^ RotateRight(e, 25);
        u32 ch = (e & f) | (~e & g);
        u32 t1 = h + s1 + ch + s_K[i] + w[i];
        u32 s0 = RotateRight(a, 2) ^ RotateRight(a, 13) ^ RotateRight(a, 22);
        u32 maj = (a & b) ^ (a & c) ^ (b & c);
        u32 t2 = s0 + maj;
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }
    m_State[0] += a;
    m_State[1] += b;
    m_State[2] += c;
    m_State[3] += d;
    m_State[4] += e;
    m_State[5] += f;
    m_State[6] += g;
    m_State[7] += h;
}

// 0x7101661340
u32 Sha256Context::vf2() {
    return 32;
}

// 0x7101661350
u32 Sha256Context::vf3() {
    return 64;
}

}  // namespace common
}  // namespace pia
}  // namespace nn
