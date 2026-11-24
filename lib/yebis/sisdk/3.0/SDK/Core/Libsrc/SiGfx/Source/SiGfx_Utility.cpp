// Scope: common
// SiGfx_Utility.cpp (its allocations' __FILE__): functions on SiGfx's numbers
// (placeholder names): the names of its graphics interfaces and shader
// languages, what a pixel format's number says about it (its bits, its
// blocks' bytes, whether it is compressed), how many mip levels a size has,
// the image flips and the binary shader cache's file names. The original
// compiled the switches to lookup tables and bit masks; the cases here are
// those tables' entries.
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <types.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiMath/Unk_Matrix.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/NX/Unk_NXResource.h>
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/SiGfx_ShaderUtility_Impl.h>

SiSDK3::ISiAllocator* Unk_4bc640();
SiSDK3::ISiAllocator* Unk_4bc690();

static const char* const Unk_23912d8[] = {
    "Unknown", "Null", "OGL", "OGLES3", "D3D11", "D3D12", "PS4", "Vulkan", "NX",
};

static const char* const Unk_2391320[] = {
    "Unknown", "Cg", "GLSL", "HLSL", "PSSL", "NX",
};

// 0x71004ed060
const char* Unk_4ed060(u32 index) {
    return Unk_23912d8[index];
}

// 0x71004ed070
const char* Unk_4ed070(u32 index) {
    return Unk_2391320[index];
}

// 0x71004ed080
u32 Unk_4ed080(u32 value) {
    switch (value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return value;
    default:
        return 0;
    }
}

// 0x71004ed090: a format's bits per pixel (0 for the compressed ones)
s32 Unk_4ed090(u32 format) {
    switch (format) {
    case 1:
    case 2:
    case 3:
    case 4:
        return 128;
    case 5:
    case 6:
    case 7:
    case 8:
        return 96;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        return 64;
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
        return 32;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
        return 16;
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
        return 8;
    case 66:
        return 1;
    case 67:
    case 68:
    case 69:
        return 32;
    case 85:
    case 86:
        return 16;
    case 87:
    case 88:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
        return 32;
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
        return 0;
    default:
        return 0;
    }
}

// 0x71004ed0c0: a format's bytes per pixel
s32 Unk_4ed0c0(u32 format) {
    return (Unk_4ed090(format) + 7) / 8;
}

// 0x71004ed0f0: a compressed format's bytes per block
s32 Unk_4ed0f0(u32 format) {
    switch (format) {
    case 70:
    case 71:
    case 72:
        return 8;
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
        return 16;
    case 79:
    case 80:
    case 81:
        return 8;
    case 82:
    case 83:
    case 84:
        return 16;
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
        return 16;
    case 101:
    case 102:
    case 103:
    case 104:
        return 8;
    default:
        return 0;
    }
}

// 0x71004ed120
bool Unk_4ed120(u32 format) {
    switch (format) {
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
        return true;
    default:
        return false;
    }
}

// 0x71004ed150
bool Unk_4ed150(u32 format) {
    switch (format) {
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
        return true;
    default:
        return false;
    }
}

// 0x71004ed180
s32 Unk_4ed180(s32 samples) {
    return samples < 2 ? 0 : samples;
}

// 0x71004ed190
bool Unk_4ed190(u32 format) {
    switch (format) {
    case 44:
    case 45:
        return true;
    default:
        return false;
    }
}

// 0x71004ed1a0: how many times a size halves before it is under the smallest
// (if there is one) or nothing
s32 Unk_4ed1a0(s32 size, s32 minSize) {
    s32 n = 0;
    if (size == 0) {
        return 0;
    }
    while (size > 0) {
        size >>= 1;
        n++;
        if (minSize > 0 && size < minSize) {
            break;
        }
    }
    return n;
}

// 0x71004ed200: the same for a width and a height. The two are halved in
// locals, declared in this order: the order decides which of them the loop
// tests first.
s32 Unk_4ed200(s32 width, s32 height, s32 minWidth, s32 minHeight) {
    if (width == 0 || height == 0) {
        return 0;
    }
    s32 n = 0;
    s32 w = width;
    s32 h = height;
    while (w > 0 || h > 0) {
        w >>= 1;
        h >>= 1;
        n++;
        if (minWidth > 0 && w < minWidth) {
            break;
        }
        if (minHeight > 0 && h < minHeight) {
            break;
        }
    }
    return n;
}

