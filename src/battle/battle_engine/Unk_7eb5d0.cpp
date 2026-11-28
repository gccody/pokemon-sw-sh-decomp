// Scope: common
// Value classifiers (0x71007eb5d0 to 0x71007ebd9c): range and set tests on
// 16-bit IDs, in the style of Unk_7eb300.cpp. Placeholder names: rename once
// the functions are known.
//
// Some sets are a loop over a small constant array: clang unrolls it into the
// same switch, but in its leaves a case moves to the end to fall through
// into the return, which follows the switch's block then (cmp 0x2ee before
// 0x258 in 0x71007ebab0). A switch statement's leaves test in ascending order.
#include <types.h>

// 0x71007eb5d0
bool Unk_7eb5d0(u16 value) {
    static const u16 kValues[] = {0x1ed, 0x305};
    for (u32 i = 0; i < 2; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007eb5f0
bool Unk_7eb5f0(u16 value) {
    switch (value) {
        case 0x3:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
        case 0x30:
        case 0x33:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4e:
        case 0x53:
        case 0x76:
        case 0x7b:
        case 0x7c:
        case 0x88:
        case 0x89:
        case 0xb0:
        case 0xb1:
        case 0xb2:
        case 0xb3:
        case 0xb4:
        case 0xb5:
        case 0xb6:
        case 0xb7:
        case 0xb8:
        case 0xb9:
        case 0xba:
        case 0xbb:
        case 0xd2:
        case 0xd3:
        case 0xd4:
            return true;
    }
    return false;
}

// 0x71007eb630
bool Unk_7eb630(u16 value) {
    switch (value) {
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
        case 0x8:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0x11:
        case 0x13:
        case 0x14:
        case 0x15:
            return true;
    }
    return false;
}

// 0x71007eb660
u32 Unk_7eb660(u32 index) {
    static const u32 kValues[] = {7, 12, 13, 15, 23, 11};
    if (index < 6)
        return kValues[index];
    return 0;
}

// 0x71007eb680
bool Unk_7eb680(u32 value) {
    switch (value) {
        case 0x7:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xf:
        case 0x17:
            return true;
    }
    return false;
}

// 0x71007eb6b0
u32 Unk_7eb6b0(u32 index) {
    static const u32 kValues[] = {
        0x24, 0x15, 0x12, 0x05, 0x04, 0x09, 0x0a, 0x08, 0x2b, 0x0b, 0x0c, 0x17, 0x0d, 0x1f,
        0x21, 0x0f, 0x13, 0x1d, 0x1e, 0x26, 0x25, 0x27, 0x28, 0x29, 0x18, 0x0e, 0x14, 0x01,
        0x02, 0x03, 0x07, 0x06, 0x10, 0x11, 0x16, 0x19, 0x1a, 0x1b, 0x1c, 0x20, 0x22, 0x23,
    };
    if (index < 42)
        return kValues[index];
    return 0;
}

// 0x71007eb6d0
bool Unk_7eb6d0(u16 value) {
    switch (value) {
        case 0x66:
        case 0x76:
        case 0x77:
        case 0xa5:
        case 0xa6:
        case 0xd6:
        case 0x10b:
        case 0x112:
        case 0x17e:
        case 0x17f:
        case 0x1c0:
        case 0x232:
        case 0x25e:
        case 0x25f:
        case 0x292:
        case 0x2b7:
        case 0x2b8:
        case 0x2b9:
        case 0x2ba:
        case 0x2bb:
        case 0x2bc:
        case 0x2bd:
        case 0x2be:
        case 0x2bf:
        case 0x2cf:
        case 0x2d3:
        case 0x2d4:
        case 0x2d5:
        case 0x2d6:
        case 0x2d7:
        case 0x2d8:
            return true;
    }
    return false;
}

extern const u16 Unk_1f10af4[81] __attribute__((visibility("hidden")));

// 0x71007eb9b0
bool Unk_7eb9b0(u16 value) {
    for (u32 i = 0; i < 81; i++) {
        if (Unk_1f10af4[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebab0
bool Unk_7ebab0(u16 value) {
    static const u16 kValues[] = {0x4d, 0x4e, 0x4f, 0x93, 0xb2, 0x258, 0x2ee};
    for (u32 i = 0; i < 7; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebb10
bool Unk_7ebb10(u16 value) {
    switch (value) {
        case 0x2c:
        case 0x9e:
        case 0xf2:
        case 0x131:
        case 0x1a6:
        case 0x1a7:
        case 0x1a8:
        case 0x2c2:
        case 0x2ea:
        case 0x2f3:
            return true;
    }
    return false;
}

// 0x71007ebb80
bool Unk_7ebb80(u16 value) {
    static const u16 kValues[] = {0x79,  0x8c,  0xbc,  0xbe,  0xc0,  0xf7,  0x128, 0x12d, 0x137,
                                  0x14b, 0x15e, 0x168, 0x18c, 0x192, 0x19b, 0x19c, 0x1aa, 0x1b7,
                                  0x1bb, 0x1e6, 0x1eb, 0x221, 0x2a4, 0x2b2, 0x30c};
    for (u32 i = 0; i < 25; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007ebcb0
bool Unk_7ebcb0(u16 value) {
    static const u16 kValues[] = {0x2e,  0xae,  0xc3,  0xd4,  0xd7,  0xf8,  0x110, 0x138,
                                  0x150, 0x16c, 0x16f, 0x17b, 0x17f, 0x1ef, 0x1f6, 0x24d,
                                  0x24e, 0x255, 0x25f, 0x2cb, 0x309, 0x317};
    for (u32 i = 0; i < 22; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}
