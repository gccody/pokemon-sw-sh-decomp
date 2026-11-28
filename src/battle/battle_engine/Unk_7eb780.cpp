// Scope: common
// A classifier that extends Unk_7eb6d0's set (in Unk_7eb5d0.cpp; a TU of its
// own, since the original calls it).
#include <types.h>

bool Unk_7eb6d0(u16 value);

// 0x71007eb780
bool Unk_7eb780(u16 value) {
    if (Unk_7eb6d0(value))
        return true;
    static const u16 kValues[] = {0xd,   0x13,  0x4c,  0x5b,  0x75,  0x82,  0x8f,  0xfd,
                                  0x108, 0x123, 0x154, 0x1d3, 0x1fb, 0x229, 0x22a, 0x236,
                                  0x259, 0x29d, 0x2b2, 0x2c0, 0x2e7, 0x2e8, 0x2f5, 0x2f6,
                                  0x2f7, 0x2f8, 0x2f9, 0x2fa, 0x2fb, 0x2fc, 0x2fd, 0x2fe,
                                  0x2ff, 0x300, 0x301, 0x302, 0x303, 0x304, 0x305, 0x306};
    for (u32 i = 0; i < 40; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}
