// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ee79c0_58 {
    u8 _0[0x198];
    u8 field_198;
};
PKMN_OFFSET_ASSERT(Unk_ee79c0_58, field_198, 0x198);

struct Unk_ee79c0 {
    u8 _0[0x58];
    Unk_ee79c0_58* field_58;
};
PKMN_OFFSET_ASSERT(Unk_ee79c0, field_58, 0x58);

// 0x7100ee79c0
u8* Unk_ee79c0_get(const Unk_ee79c0* self) {
    return &self->field_58->field_198;
}

// 0x7100ee79d0
void Unk_ee79d0() {}

struct Unk_eeb410 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_eeb410, field_0, 0x0);

// 0x7100eeb410
u32 Unk_eeb410_getField0(const Unk_eeb410* self) {
    return self->field_0;
}

struct Unk_efcb80 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_efcb80, field_6c, 0x6c);

// 0x7100efcb80
void Unk_efcb80_setField6c(Unk_efcb80* self, u32 value) {
    self->field_6c = value;
}

struct Unk_efd570 {
    u8 _0[0x720];
    u64 field_720;
};
PKMN_OFFSET_ASSERT(Unk_efd570, field_720, 0x720);

// 0x7100efd570
void Unk_efd570_setField720(Unk_efd570* self, u64 value) {
    self->field_720 = value;
}
