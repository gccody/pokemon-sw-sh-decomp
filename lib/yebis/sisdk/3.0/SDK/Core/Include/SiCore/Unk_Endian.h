// SiSDK3's byte swaps, as the streams' code shows them (placeholder names):
// the 32-bit one swaps its halves in place with the 16-bit one, the 64-bit one
// with the 32-bit one (the instructions keep that shape: two `rev` of the
// halves instead of one of the whole).
#pragma once

#include <types.h>

namespace SiSDK3 {

inline u16 Unk_Swap16(u16 value) {
    return static_cast<u16>((value << 8) | (value >> 8));
}
inline u32 Unk_Swap32(u32 value) {
    u16* p = reinterpret_cast<u16*>(&value);
    u16 t = Unk_Swap16(p[0]);
    p[0] = Unk_Swap16(p[1]);
    p[1] = t;
    return value;
}
inline u64 Unk_Swap64(u64 value) {
    u32* p = reinterpret_cast<u32*>(&value);
    u32 t = Unk_Swap32(p[0]);
    p[0] = Unk_Swap32(p[1]);
    p[1] = t;
    return value;
}
inline float Unk_SwapFloat(float value) {
    union {
        float f;
        u32 u;
    } v;
    v.f = value;
    v.u = Unk_Swap32(v.u);
    return v.f;
}
inline double Unk_SwapDouble(double value) {
    union {
        double f;
        u64 u;
    } v;
    v.f = value;
    v.u = Unk_Swap64(v.u);
    return v.f;
}

}  // namespace SiSDK3
