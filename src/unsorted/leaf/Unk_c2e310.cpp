// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_c2e310 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_c2e310, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_c2e310, field_5d8, 0x5d8);

void Unk_1500c40(u64);

// 0x7100c2e310
void Unk_c2e310_call(Unk_c2e310* self) {
    self->field_5d8 = 1;
    if (self->field_4c0 != 0) {
        Unk_1500c40(self->field_4c0);
    }
}

struct Unk_c2e330 {
    u8 _0[0x4c0];
    u64 field_4c0;
    u8 _4c8[0x110];
    u32 field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_c2e330, field_4c0, 0x4c0);
PKMN_OFFSET_ASSERT(Unk_c2e330, field_5d8, 0x5d8);

void Unk_1500c90(u64);

// 0x7100c2e330
void Unk_c2e330_call(Unk_c2e330* self) {
    self->field_5d8 = 0;
    if (self->field_4c0 != 0) {
        Unk_1500c90(self->field_4c0);
    }
}

struct Unk_c2eea0 {
    u8 _0[0x660];
    u64 field_660;
};
PKMN_OFFSET_ASSERT(Unk_c2eea0, field_660, 0x660);

void Unk_eb75e0(u64);

// 0x7100c2eea0
void Unk_c2eea0_call(const Unk_c2eea0* self) {
    Unk_eb75e0(self->field_660);
}

struct Unk_c338a0 {
    u8 _0[0xe8];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_c338a0, field_e8, 0xe8);

// 0x7100c338a0
void Unk_c338a0_set(Unk_c338a0* self) {
    self->field_e8 = 1;
}

struct Unk_c33940 {
    u8 _0[0xea];
    u8 field_ea;
};
PKMN_OFFSET_ASSERT(Unk_c33940, field_ea, 0xea);

// 0x7100c33940
void Unk_c33940_set(Unk_c33940* self) {
    self->field_ea = 1;
}