// 0x71004ed300: the same for a width, a height and a depth
s32 Unk_4ed300(s32 width, s32 height, s32 depth, s32 minWidth, s32 minHeight, s32 minDepth) {
    if (width == 0 || height == 0) {
        return 0;
    }
    s32 n = 0;
    s32 w = width;
    s32 h = height;
    s32 d = depth;
    while (w > 0 || h > 0 || d > 0) {
        w >>= 1;
        h >>= 1;
        d >>= 1;
        n++;
        if (minWidth > 0 && w < minWidth) {
            break;
        }
        if (minHeight > 0 && h < minHeight) {
            break;
        }
        if (minDepth > 0 && d < minDepth) {
            break;
        }
    }
    return n;
}

// 0x71004ed4f0: writes a colour (four floats) as a pixel of a format, and
// returns how many components it wrote (0 for the formats it doesn't know)
s32 Unk_4ed4f0(u32 format, void* pPixel, const f32* pColor) {
    u8* pBytes = static_cast<u8*>(pPixel);
    f32* pFloats = static_cast<f32*>(pPixel);
    switch (format) {
    case 61:
    case 65:
        pBytes[0] = static_cast<u8>(pColor[0] * 255.0f);
        return 1;
    case 87:
        pBytes[0] = static_cast<u8>(pColor[2] * 255.0f);
        pBytes[1] = static_cast<u8>(pColor[1] * 255.0f);
        pBytes[2] = static_cast<u8>(pColor[0] * 255.0f);
        pBytes[3] = static_cast<u8>(pColor[3] * 255.0f);
        return 4;
    case 2:
        pFloats[0] = pColor[0];
        pFloats[1] = pColor[1];
        pFloats[2] = pColor[2];
        pFloats[3] = pColor[3];
        return 4;
    case 6:
        pFloats[0] = pColor[0];
        pFloats[1] = pColor[1];
        pFloats[2] = pColor[2];
        return 3;
    case 16:
        pFloats[0] = pColor[0];
        pFloats[1] = pColor[1];
        return 2;
    case 28:
        pBytes[0] = static_cast<u8>(pColor[0] * 255.0f);
        pBytes[1] = static_cast<u8>(pColor[1] * 255.0f);
        pBytes[2] = static_cast<u8>(pColor[2] * 255.0f);
        pBytes[3] = static_cast<u8>(pColor[3] * 255.0f);
        return 4;
    case 41:
        pFloats[0] = pColor[0];
        return 1;
    }
    return 0;
}

// 0x71004ed630
u32 Unk_4ed630(u32 format, u32 index) {
    switch (format) {
    case 28:
    case 31:
    case 32:
        switch (index) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        }
        break;
    case 87:
        switch (index) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 3;
        }
        break;
    }
    return 1;
}

// 0x71004ed680
s32 Unk_4ed680(u32 format, u32 index) {
    switch (format) {
    case 28:
    case 31:
    case 32:
        switch (index) {
        case 0:
        case 1:
        case 2:
        case 3:
            return 1;
        }
        break;
    case 87:
        switch (index) {
        case 0:
        case 1:
        case 2:
        case 3:
            return 1;
        }
        break;
    }
    return -1;
}

// 0x71004ed6e0
bool Unk_4ed6e0(u32 format) {
    switch (format) {
    case 29:
    case 72:
    case 75:
    case 78:
    case 91:
    case 93:
    case 99:
        return true;
    default:
        return false;
    }
}

// What 0x71004ed720 is given (placeholder names): a draw context, whose slot
// 5 is its device.
class Unk_4ed720_Device {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};
class Unk_4ed720_Context {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual Unk_4ed720_Device* vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
};
// What it returns (placeholder): a pointer, returned in memory (so it isn't
// trivially copied).
struct Unk_4ed720_Result {
    Unk_4ed720_Result() : field_0(nullptr) {}
    Unk_4ed720_Result(const Unk_4ed720_Result& other);

    void* field_0;
};

// 0x71004ed720
Unk_4ed720_Result Unk_4ed720(Unk_4ed720_Context* context) {
    if (context != nullptr) {
        context->vf5()->vf14();
        context->vf19();
        context->vf19();
    }
    return Unk_4ed720_Result();
}

