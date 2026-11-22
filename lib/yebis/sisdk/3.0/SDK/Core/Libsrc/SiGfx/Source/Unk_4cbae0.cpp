// Scope: common
// Two functions between two static initialisers (placeholder file and
// names; the first one, 0x71004cbae0, isn't written).
#include <types.h>

// 0x71004cbc40: compares two versions of four numbers each (-1, 0 or 1)
s32 Unk_4cbc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 b0, s32 b1, s32 b2, s32 b3) {
    if (a0 < b0) {
        return -1;
    }
    if (a0 > b0) {
        return 1;
    }
    if (a1 < b1) {
        return -1;
    }
    if (a1 > b1) {
        return 1;
    }
    if (a2 < b2) {
        return -1;
    }
    if (a2 > b2) {
        return 1;
    }
    if (a3 < b3) {
        return -1;
    }
    return a3 > b3;
}
