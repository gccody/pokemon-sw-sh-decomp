// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007c5070
void Unk_7c5070() {}

struct Unk_7ca070 {
    u8 _0[0x166];
    u16 field_166;
};
PKMN_OFFSET_ASSERT(Unk_7ca070, field_166, 0x166);

// 0x71007ca070
u16 Unk_7ca070_getField166(const Unk_7ca070* self) {
    return self->field_166;
}

struct Unk_7ca1c0 {
    u8 _0[0x150];
    u32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_7ca1c0, field_150, 0x150);

// 0x71007ca1c0
u32 Unk_7ca1c0_getField150(const Unk_7ca1c0* self) {
    return self->field_150;
}

struct Unk_7cb850 {
    u8 _0[0x174];
    u8 field_174;
};
PKMN_OFFSET_ASSERT(Unk_7cb850, field_174, 0x174);

// 0x71007cb850
u8 Unk_7cb850_getField174(const Unk_7cb850* self) {
    return self->field_174;
}

struct Unk_7cbc20 {
    u8 _0[0x170];
    u32 field_170;
};
PKMN_OFFSET_ASSERT(Unk_7cbc20, field_170, 0x170);

// 0x71007cbc20
u32 Unk_7cbc20_getField170(const Unk_7cbc20* self) {
    return self->field_170;
}

// 0x71007cc160
void Unk_7cc160() {}

struct Unk_7cc3c0 {
    u8 _0[0x168];
    u16 field_168;
};
PKMN_OFFSET_ASSERT(Unk_7cc3c0, field_168, 0x168);

// 0x71007cc3c0
u16 Unk_7cc3c0_getField168(const Unk_7cc3c0* self) {
    return self->field_168;
}

struct Unk_7cc400 {
    u8 _0[0x164];
    u16 field_164;
};
PKMN_OFFSET_ASSERT(Unk_7cc400, field_164, 0x164);

// 0x71007cc400
u16 Unk_7cc400_getField164(const Unk_7cc400* self) {
    return self->field_164;
}