// 0x71004ed780: writes a primitive's indices (16 or 32 bits each) into an
// index buffer: at twice or three times the primitive's number for the list
// kinds (2 and 4), at the number itself for the strip kinds (3 and 5). The
// cases are in this order: the last one's 16 bit half shares its return with
// the kinds that write nothing.
void Unk_4ed780(u32 kind, bool is32, void* pIndices, s32 index, u32 a, u32 b, u32 c) {
    u16* p16 = static_cast<u16*>(pIndices);
    u32* p32 = static_cast<u32*>(pIndices);
    switch (kind) {
    case 2:
        if (is32) {
            p32[index * 2] = a;
            p32[index * 2 + 1] = b;
        } else {
            p16[index * 2] = a;
            p16[index * 2 + 1] = b;
        }
        break;
    case 4:
        if (is32) {
            p32[index * 3] = a;
            p32[index * 3 + 1] = b;
            p32[index * 3 + 2] = c;
        } else {
            p16[index * 3] = a;
            p16[index * 3 + 1] = b;
            p16[index * 3 + 2] = c;
        }
        break;
    case 3:
        if (is32) {
            p32[index] = a;
            p32[index + 1] = b;
        } else {
            p16[index] = a;
            p16[index + 1] = b;
        }
        break;
    case 5:
        if (is32) {
            p32[index] = a;
            p32[index + 1] = b;
            p32[index + 2] = c;
        } else {
            p16[index] = a;
            p16[index + 1] = b;
            p16[index + 2] = c;
        }
        break;
    }
}

// SiMath's packers (Unk_594d30.cpp): three floats as 11, 11 and 10 bit
// floats, four as half floats
struct Unk_594e80_Half4 {
    u16 field_0[4];
};
void Unk_594d30(u32* dst, const u32* src);
void Unk_594e80(Unk_594e80_Half4* dst, const u32* src);

// A float's bits as a half float's (inline here; SiMath's translation unit
// has the same code).
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
        mantissa = (bits >> 13) & 0x3ff;
        if (exponent < 0x70) {
            return sign;
        }
        if (exponent > 0xef) {
            return 0x7c00;
        }
    }
    return sign | mantissa | ((biased & 0x1f) << 10);
}

// Three floats copied together (placeholder name).
struct Unk_Float3 {
    f32 field_0[3];
};

