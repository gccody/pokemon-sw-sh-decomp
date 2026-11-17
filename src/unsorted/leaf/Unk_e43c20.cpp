// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e43c20
void Unk_e43c20() {}

struct Unk_e44e00 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_e44e00, field_90, 0x90);

// 0x7100e44e00
bool Unk_e44e00_check(const Unk_e44e00* self) {
    return self->field_90 != 0;
}

struct Unk_e47200 {
    u8 _0[0x54];
    u32 field_54;
    u8 field_58;
    u8 _59[0x2];
    bool field_5b;
    u32 field_5c;
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_e47200, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_e47200, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_e47200, field_5b, 0x5b);
PKMN_OFFSET_ASSERT(Unk_e47200, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_e47200, field_60, 0x60);

// 0x7100e47200
void Unk_e47200_set(Unk_e47200* self, u32 value, bool arg2) {
    self->field_5c = 0;
    self->field_60 = value;
    self->field_58 = 0;
    self->field_54 = 1;
    self->field_5b = arg2;
}

void Unk_e4c3c0();

// 0x7100e4c3b0
void Unk_e4c3b0_call() {
    Unk_e4c3c0();
}

// 0x7100e4cc50
void Unk_e4cc50() {}

struct Unk_e51bf0 {
    u8 _0[0x1c8];
    u8 field_1c8;
};
PKMN_OFFSET_ASSERT(Unk_e51bf0, field_1c8, 0x1c8);

// 0x7100e51bf0
void Unk_e51bf0_setField1c8(Unk_e51bf0* self, u8 value) {
    self->field_1c8 = value;
}

struct Unk_e51c00 {
    u8 _0[0x1c9];
    u8 field_1c9;
};
PKMN_OFFSET_ASSERT(Unk_e51c00, field_1c9, 0x1c9);

// 0x7100e51c00
void Unk_e51c00_setField1c9(Unk_e51c00* self, u8 value) {
    self->field_1c9 = value;
}
