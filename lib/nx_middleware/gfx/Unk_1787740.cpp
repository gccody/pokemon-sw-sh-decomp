// Scope: common
// NintendoSDK_gfx 7.3.2 for NVN: its SDK MW tag and the image format queries. Placeholder names (gfx.h).
#include "nx_middleware/gfx/gfx.h"

// 0x7101787740
void Unk_1787740() {
    nn::util::ReferSymbol("SDK MW+Nintendo+NintendoSDK_gfx-7_3_2-Release");
}

// 0x7101787750
int Unk_1787750(int format) {
    switch (format) {
    case 0x27: return 16;
    case 0x28: return 8;
    case 0x29: return 16;
    case 0x2a: return 8;
    case 0x2b: return 8;
    case 0x2c: return 4;
    case 0x2d: return 4;
    case 0x2e: return 5;
    case 0x2f: return 5;
    case 0x30: return 6;
    case 0x31: return 6;
    case 0x32: return 8;
    case 0x33: return 8;
    case 0x34: return 8;
    case 0x35: return 10;
    case 0x36: return 10;
    case 0x37: return 10;
    case 0x38: return 10;
    case 0x39: return 12;
    case 0x3a: return 12;
    default: return 4;
    }
}

// 0x7101787780
int Unk_1787780(int format) {
    switch (format) {
    case 0x27: return 8;
    case 0x28: return 8;
    case 0x29: return 8;
    case 0x2a: return 8;
    case 0x2b: return 4;
    case 0x2c: return 4;
    case 0x2d: return 4;
    case 0x2e: return 4;
    case 0x2f: return 5;
    case 0x30: return 5;
    case 0x31: return 6;
    case 0x32: return 5;
    case 0x33: return 6;
    case 0x34: return 8;
    case 0x35: return 5;
    case 0x36: return 6;
    case 0x37: return 8;
    case 0x38: return 10;
    case 0x39: return 10;
    case 0x3a: return 12;
    default: return 4;
    }
}

// 0x71017877b0
bool Unk_17877b0(int format) {
    return static_cast<u32>(format - 0x1a) < 0x21;
}

// 0x71017877c0
int Unk_17877c0(int format) {
    switch (format) {
    case 0x1a: return 8;
    case 0x1b: return 16;
    case 0x1c: return 16;
    case 0x1d: return 8;
    case 0x1e: return 16;
    case 0x1f: return 16;
    case 0x20: return 16;
    case 0x21: return 8;
    case 0x22: return 16;
    case 0x23: return 8;
    case 0x24: return 8;
    case 0x25: return 8;
    case 0x26: return 16;
    case 0x27: return 32;
    case 0x28: return 32;
    case 0x29: return 32;
    case 0x2a: return 32;
    case 0x2b: return 8;
    case 0x2c: return 8;
    case 0x2d: return 16;
    case 0x2e: return 16;
    case 0x2f: return 16;
    case 0x30: return 16;
    case 0x31: return 16;
    case 0x32: return 16;
    case 0x33: return 16;
    case 0x34: return 16;
    case 0x35: return 16;
    case 0x36: return 16;
    case 0x37: return 16;
    case 0x38: return 16;
    case 0x39: return 16;
    case 0x3a: return 16;
    case 0x3b: return 2;
    }
    if (format < 3) {
        return 1;
    }
    if (format < 0xb) {
        return 2;
    }
    if (format < 0x15) {
        return 4;
    }
    if (format < 0x18) {
        return 8;
    }
    return format == 0x18 ? 0xc : 0x10;
}

// 0x7101787830
size_t Unk_1787830(u32 width, int format) {
    if (Unk_17877b0(format)) {
        u32 blockWidth = Unk_1787750(format);
        width = (width + blockWidth - 1) / blockWidth;
    }
    return Unk_17877c0(format) * width;
}

// 0x71017878f0
int Unk_17878f0(int type, bool isSigned, bool isNormalized) {
    switch (type) {
    case 1:
        return isSigned ? 4 : 0;
    case 2:
        if (isSigned) {
            return isNormalized ? 7 : 5;
        }
        return isNormalized ? 6 : 1;
    case 3:
        return 2;
    default:
        nn::detail::UnexpectedDefaultImpl("", "", 0);
    }
}