// NON_MATCHING: the original's size; three differences. The half floats
// (formats 34 and 54): the original subtracts the bias in the block of the
// first range test (`subs w9, w11, #0x70; b.lo`), where this subtracts it
// after the second (`cmp #0x6f; b.ls`: InstCombine sinks the subtraction to
// the block that uses it; the exponent read before the sign and the
// mantissa before the tests give the rest of the original's code). The blocks of
// formats 61/65 and 62/64 are laid out the other way round (which one falls
// into their shared conversion). Format 26 stores the copy's two words in
// the other order. The case groups are in the original's layout (they come
// first: twice as likely as the single cases).
// Also tried (half floats, 50 forms): s32 or u32 exponent and bias, the
// tests on the bias (`biased < 0`, `biased > 0x7f`) or the exponent, the bias
// unmasked (only `biased <= 0`, which isn't the same function, gives the
// original's `subs`).
// 0x71004ed850: writes a colour (four floats) as a pixel of a format (the
// formats are DXGI's numbers), false for the formats it doesn't know
bool Unk_4ed850(u32 format, void* pPixel, const f32* pColor) {
    u8* p8 = static_cast<u8*>(pPixel);
    u16* p16 = static_cast<u16*>(pPixel);
    u32* p32 = static_cast<u32*>(pPixel);
    const u32* pBits = reinterpret_cast<const u32*>(pColor);
    switch (format) {
    case 2:
        p32[0] = pBits[0];
        p32[1] = pBits[1];
        p32[2] = pBits[2];
        p32[3] = pBits[3];
        break;
    case 3:
        p32[0] = static_cast<u32>(pColor[0]);
        p32[1] = static_cast<u32>(pColor[1]);
        p32[2] = static_cast<u32>(pColor[2]);
        p32[3] = static_cast<u32>(pColor[3]);
        break;
    case 4:
        p32[0] = static_cast<s32>(pColor[0]);
        p32[1] = static_cast<s32>(pColor[1]);
        p32[2] = static_cast<s32>(pColor[2]);
        p32[3] = static_cast<s32>(pColor[3]);
        break;
    case 6:
        p32[0] = pBits[0];
        p32[1] = pBits[1];
        p32[2] = pBits[2];
        break;
    case 7:
        p32[0] = static_cast<u32>(pColor[0]);
        p32[1] = static_cast<u32>(pColor[1]);
        p32[2] = static_cast<u32>(pColor[2]);
        break;
    case 8:
        p32[0] = static_cast<s32>(pColor[0]);
        p32[1] = static_cast<s32>(pColor[1]);
        p32[2] = static_cast<s32>(pColor[2]);
        break;
    case 10: {
        Unk_594e80_Half4 value;
        Unk_594e80(&value, pBits);
        *static_cast<Unk_594e80_Half4*>(pPixel) = value;
        break;
    }
    case 11:
        p16[0] = static_cast<u16>(pColor[0] * 65535.0f);
        p16[1] = static_cast<u16>(pColor[1] * 65535.0f);
        p16[2] = static_cast<u16>(pColor[2] * 65535.0f);
        p16[3] = static_cast<u16>(pColor[3] * 65535.0f);
        break;
    case 12:
    case 14:
        p16[0] = static_cast<u16>(pColor[0]);
        p16[1] = static_cast<u16>(pColor[1]);
        p16[2] = static_cast<u16>(pColor[2]);
        p16[3] = static_cast<u16>(pColor[3]);
        break;
    case 13:
        p16[0] = static_cast<s16>(pColor[0] * 32767.5f);
        p16[1] = static_cast<s16>(pColor[1] * 32767.5f);
        p16[2] = static_cast<s16>(pColor[2] * 32767.5f);
        p16[3] = static_cast<s16>(pColor[3] * 32767.5f);
        break;
    case 16:
        p32[0] = pBits[0];
        p32[1] = pBits[1];
        break;
    case 17:
        p32[0] = static_cast<u32>(pColor[0]);
        p32[1] = static_cast<u32>(pColor[1]);
        break;
    case 18:
        p32[0] = static_cast<s32>(pColor[0]);
        p32[1] = static_cast<s32>(pColor[1]);
        break;
    case 24: {
        u32 r = static_cast<u32>(pColor[0] / 1023.0f);
        u32 g = static_cast<u32>(pColor[1] / 1023.0f);
        u32 b = static_cast<u32>(pColor[2] / 1023.0f);
        u32 a = static_cast<u32>(pColor[3] / 3.0f);
        p32[0] = r + (g << 10) + (b << 20) + (a << 30);
        break;
    }
    case 25: {
        u32 r = static_cast<u32>(pColor[0]);
        u32 g = static_cast<u32>(pColor[1]);
        u32 b = static_cast<u32>(pColor[2]);
        u32 a = static_cast<u32>(pColor[3]);
        p32[0] = r + (g << 10) + (b << 20) + (a << 30);
        break;
    }
    case 26: {
        Unk_Float3 rgb = *reinterpret_cast<const Unk_Float3*>(pColor);
        u32 value;
        Unk_594d30(&value, reinterpret_cast<const u32*>(&rgb));
        p32[0] = value;
        break;
    }
    case 28:
    case 29:
        p8[0] = static_cast<u8>(pColor[0] * 255.0f);
        p8[1] = static_cast<u8>(pColor[1] * 255.0f);
        p8[2] = static_cast<u8>(pColor[2] * 255.0f);
        p8[3] = static_cast<u8>(pColor[3] * 255.0f);
        break;
    case 30:
    case 32:
        p8[0] = static_cast<u8>(pColor[0]);
        p8[1] = static_cast<u8>(pColor[1]);
        p8[2] = static_cast<u8>(pColor[2]);
        p8[3] = static_cast<u8>(pColor[3]);
        break;
    case 31:
        p8[0] = static_cast<s8>(pColor[0] * 127.0f);
        p8[1] = static_cast<s8>(pColor[1] * 127.0f);
        p8[2] = static_cast<s8>(pColor[2] * 127.0f);
        p8[3] = static_cast<s8>(pColor[3] * 127.0f);
        break;
    case 34:
        p16[0] = Unk_PackHalf(pBits[0]);
        p16[1] = Unk_PackHalf(pBits[1]);
        break;
    case 35:
        p16[0] = static_cast<u16>(pColor[0] * 65535.0f);
        p16[1] = static_cast<u16>(pColor[1] * 65535.0f);
        break;
    case 36:
    case 38:
        p16[0] = static_cast<u16>(pColor[0]);
        p16[1] = static_cast<u16>(pColor[1]);
        break;
    case 37:
        p16[0] = static_cast<s16>(pColor[0] * 32767.5f);
        p16[1] = static_cast<s16>(pColor[1] * 32767.5f);
        break;
    case 40:
    case 41:
        p32[0] = pBits[0];
        break;
    case 42:
        p32[0] = static_cast<u32>(pColor[0]);
        break;
    case 43:
        p32[0] = static_cast<s32>(pColor[0]);
        break;
    case 49:
        p8[0] = static_cast<u8>(pColor[0] * 255.0f);
        p8[1] = static_cast<u8>(pColor[1] * 255.0f);
        break;
    case 50:
    case 52:
        p8[0] = static_cast<u8>(pColor[0]);
        p8[1] = static_cast<u8>(pColor[1]);
        break;
    case 51:
        p8[0] = static_cast<s8>(pColor[0] * 128.0f);
        p8[1] = static_cast<s8>(pColor[1] * 128.0f);
        break;
    case 54:
        p16[0] = Unk_PackHalf(pBits[0]);
        break;
    case 55:
    case 56:
        p16[0] = static_cast<u16>(pColor[0] * 65535.0f);
        break;
    case 57:
    case 59:
        p16[0] = static_cast<u16>(pColor[0]);
        break;
    case 58:
        p16[0] = static_cast<s16>(pColor[0] * 32767.5f);
        break;
    case 62:
    case 64:
        p8[0] = static_cast<u8>(pColor[0]);
        break;
    case 63:
        p8[0] = static_cast<s8>(pColor[0] * 128.0f);
        break;
    case 61:
    case 65:
        p8[0] = static_cast<u8>(pColor[0] * 255.0f);
        break;
    default:
        return false;
    }
    return true;
}

