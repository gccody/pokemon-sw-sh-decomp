// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3dfe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3dfe0_arg1, field_0, 0x0);

struct Unk_e3dfe0 {
    u8 _0[0x90];
    u32 field_90;
    u8 _94[0x4];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_e3dfe0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_e3dfe0, field_98, 0x98);

// 0x7100e3dfe0
void Unk_e3dfe0_set(Unk_e3dfe0* self, const Unk_e3dfe0_arg1* value) {
    self->field_90 = 2;
    self->field_98 = value->field_0;
}

struct Unk_e3e3b0 {
    u8 _0[0x1a0];
    u32 field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_e3e3b0, field_1a0, 0x1a0);

// 0x7100e3e3b0
bool Unk_e3e3b0_check(const Unk_e3e3b0* self) {
    return self->field_1a0 != 0xfffffffe;
}

struct Unk_e3efd0_60 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_e3efd0_60, field_140, 0x140);

struct Unk_e3efd0 {
    u8 _0[0x60];
    Unk_e3efd0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e3efd0, field_60, 0x60);

// 0x7100e3efd0
void Unk_e3efd0_set(const Unk_e3efd0* self) {
    self->field_60->field_140 = 0xb5;
}
