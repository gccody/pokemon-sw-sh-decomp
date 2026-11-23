// Scope: common
// A YEBIS src/GPU translation unit (0x7100446a90 to 0x71004472b8), the formats' and usages' names, between GPUInterfaceResource.cpp and GPUInterfaceTexture.cpp: its name isn't in the executable.
#include <math.h>
#include <stdio.h>
#include <string.h>

#include <yebis/YEBIS_draft/src/GPU/Unk_Statics.h>

namespace PPFX {

// 0x7100446a90: a size at a mip level (at least 1)
u32 Unk_446a90(u32 size, u32 level) {
    u32 value = size >> level;
    return value > 1 ? value : 1;
}

// 0x7100446aa0: how many mip levels sizes have
u32 Unk_446aa0(u32 width, u32 height, u32 depth) {
    u32 size = width > height ? width : height;
    size = size > depth ? size : depth;
    return static_cast<u32>(floorf(logf(static_cast<f32>(size)) / 0.6931472f)) + 1;
}

// 0x7100446ae0: a format's bytes per pixel
u32 Unk_446ae0(s32 format) {
    switch (format) {
    case 1:
    case 2:
    case 3:
    case 4:
        return 16;
    case 5:
    case 6:
    case 7:
    case 8:
        return 12;
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
        return 8;
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
    case 67:
    case 87:
    case 88:
    case 91:
    case 93:
        return 4;
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 57:
    case 58:
    case 59:
    case 85:
    case 86:
        return 2;
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
        return 1;
    default:
        return 0;
    }
}

// 0x7100446b20: a texture format's name (the log lines' formats), copied to
// buffer if there is one
// NON_MATCHING: the block that returns the name without a buffer is laid out
// after the last case here, and after GPUFMT_D24S8's (before GPUFMT_D16's and
// GPUFMT_A8's) in the original; the instructions are the same. Tried: the
// default label at every position, the name initialised before the switch,
// the last two formats tested in the default, one return or two.
const char* Unk_446b20(s32 format, char* buffer) {
    static char Unk_24e1bf0[0x40];
    const char* name;
    switch (format) {
    case 0:
        name = "GPUFMT_UNKNOWN";
        break;
    case 2:
        name = "GPUFMT_A32B32G32R32F";
        break;
    case 10:
        name = "GPUFMT_A16B16G16R16F";
        break;
    case 24:
        name = "GPUFMT_A2B10G10R10";
        break;
    case 28:
        name = "GPUFMT_A8R8G8B8";
        break;
    case 29:
        name = "GPUFMT_A8R8G8B8_SRGB";
        break;
    case 41:
        name = "GPUFMT_R32F";
        break;
    case 45:
        name = "GPUFMT_D24S8";
        break;
    case 55:
        name = "GPUFMT_D16";
        break;
    case 65:
        name = "GPUFMT_A8";
        break;
    default:
        sprintf(Unk_24e1bf0, "0x%08x", format);
        name = Unk_24e1bf0;
        break;
    }
    if (buffer != nullptr) {
        strcpy(buffer, name);
        return buffer;
    }
    return name;
}

// 0x7100446c40: a usage's names (the short ones if shortNames), copied to
// buffer if there is one
// NON_MATCHING: the same instructions with other callee-saved registers, and
// one more of them: the original keeps the text's address in x21 (set again
// in each block that uses it), the usage in x22 and the count in x23; here
// the usage is in x21 and the address shares the count's and the usage's
// registers.
const char* Unk_446c40(u32 usage, bool shortNames, char* buffer) {
    static char Unk_24e1c30[0x100];
    char* text = Unk_24e1c30;
    s32 count = 0;
    text[0] = 0;
    if (usage & 1) {
        char* end = text + strlen(text);
        if (shortNames) {
            sprintf(end, count != 0 ? "|%s" : "%s", "RT");
        } else {
            sprintf(end, count != 0 ? " | %s" : "%s", "GPUUSAGE_RENDERTARGET");
        }
        count++;
    }
    if (usage & 2) {
        char* end = text + strlen(text);
        if (shortNames) {
            sprintf(end, count != 0 ? "|%s" : "%s", "DS");
        } else {
            sprintf(end, count != 0 ? " | %s" : "%s", "GPUUSAGE_DEPTHSTENCIL");
        }
        count++;
    }
    if (buffer != nullptr) {
        strcpy(buffer, text);
        return buffer;
    }
    return text;
}

// 0x7100446d60: an index format's name
const char* Unk_446d60(s32 format, char* buffer) {
    const char* name = nullptr;
    switch (format) {
    case -1:
        name = "GPUIBFMT_UNKNOWN";
        break;
    case 42:
        name = "GPUIBFMT_UINT32";
        break;
    case 57:
        name = "GPUIBFMT_UINT16";
        break;
    }
    if (buffer != nullptr) {
        strcpy(buffer, name);
        return buffer;
    }
    return name;
}

}  // namespace PPFX

