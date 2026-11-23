// Scope: common
// SiMath's packed float formats (placeholder file and names): three floats
// as 11, 11 and 10 bits, four floats as half floats.
//
// The mantissa is extracted before the test for a too large exponent: the
// block that joins the zero exponent's path then ends in a conditional
// branch, InstCombine can't push the packing into the paths, and the zero
// path keeps its own packing of two zeros (`mov w9, wzr; mov w8, wzr; bfi`)
// with the bias subtracted before the range tests (`subs w9, w10, #0x70`).
// The half floats are built in a struct returned by value: its i64
// coercion makes them one 64-bit store (`bfi` x3, `str x8`); the exponent
// is read before the sign (the order of `ubfx` and `and`).
#include <types.h>

// A float's bits as an unsigned float of six mantissa and five exponent bits
// (0 for a negative or too small number, the largest exponent for a too
// large one).
static inline u32 Unk_Pack11(u32 bits) {
    if (static_cast<s32>(bits) < 0) {
        return 0;
    }
    u32 exponent = (bits >> 23) & 0xff;
    u32 biased;
    u32 mantissa;
    if (exponent == 0) {
        biased = 0;
        mantissa = 0;
    } else {
        biased = exponent - 0x70;
        if (exponent < 0x70) {
            return 0;
        }
        mantissa = (bits >> 17) & 0x3f;
        if (exponent > 0xef) {
            return 0x7c0;
        }
    }
    return mantissa | ((biased & 0x1f) << 6);
}

// The same with five mantissa bits.
static inline u32 Unk_Pack10(u32 bits) {
    if (static_cast<s32>(bits) < 0) {
        return 0;
    }
    u32 exponent = (bits >> 23) & 0xff;
    u32 biased;
    u32 mantissa;
    if (exponent == 0) {
        biased = 0;
        mantissa = 0;
    } else {
        biased = exponent - 0x70;
        if (exponent < 0x70) {
            return 0;
        }
        mantissa = (bits >> 18) & 0x1f;
        if (exponent > 0xef) {
            return 0x3e0;
        }
    }
    return mantissa | ((biased & 0x1f) << 5);
}

// A float's bits as a half float's.
static inline u16 Unk_PackHalf(u32 bits) {
    u32 exponent = (bits >> 23) & 0xff;
    u32 sign = (bits >> 16) & 0x8000;
    u32 biased;
    u32 mantissa;
    if (exponent == 0) {
        biased = 0;
        mantissa = 0;
    } else {
        biased = exponent - 0x70;
        if (exponent < 0x70) {
            return sign;
        }
        mantissa = (bits >> 13) & 0x3ff;
        if (exponent > 0xef) {
            return 0x7c00;
        }
    }
    return sign | mantissa | ((biased & 0x1f) << 10);
}

// 0x7100594d30
void Unk_594d30(u32* dst, const u32* src) {
    u32 r = Unk_Pack11(src[0]);
    u32 g = Unk_Pack11(src[1]);
    u32 b = Unk_Pack10(src[2]);
    *dst = (g << 11) | r | (b << 22);
}

struct Unk_594e80_Half4 {
    u16 field_0[4];
};

// Four floats' bits as half floats.
static inline Unk_594e80_Half4 Unk_MakeHalf4(const u32* src) {
    Unk_594e80_Half4 value;
    value.field_0[0] = Unk_PackHalf(src[0]);
    value.field_0[1] = Unk_PackHalf(src[1]);
    value.field_0[2] = Unk_PackHalf(src[2]);
    value.field_0[3] = Unk_PackHalf(src[3]);
    return value;
}

// 0x7100594e80
void Unk_594e80(Unk_594e80_Half4* dst, const u32* src) {
    *dst = Unk_MakeHalf4(src);
}