void Unk_4ef880(SiSDK3::SiString<char>* self, const char* format, va_list args);

// 0x71004edfa0
void Unk_4edfa0(SiSDK3::SiString<char>* self, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Unk_4ef880(self, format, args);
    va_end(args);
}

// 0x7100594590: a view volume's projection, for one of two handednesses (its
// own translation unit has the matrix as sixteen floats)
Unk_Matrix44 Unk_594590(const Unk_594590_Volume* volume, s32 handedness);

// NON_MATCHING: the same instructions up to the product's scheduling: the
// original loads the projection's last row first and multiplies it by zero
// before the others (tried: the product's loop backwards, its rows in
// locals, the lanes from a row local, accumulated terms, vmulq_n/laneq, the
// scalars first in each product).
// Also tried: Unk_Multiply with its products in locals (last row first),
// b's rows in locals, the lanes as floats, vmulq_laneq/vmlaq_n, unrolled
// rows, by value; the translation before the projection, the product of a
// temporary, the volume's planes from expressions.
// 0x71004ee020: an orthographic projection of a width and a height
Unk_Matrix44 Unk_4ee020(f32 width, f32 height, f32 zNear, f32 zFar) {
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 z = 0.0f;
    f32 right = x + width;
    f32 bottom = y + height;
    f32 depth = z + zNear;
    Unk_594590_Volume volume(1, x, right, y, bottom, zNear, zFar);
    Unk_Matrix44 projection = Unk_594590(&volume, 0);
    Unk_Matrix44 translation = Unk_Identity();
    Unk_Translate(&translation, 0.0f, 0.0f, depth);
    return Unk_Multiply(translation, projection);
}

// 0x71004c3410, 0x71004c3450: two hashes of a block of bytes (a 64-bit size)
u32 Unk_4c3410(s64 size, const u8* data);
u32 Unk_4c3450(s64 size, const u8* data);
// 0x71004c5860: snprintf
s32 Unk_4c5860(char* dst, size_t size, const char* format, ...);

// A shader's key as 0x71004eddf0 reads it (placeholder names): a number and
// a block of bytes.
struct Unk_4eddf0_Key {
    u8 field_0[8];
    u32 field_8;
    s32 field_c;  // the block's size
    const u8* field_10;
};

// (the hashes take a 64-bit size, which is why the block's size is loaded
// with `ldrsw x0` for each)
// 0x71004eddf0: a key as text, the number then the block's two hashes, in
// hexadecimal
bool Unk_4eddf0(SiSDK3::SiString<char>* dst, const void* key) {
    const Unk_4eddf0_Key* k = static_cast<const Unk_4eddf0_Key*>(key);
    SiSDK3::Unk_StringReserve(dst, k->field_c * 2 + 8);
    char text[16];
    Unk_4c5860(text, sizeof(text), "%x", k->field_8);
    SiSDK3::Unk_StringAppendGrow(dst, static_cast<const char*>(text));
    if (k->field_c > 0) {
        u32 hash1 = Unk_4c3410(k->field_c, k->field_10);
        u32 hash2 = Unk_4c3450(k->field_c, k->field_10);
        SiSDK3::Unk_StringAppend(dst, '_');
        Unk_4edfa0(dst, "%x_%x", hash1, hash2);
    }
    return true;
}

// SiGfx's kernel as the image functions use it (placeholder): slot 6 is its
// allocator.
class Unk_GfxKernelAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual SiSDK3::ISiAllocator* vf6();
};
// 0x71004cbf40: SiGfx's kernel (leafgen's name and type)
u64 Unk_4cbf40_get();
static inline SiSDK3::ISiAllocator* Unk_GfxAllocator() {
    return reinterpret_cast<Unk_GfxKernelAllocator*>(Unk_4cbf40_get())->vf6();
}

