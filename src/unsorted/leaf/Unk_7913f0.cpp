// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7913f0_arg4 {
    u8 _0[0xd];
    u8 field_d;
};
PKMN_OFFSET_ASSERT(Unk_7913f0_arg4, field_d, 0xd);

// 0x71007913f0
void Unk_7913f0_set(void* /*unused*/,
                    u32 /*unused*/,
                    u32 /*unused*/,
                    bool arg3,
                    Unk_7913f0_arg4* arg4) {
    if (arg4 != nullptr) {
        if ((arg3) == 0)
            return;
        arg4->field_d = 0;
    }
}

struct Unk_791550_arg4 {
    u8 _0[0xe];
    u8 field_e;
};
PKMN_OFFSET_ASSERT(Unk_791550_arg4, field_e, 0xe);

// 0x7100791550
void Unk_791550_set(void* /*unused*/,
                    u32 /*unused*/,
                    u32 /*unused*/,
                    bool arg3,
                    Unk_791550_arg4* arg4) {
    if (arg4 != nullptr) {
        if ((arg3) == 0)
            return;
        arg4->field_e = 0;
    }
}
