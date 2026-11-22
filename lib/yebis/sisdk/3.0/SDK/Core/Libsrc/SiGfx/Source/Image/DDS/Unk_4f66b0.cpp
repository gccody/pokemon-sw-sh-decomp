// Scope: common
// Which of SiGfx's formats a DDS file's pixels have (a translation unit of
// its own, 0x71004f66b0 to 0x71004f68a0; its static initialiser is
// lib/yebis/static's).
#include <yebis/sisdk/3.0/SDK/Core/Libsrc/SiGfx/Source/Image/DDS/Unk_4f66b0.h>

// 0x71004f66b0
bool Unk_4f66b0(const Unk_4f66b0_PixelFormat* pixelFormat, u32* format) {
    *format = 0;
    u32 value;
    if ((pixelFormat->field_4 & 0x41) == 0x41 && pixelFormat->field_c == 32) {
        if (pixelFormat->field_10 == 0xff) {
            if (pixelFormat->field_14 != 0xff00) {
                return false;
            }
            if (pixelFormat->field_18 != 0xff0000) {
                return false;
            }
            if (pixelFormat->field_1c != 0xff000000) {
                return false;
            }
            value = 0x1c;
        } else if (pixelFormat->field_10 == 0xff0000) {
            if (pixelFormat->field_14 != 0xff00) {
                return false;
            }
            if (pixelFormat->field_18 != 0xff) {
                return false;
            }
            if (pixelFormat->field_1c != 0xff000000) {
                return false;
            }
            value = 0x57;
        } else {
            return false;
        }
    } else {
        if (!(pixelFormat->field_4 & 4)) {
            return false;
        }
        switch (pixelFormat->field_8) {
        case 36:
            value = 0xb;
            break;
        case 110:
            value = 0xd;
            break;
        case 111:
            value = 0x36;
            break;
        case 112:
            value = 0x22;
            break;
        case 113:
            value = 0xa;
            break;
        case 114:
            value = 0x29;
            break;
        case 115:
            value = 0x10;
            break;
        case 116:
            value = 2;
            break;
        case 0x31545844:  // DXT1
            value = 0x47;
            break;
        case 0x32545844:  // DXT2
        case 0x33545844:  // DXT3
            value = 0x4a;
            break;
        case 0x34545844:  // DXT4
        case 0x35545844:  // DXT5
            value = 0x4d;
            break;
        default:
            return false;
        }
    }
    *format = value;
    return true;
}

// 0x71004f6890
bool Unk_4f6890(u32 dxgiFormat, u32* format) {
    *format = dxgiFormat;
    return true;
}
