// Scope: common
// Functions on SiGfx's numbers (placeholder names): the names of its graphics
// interfaces and shader languages, what a pixel format's number says about it
// (its bits, its blocks' bytes, whether it is compressed), and how many mip
// levels a size has. The original compiled the switches to lookup tables and
// bit masks; the cases here are those tables' entries.
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <types.h>

#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/SiCore_String.h>
#include <yebis/sisdk/3.0/SDK/Core/Include/SiCore/Unk_StringFuncs.h>

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

void Unk_4ef880(SiSDK3::SiString<char>* self, const char* format, va_list args);

// 0x71004edfa0
void Unk_4edfa0(SiSDK3::SiString<char>* self, const char* format, ...) {
    va_list args;
    va_start(args, format);
    Unk_4ef880(self, format, args);
    va_end(args);
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
