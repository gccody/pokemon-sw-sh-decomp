// Scope: common
// A packed u32 of five fields (bits 0-12, 13-15, 16-21, 22-24, 25-27) and the
// lookups of a move's counterpart by its type (the TU of
// 0x710082d930-0x710082da60). Unk_82d670.cpp calls them.
#include <types.h>

// 0x710082d930
u32 Unk_82d930(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4) {
    return (arg0 & 7) << 25 | (arg1 & 7) << 22 | (arg2 & 0x3f) << 16 | (arg3 & 7) << 13 |
           (arg4 & 0x1fff);
}

// 0x710082d950
u32 Unk_82d950(u32 value) {
    return (value >> 25) & 7;
}

// 0x710082d960
u32 Unk_82d960(u32 value, u32 field) {
    return (value & ~(7u << 25)) | (field & 7) << 25;
}

// 0x710082d970
u32 Unk_82d970(u32 value) {
    return value & 0x3fffff;
}

// 0x710082d980
s32 Unk_82d980(u32 value) {
    return static_cast<s32>((value >> 16) & 0x3f) - 7;
}

u8 Unk_780d40(u32 move);
u32 Unk_780d70(u32 move);

// 0x710082da30
u32 Unk_82da30(u8 type) {
    switch (type) {
        case 1:
            return 0x2f9;
        case 2:
            return 0x2fe;
        case 3:
            return 0x2fc;
        case 4:
            return 0x303;
        case 5:
            return 0x302;
        case 6:
            return 0x2f6;
        case 7:
            return 0x2fa;
        case 8:
            return 0x306;
        case 9:
            return 0x2f5;
        case 10:
            return 0x2fd;
        case 11:
            return 0x305;
        case 12:
            return 0x2f7;
        case 13:
            return 0x301;
        case 14:
            return 0x2fb;
        case 15:
            return 0x300;
        case 16:
            return 0x304;
        case 17:
            return 0x2ff;
        default:
            return 0x2f8;
    }
}

// 0x710082d9a0
u32 Unk_82d9a0(u32 move) {
    if (move == 0 || move == 0xa5)
        return move;
    if (!Unk_780d70(move))
        return 0x2e7;
    return Unk_82da30(Unk_780d40(move));
}