// whether a format is compressed in blocks (inline: placeholder name)
static inline bool Unk_IsBlockFormat(u32 format) {
    switch (format) {
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x5e:
    case 0x5f:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
        return true;
    default:
        return false;
    }
}

// A BC1 colour block's rows the other way up (inline: placeholder name): its
// four rows of indices are its last four bytes.
static inline void Unk_FlipColorBlock(u8* block) {
    u8 row0 = block[4];
    u8 row1 = block[5];
    u8 row2 = block[6];
    u8 row3 = block[7];
    block[4] = row3;
    block[5] = row2;
    block[6] = row1;
    block[7] = row0;
}

// A BC4 block's rows the other way up (inline: placeholder name): after its
// two values, its indices are four rows of 12 bits, two rows in each three
// bytes.
static inline void Unk_FlipAlphaBlock(u8* block) {
    u32 rows01;
    u32 rows23;
    memcpy(&rows01, block + 2, sizeof(rows01));
    memcpy(&rows23, block + 5, sizeof(rows23));
    rows01 &= 0xffffff;
    rows23 &= 0xffffff;
    // (the rows swapped, a byte at a time: each middle byte is the upper
    // row's last four bits and the lower row's first four)
    block[2] = static_cast<u8>(rows23 >> 12);
    block[3] = static_cast<u8>((rows23 >> 20) | (rows23 << 4));
    block[4] = static_cast<u8>(rows23 >> 4);
    block[5] = static_cast<u8>(rows01 >> 12);
    block[6] = static_cast<u8>((rows01 >> 20) | (rows01 << 4));
    block[7] = static_cast<u8>(rows01 >> 4);
}

// 0x71004ee660: turns a compressed block upside down (placeholder name)
bool Unk_4ee660(u32 format, u8* block) {
    switch (format) {
    case 0x46:
    case 0x47:
    case 0x48:
        Unk_FlipColorBlock(block);
        break;
    case 0x49:
    case 0x4a:
    case 0x4b: {
        u16* alpha = reinterpret_cast<u16*>(block);
        u16 row0 = alpha[0];
        u16 row1 = alpha[1];
        u16 row2 = alpha[2];
        u16 row3 = alpha[3];
        alpha[0] = row3;
        alpha[1] = row2;
        alpha[2] = row1;
        alpha[3] = row0;
        Unk_FlipColorBlock(block + 8);
        break;
    }
    case 0x4c:
    case 0x4d:
    case 0x4e:
        Unk_FlipAlphaBlock(block);
        Unk_FlipColorBlock(block + 8);
        break;
    case 0x4f:
    case 0x50:
    case 0x51:
        Unk_FlipAlphaBlock(block);
        break;
    case 0x52:
    case 0x53:
    case 0x54:
        Unk_FlipAlphaBlock(block);
        Unk_FlipAlphaBlock(block + 8);
        break;
    }
    return true;
}

// Turns a row of compressed blocks upside down (inline: placeholder name);
// nothing for a format without blocks.
static inline void Unk_FlipBlockRow(u32 format, u8* row, s32 count) {
    s64 step;
    switch (format) {
    case 70:
    case 71:
    case 72:
        step = 8;
        break;
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
        step = 16;
        break;
    case 79:
    case 80:
    case 81:
        step = 8;
        break;
    case 82:
    case 83:
    case 84:
        step = 16;
        break;
    case 94:
    case 95:
    case 96:
    case 97:
    case 98:
    case 99:
        step = 16;
        break;
    case 101:
    case 102:
    case 103:
    case 104:
        step = 8;
        break;
    default:
        return;
    }
    for (s32 i = 0; i < count; i++) {
        Unk_4ee660(format, row);
        row += step;
    }
}

