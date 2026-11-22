// Scope: common
// SiMath's packed float formats (placeholder file and names): three floats
// as 11, 11 and 10 bits, four floats as half floats.
//
// Neither function matches yet. The original keeps the zero exponent's path
// as it is in the source (exponent and mantissa both set to zero, then packed
// with the same bit insertion as a normal number: `mov w9, wzr; mov w8, wzr;
// bfi w8, w9, #6, #5`) and subtracts the bias before the range tests
// (`subs w9, w10, #0x70; b.lo`). Here clang folds the zero path's packing
// into a constant and rewrites the other one as shifts and a mask. Tried:
// plain shifts and masks (this file), bitfield unions for the float and for
// the results, the biased exponent as its own variable.
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
        if (exponent > 0xef) {
            return 0x7c0;
        }
        mantissa = (bits >> 17) & 0x3f;
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
        if (exponent > 0xef) {
            return 0x3e0;
        }
        mantissa = (bits >> 18) & 0x1f;
    }
    return mantissa | ((biased & 0x1f) << 5);
}

// A float's bits as a half float's.
static inline u16 Unk_PackHalf(u32 bits) {
    u32 sign = (bits >> 16) & 0x8000;
    u32 exponent = (bits >> 23) & 0xff;
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
        if (exponent > 0xef) {
            return 0x7c00;
        }
        mantissa = (bits >> 13) & 0x3ff;
    }
    return sign | mantissa | ((biased & 0x1f) << 10);
}

// 0x7100594d30
// NON_MATCHING: see the top of the file.
void Unk_594d30(u32* dst, const u32* src) {
    u32 r = Unk_Pack11(src[0]);
    u32 g = Unk_Pack11(src[1]);
    u32 b = Unk_Pack10(src[2]);
    *dst = (g << 11) | r | (b << 22);
}

struct Unk_594e80_Half4 {
    u16 field_0[4];
};

// 0x7100594e80
// NON_MATCHING: see the top of the file.
void Unk_594e80(Unk_594e80_Half4* dst, const u32* src) {
    Unk_594e80_Half4 value;
    value.field_0[0] = Unk_PackHalf(src[0]);
    value.field_0[1] = Unk_PackHalf(src[1]);
    value.field_0[2] = Unk_PackHalf(src[2]);
    value.field_0[3] = Unk_PackHalf(src[3]);
    *dst = value;
}
