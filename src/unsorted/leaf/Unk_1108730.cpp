// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1108730 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108730, field_58, 0x58);

// 0x7101108730
u64 Unk_1108730_getField58(const Unk_1108730* self) {
    return self->field_58;
}

struct Unk_110ca80 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_110ca80, field_120, 0x120);

// 0x710110ca80
u32 Unk_110ca80_getField120(const Unk_110ca80* self) {
    return self->field_120;
}

struct Unk_110ca90 {
    u8 _0[0x124];
    u32 field_124;
};
PKMN_OFFSET_ASSERT(Unk_110ca90, field_124, 0x124);

// 0x710110ca90
u32 Unk_110ca90_getField124(const Unk_110ca90* self) {
    return self->field_124;
}