// NON_MATCHING: 4 bytes longer: the loops are unswitched as the original's
// are (formats 0x47, 0x46, then the rest), but in the generic loop the
// original keeps the format's table index in a register and spills the row
// size, where this does the reverse and loads the index twice. Tried: the
// row pointers' products in other orders, an s32 or u32 step, a non-static
// helper.
// Also tried: the row index as s32, s64 or int, the rows' products both
// ways round, `&data[...]`, the bottom row computed first.
// 0x71004ee290: turns a block-compressed image upside down, a row of blocks
// at a time (placeholder name)
bool Unk_4ee290(u32 format, u8* data, s32 width, s32 height) {
    s32 blockBytes = Unk_4ed0f0(format);
    s32 blocksWide = width >> 2;
    blocksWide = blocksWide > 1 ? blocksWide : 1;
    s32 blocksHigh = height >> 2;
    blocksHigh = blocksHigh > 1 ? blocksHigh : 1;
    SiSDK3::ISiAllocator* pAllocator = Unk_GfxAllocator();
    if (pAllocator == nullptr) {
        return false;
    }
    s32 rowSize = blockBytes * blocksWide;
#line 7229
    u8* row = static_cast<u8*>(pAllocator->vf8(1, rowSize, -1, __FILE__, __LINE__));
    if (row == nullptr) {
        return false;
    }
    for (s32 y = 0; y < blocksHigh / 2; y++) {
        u8* top = data + rowSize * y;
        u8* bottom = data + (blocksHigh - 1 - y) * rowSize;
        memcpy(row, bottom, rowSize);
        memcpy(bottom, top, rowSize);
        memcpy(top, row, rowSize);
        Unk_FlipBlockRow(format, top, blocksWide);
        Unk_FlipBlockRow(format, bottom, blocksWide);
    }
    if (blocksHigh % 2 != 0) {
        Unk_FlipBlockRow(format, data + rowSize * (blocksHigh / 2), blocksWide);
    }
    pAllocator = Unk_GfxAllocator();
    if (pAllocator != nullptr) {
#line 7259
        SI_FREE(pAllocator, row);
    }
    return true;
}

// 0x71004ee110: turns an image upside down, a row at a time (a compressed
// one by its blocks)
// NON_MATCHING: the bottom row's number: the original keeps it a 32-bit
// counter (`subs w23, w22, #1` before the loop, `cmp x24, w23, sxtw` at its
// top, `sub w23, w23, #1`); here IndVars widens it to 64 bits (`cmp x23,
// x25`, `sub x25, x25, #1`). The pitch as a 64-bit local sign-extended once
// and the counter decremented in the loop's increment give the rest (same
// size). Tried: the decrement in the body or before the test, the test
// written `j <= i`, the bottom row's offset from the 32-bit pitch, row
// pointers, an int index.
// Also tried (72 forms): s32/s64 rows with s32/u32 bottom numbers, the
// bottom row from `height - 1 - i`, the test cast, the decrement in the
// increment or the body.
// (Round 3: i as s32/s64/int with j as s32/int declared before or after it,
// j as u32 tested through a cast, i < j in the loop's condition: no change.)
bool Unk_4ee110(u32 format, u8* data, s32 width, s32 height, s32 pitch) {
    if (Unk_IsBlockFormat(format)) {
        if ((format >= 0x46 && format <= 0x54) || (format >= 0x5e && format <= 0x63)) {
            Unk_4ee290(format, data, width, height);
        }
        return true;
    }
    SiSDK3::ISiAllocator* pAllocator = Unk_GfxAllocator();
#line 7179
    u8* row = pAllocator != nullptr ? static_cast<u8*>(pAllocator->vf8(1, pitch, -1, __FILE__, __LINE__)) : nullptr;
    s64 size = pitch;
    s32 j = height - 1;
    for (s64 i = 0; i < height; i++, j--) {
        if (i >= j) {
            break;
        }
        memcpy(row, data + i * size, size);
        memcpy(data + i * size, data + j * size, size);
        memcpy(data + j * size, row, size);
    }
    if (row != nullptr) {
        pAllocator = Unk_GfxAllocator();
        if (pAllocator != nullptr) {
#line 7203
            SI_FREE(pAllocator, row);
        }
    }
    return true;
}

// 0x71004e4400: a path's file name, with or without its extension
SiSDK3::SiString<char> Unk_4e4400(SiSDK3::SiString<char>* path, bool withExtension);
// 0x71004ca0b0: replaces a text with another
void Unk_4ca0b0(SiSDK3::SiString<char>* self, const char* from, const char* to, u64, u64, bool);
// 0x71004c3560: another hash of a string
u32 Unk_4c3560(const SiSDK3::SiString<char>* s);
// 0x71004c9090: formats a string
void Unk_4c9090(SiSDK3::SiString<char>* self, const char* format, ...);

