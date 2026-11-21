#pragma once
// Powers of ten and decibels made from the bits of a float, the way the
// sound engine's code has them inline. Written from the executable.
// Placeholder names.
#include <types.h>

static inline f32 Unk_BitsToFloat(u32 bits) {
    union {
        u32 u;
        f32 f;
    } value;
    value.u = bits;
    return value.f;
}

static inline u32 Unk_FloatToBits(f32 number) {
    union {
        u32 u;
        f32 f;
    } value;
    value.f = number;
    return value.u;
}

// 10 to the power of x: the exponent and the fraction of 2 to the power of
// x * log2(10) are the bits of an integer.
static inline f32 Unk_Pow10Unchecked(f32 x) {
    u32 bits = static_cast<u32>(x * 27866352.6f + 1065353216.0f);
    u32 exponent = bits & 0xff800000;
    f32 fraction = Unk_BitsToFloat((bits & 0x7fffff) | 0x3f800000);
    return ((0.32518977f * fraction + 0.020805772f) * fraction + 0.65304345f) *
           Unk_BitsToFloat(exponent);
}

static inline f32 Unk_Pow10(f32 x) {
    if (x < -37.0f)
        return 0.0f;
    return Unk_Pow10Unchecked(x);
}

// A level from decibels.
static inline f32 Unk_FromDecibels(f32 decibels) {
    return Unk_Pow10(decibels * 0.05f);
}

// Decibels from a level: 20 / ln(10) times its logarithm.
static inline f32 Unk_ToDecibels(f32 level) {
    u32 bits = Unk_FloatToBits(level + 1e-38f);
    f32 fraction = Unk_BitsToFloat((bits & 0x7fffff) | 0x3f800000);
    f32 exponent = static_cast<f32>((bits >> 23) & 0xff) - 127.0f;
    f32 y = (fraction - 1.0f) / (fraction + 1.0f);
    f32 y2 = y * y;
    f32 series = 2.0f * y * (y2 * 0.33333334f + 1.0f);
    f32 log = series + exponent * 0.6931472f;
    return log * 0.4342945f * 20.0f;
}
