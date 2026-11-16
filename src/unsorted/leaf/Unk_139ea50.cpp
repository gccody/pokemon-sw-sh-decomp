// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_139ea50 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ea50, field_0, 0x0);

// 0x710139ea50
u32 Unk_139ea50_getField0(const Unk_139ea50* self) {
    return self->field_0;
}

struct Unk_139ffb0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_139ffb0, field_0, 0x0);

// 0x710139ffb0
u32 Unk_139ffb0_getField0(const Unk_139ffb0* self) {
    return self->field_0;
}

struct Unk_13a1200 {
    u8 _0[0x8];
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_13a1200, field_8, 0x8);

// 0x71013a1200
u32 Unk_13a1200_getField8(const Unk_13a1200* self) {
    return self->field_8;
}