// 0x71004ee870: the name of a request's shader in a binary cache: its file's
// name, the target's interface and language, the stage, the versions, then
// two hashes of its keys and names. The two numbers of a target are read as
// the halves of its 64-bit field (two 32-bit loads); the languages' cases are
// in descending order (the original compares 4, 3, 2); the text of the
// request's second string goes out of scope before the separator after it.
void Unk_4ee870(const SiSDK3::Unk_4e7710_Request* request, SiSDK3::SiString<char>* name) {
    using namespace SiSDK3;
    Unk_StringAssign(name, "");
    SiString<char> file = Unk_4e4400(const_cast<SiString<char>*>(&request->field_68), false);
    Unk_4ca0b0(&file, "/", "_", 0, 0, true);
    Unk_4ca0b0(&file, "\\", "_", 0, 0, true);
    Unk_StringAppendString(name, &file);
    Unk_StringAppend(name, '_');
    if (request->field_98.field_10 != 0) {
        {
            SiString<char> text = Unk_4c49f0(Unk_StringCStr(&request->field_98));
            Unk_StringAppendString(name, &text);
        }
        Unk_StringAppend(name, '_');
    }
    s32 api = request->field_38;
    s32 language = request->field_3c;
    s32 major = static_cast<s32>(request->field_40);
    s32 minor = static_cast<s32>(request->field_40 >> 32);
    if (request->field_48 != 0 && request->field_4c != 0) {
        api = request->field_48;
        language = request->field_4c;
        major = static_cast<s32>(request->field_50);
        minor = static_cast<s32>(request->field_50 >> 32);
    }
    switch (api) {
    case 2:
        Unk_StringAppendGrow(name, "OGL");
        break;
    case 3:
        Unk_StringAppendGrow(name, "OGLES3");
        break;
    case 4:
        Unk_StringAppendGrow(name, "D3D11");
        break;
    case 5:
        Unk_StringAppendGrow(name, "D3D12");
        break;
    case 6:
        Unk_StringAppendGrow(name, "PS4");
        break;
    case 7:
        Unk_StringAppendGrow(name, "Vulkan");
        break;
    case 8:
        Unk_StringAppendGrow(name, "NX");
        break;
    }
    Unk_StringAppend(name, '_');
    switch (language) {
    case 4:
        Unk_StringAppendGrow(name, "PSSL");
        break;
    case 3:
        Unk_StringAppendGrow(name, "HLSL");
        break;
    case 2:
        Unk_StringAppendGrow(name, "GLSL");
        break;
    }
    Unk_StringAppend(name, '_');
    switch (request->field_58) {
    case 1:
        Unk_StringAppendGrow(name, "VS");
        break;
    case 2:
        Unk_StringAppendGrow(name, "PS");
        break;
    case 3:
        Unk_StringAppendGrow(name, "GS");
        break;
    case 4:
        Unk_StringAppendGrow(name, "DS");
        break;
    case 5:
        Unk_StringAppendGrow(name, "HS");
        break;
    case 6:
        Unk_StringAppendGrow(name, "CS");
        break;
    }
    Unk_StringAppend(name, '_');
    Unk_4edfa0(name, "%d_%d", major, minor);
    Unk_StringAppend(name, '_');
    Unk_4edfa0(name, "%d_%d", request->field_5c, request->field_60);
    Unk_StringAppend(name, '_');
    Unk_NXString<0x400> keys(nullptr);
    Unk_StringAppendString(&keys, &request->field_c8);
    Unk_StringAppendString(&keys, &request->field_f8);
    if (request->field_1d8.m_itemCount != 0) {
        for (u64 i = 0; i < request->field_1d8.m_itemCount; i++) {
            Unk_StringAppendString(&keys, &request->field_1d8.m_pData[i]);
        }
    } else {
        for (u64 i = 0; i < request->field_188.m_itemCount; i++) {
            Unk_StringAppendString(&keys, &request->field_188.m_pData[i]);
        }
    }
    u32 hash1 = Unk_4c3510(&keys);
    u32 hash2 = Unk_4c3560(&keys);
    Unk_NXString<0x400> hashes(nullptr);
    Unk_4c9090(&hashes, "_%08x_%08x", hash1, hash2);
    Unk_StringAppendString(name, &hashes);
    Unk_StringAppendGrow(name, ".shadercache");
}

// 0x71004ef880: adds formatted text to a string (at most 4096 characters).
// The length is widened where it is declared and tests the same thing as the
// if: that keeps its select in front of the branch.
void Unk_4ef880(SiSDK3::SiString<char>* self, const char* format, va_list args) {
    SiSDK3::ISiAllocator* pAllocator = Unk_4bc690() != nullptr ? Unk_4bc690() : Unk_4bc640();
    static_cast<void>(pAllocator);
    char buffer[0x1000];
    s32 n = vsnprintf(buffer, sizeof(buffer), format, args);
    size_t length = static_cast<u32>(n < 0 ? 0 : n);
    if (!(n < 0)) {
        size_t needed = length + self->field_10 + 1;
        if (needed > self->field_20) {
            Unk_4c5d50(self, needed, true);
        }
        memcpy(self->m_pBuffer + self->field_10, buffer, length);
        self->m_pBuffer[self->field_10 + length] = 0;
        const char* s = self->m_pBuffer;
        size_t count = 0;
        if (s != nullptr) {
            while (s[count] != 0) {
                count++;
            }
        }
        self->field_10 = count;
    }
}