// 0x7100446df0: a result's name
const char* Unk_446df0(s32 result) {
    switch (result) {
    case -6:
        return "E_INVALIDARG";
    case -5:
        return "E_OUTOFMEMORY";
    case -4:
        return "E_NOTIMPL";
    case -3:
        return "E_UNEXPECTED";
    case -2:
        return "E_ABORT";
    case -1:
        return "E_FAIL";
    case 0:
        return "S_OK";
    case 1:
        return "S_FALSE";
    default:
        return "Unknown Error Code";
    }
}

namespace PPFX {

// 0x7100446e20: the size of a tile and how many there are (one, the
// target's size, whatever the other parameters say)
s32 Unk_446e20(u32* width, u32* height, u32 targetWidth, u32 targetHeight, s32 arg4, s32* format, s32 tiled,
               s32 msaa, s32 arg8) {
    if (width != nullptr) {
        *width = targetWidth;
    }
    if (height != nullptr) {
        *height = targetHeight;
    }
    return 1;
}

// 0x7100446e40: a multisample type's sample count
u32 Unk_446e40(s32 msaa) {
    switch (msaa) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
        return 10;
    case 11:
        return 11;
    case 12:
        return 12;
    case 13:
        return 13;
    case 14:
        return 14;
    case 15:
        return 15;
    case 16:
        return 16;
    default:
        return 0;
    }
}

// 0x7100446e60: the sample count of a number of samples between 1 and 16
// (16 for a negative one)
u32 Unk_446e60(s32 count) {
    s32 n = count < 0 ? 16 : count;
    n = n < 16 ? n : 16;
    n = n > 1 ? n : 1;
    return Unk_446e40(n);
}

// 0x7100446eb0: the multisample type and quality of a number of samples
// and a quality (both between 1 and 16, 16 for a negative one; no quality
// for one sample)
// NON_MATCHING: here the inlined switch of Unk_446e40 becomes a lookup
// table; the original keeps it a jump table whose case 1 also sets the
// quality to 0 (the test of one sample merged into the switch, which a
// non-constant result then keeps from becoming a table) and branches on the
// quality's sign. Eight orders of the tests were tried.
s32 Unk_446eb0(s32 count, s32 quality, u32* outType, s32* outQuality) {
    s32 n = count < 0 ? 16 : count;
    n = n < 16 ? n : 16;
    n = n > 1 ? n : 1;
    s32 q = quality < 0 ? 16 : quality;
    q = q < 16 ? q : 16;
    if (n == 1) {
        q = 0;
    }
    u32 type = Unk_446e40(n);
    if (outType != nullptr) {
        *outType = type;
    }
    if (outQuality != nullptr) {
        *outQuality = q;
    }
    return 0;
}

// 0x7100447010
bool Unk_447010(s32 arg0, s32 arg1) {
    return arg0 > 0 || arg1 != 0;
}

// 0x7100447030
u32 Unk_447030(s32 arg) {
    switch (arg) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 4;
    default:
        return 9;
    }
}

}  // namespace PPFX

// 0x7100447050: _GLOBAL__sub_I_Unk_447050.cpp
