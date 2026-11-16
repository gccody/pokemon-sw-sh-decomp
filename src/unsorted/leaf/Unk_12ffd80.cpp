// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_12ffd80 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_12ffd80, field_8, 0x8);

// 0x71012ffd80
u32 Unk_12ffd80_getField8(const Unk_12ffd80* self) {
    return self->field_8;
}

struct Unk_1305db0 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1305db0, field_58, 0x58);

// 0x7101305db0
u64 Unk_1305db0_getField58(const Unk_1305db0* self) {
    return self->field_58;
}

// 0x710130abe0
void Unk_130abe0() {}
