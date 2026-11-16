// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1062350 {
    u8 _0[0xa0];
    u64 field_a0;
};
PKMN_OFFSET_ASSERT(Unk_1062350, field_a0, 0xa0);

// 0x7101062350
u64 Unk_1062350_getFielda0(const Unk_1062350* self) {
    return self->field_a0;
}

struct Unk_1062370 {
    u8 _0[0x2a0];
    u8 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_1062370, field_2a0, 0x2a0);

// 0x7101062370
u8* Unk_1062370_getField2a0Ptr(Unk_1062370* self) {
    return &self->field_2a0;
}

struct Unk_1064e20 {
    u8 _0[0xc0];
    u8 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_1064e20, field_c0, 0xc0);

// 0x7101064e20
u8* Unk_1064e20_getFieldc0Ptr(Unk_1064e20* self) {
    return &self->field_c0;
}
