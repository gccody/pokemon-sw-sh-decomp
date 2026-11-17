// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e67870
void Unk_e67870() {}

// 0x7100e67880
u32 Unk_e67880_get() {
    return 1;
}

struct Unk_e67a00 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e67a00, field_18, 0x18);

void Unk_e67e80(u64);

// 0x7100e67a00
void Unk_e67a00_call(const Unk_e67a00* self) {
    Unk_e67e80(self->field_18);
}

struct Unk_e69de0_5d8 {
    u8 _0[0x30];
    f32 field_30;
    f32 field_34;
    u32 field_38;
    u8 _3c[0x1c];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_58, 0x58);

struct Unk_e69de0 {
    u8 _0[0x5d8];
    Unk_e69de0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_e69de0, field_5d8, 0x5d8);

// 0x7100e69de0
void Unk_e69de0_set(const Unk_e69de0* self, f32 fvalue, f32 farg1) {
    Unk_e69de0_5d8* p0 = self->field_5d8;
    p0->field_30 = fvalue;
    p0->field_34 = farg1;
    p0->field_38 = 0;
    p0->field_58 = p0->field_58 | 0x10;
}
