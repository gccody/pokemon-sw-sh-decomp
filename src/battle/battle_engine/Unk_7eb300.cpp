// Scope: common
// Value classifiers (0x71007eb300 to 0x71007eb5b0): small range and set
// tests on 16-bit IDs. Placeholder names: rename once the functions are known.
#include <types.h>

extern const u16 Unk_1f109a8[70] __attribute__((visibility("hidden")));

// 0x71007eb300
bool Unk_7eb300(u16 value) {
    switch (value) {
        case 9:
        case 10:
        case 15:
        case 16:
            return true;
    }
    return false;
}

// 0x71007eb330
bool Unk_7eb330(u16 value) {
    return value >= 0x206 && value <= 0x208;
}

// NON_MATCHING: block layout: the original places the table load before the
// value == 0x17 fallback (tbz instead of tbnz).
// 0x71007eb350
u32 Unk_7eb350(u16 value) {
    switch (value) {
        case 0x12:
        case 0x13:
            return 1;
        case 0x16:
            return 2;
        case 0x1b:
            return 3;
        case 0x11:
        case 0x18:
        case 0x19:
            return 4;
        case 0x14:
        case 0x15:
            return 5;
    }
    return value == 0x17 ? 6 : 0;
}

// 0x71007eb3a0
bool Unk_7eb3a0(u16 value) {
    static const u16 kValues[] = {0xdc, 0x129, 0x11f};
    for (u32 i = 0; i < 3; i++) {
        if (kValues[i] == value)
            return true;
    }
    return false;
}

// 0x71007eb3d0
bool Unk_7eb3d0(u32 value) {
    switch (static_cast<u16>(value)) {
        case 0x3b:
        case 0x79:
        case 0x7a:
        case 0x95:
        case 0x96:
        case 0xa1:
        case 0xb0:
        case 0xc5:
        case 0xd0:
        case 0xd1:
        case 0xd2:
        case 0xd3:
        case 0xd5:
        case 0xde:
        case 0xdf:
        case 0xe1:
        case 0xf1:
        case 0xf8:
        case 0x100:
        case 0x102:
            return true;
    }
    static const u16 kValues[] = {0x24, 0x19};
    for (u32 i = 0; i < 2; i++) {
        if (kValues[i] == static_cast<u16>(value))
            return true;
    }
    return false;
}

// 0x71007eb420
bool Unk_7eb420(u32 value) {
    switch (static_cast<u16>(value)) {
        case 0x79:
        case 0xa1:
        case 0xb0:
        case 0xc5:
        case 0xd0:
        case 0xd1:
        case 0xd2:
        case 0xd3:
        case 0xd5:
        case 0xe1:
        case 0xf1:
        case 0xf8:
            return true;
    }
    return false;
}

// 0x71007eb4b0
bool Unk_7eb4b0(u16 value) {
    switch (value) {
        case 0x19:
        case 0x79:
        case 0x95:
        case 0xa1:
        case 0xb0:
        case 0xc5:
        case 0xd0:
        case 0xd1:
        case 0xd2:
        case 0xd3:
        case 0xd5:
        case 0xe1:
        case 0xf1:
        case 0xf8:
        case 0x100:
        case 0x102:
            return true;
    }
    return false;
}

// NON_MATCHING: the 0x284 test selects with the inverted condition
// (csel wzr, w9, ne instead of csel w9, wzr, eq).
// 0x71007eb4f0
bool Unk_7eb4f0(u16 item) {
    switch (item) {
        case 0x12a:
        case 0x12b:
        case 0x12c:
        case 0x12d:
        case 0x12e:
        case 0x12f:
        case 0x130:
        case 0x131:
        case 0x132:
        case 0x133:
        case 0x134:
        case 0x135:
        case 0x136:
        case 0x137:
        case 0x138:
        case 0x139:
        case 0x284:
            return true;
    }
    return false;
}

// 0x71007eb510
bool Unk_7eb510(u16 item) {
    return item >= 0x388 && item <= 0x398;
}

// 0x71007eb530
bool Unk_7eb530(u16 item) {
    return item >= 0x74 && item <= 0x77;
}

// 0x71007eb540
bool Unk_7eb540(u16 value) {
    for (u32 i = 0; i < 70; i++) {
        if (Unk_1f109a8[i] == value)
            return true;
    }
    return false;
}

// 0x71007eb590
bool Unk_7eb590(u16 value) {
    switch (value) {
        case 0xd1:
        case 0xf1:
        case 0xf8:
        case 0x100:
        case 0x102:
            return true;
    }
    return false;
}
