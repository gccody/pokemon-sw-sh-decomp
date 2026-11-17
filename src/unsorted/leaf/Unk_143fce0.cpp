// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_143fce0 {
    u8 _0[0x700];
    u64 field_700;
};
PKMN_OFFSET_ASSERT(Unk_143fce0, field_700, 0x700);

// 0x710143fce0
void Unk_143fce0_setField700(Unk_143fce0* self, u64 value) {
    self->field_700 = value;
}

void Unk_eb6230(void*, u32);

// 0x7101442c40
void Unk_1442c40_call(void* self) {
    Unk_eb6230(self, 3);
}

struct Unk_1443160 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u32 field_20;
    u8 _24[0x4];
    u64 field_28;
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_1443160, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1443160, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1443160, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1443160, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1443160, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1443160, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_1443160, field_30, 0x30);

// 0x7101443160
void Unk_1443160_set(Unk_1443160* self) {
    self->field_20 = 0;
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_28 = 0;
    self->field_30 = 0;
}

struct Unk_1443df0 {
    u8 _0[0x20];
    u8 field_20;
    u8 _21[0x1];
    u16 field_22;
};
PKMN_OFFSET_ASSERT(Unk_1443df0, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_1443df0, field_22, 0x22);

// 0x7101443df0
u16 Unk_1443df0_get(const Unk_1443df0* self) {
    if (self->field_20 == 0) {
        return 0xffff;
    }
    return self->field_22;
}

struct Unk_1448b60 {
    u8 _0[0x3198];
    u64 field_3198;
};
PKMN_OFFSET_ASSERT(Unk_1448b60, field_3198, 0x3198);

void Unk_14bacd0(u64);

// 0x7101448b60
void Unk_1448b60_call(const Unk_1448b60* self) {
    Unk_14bacd0(self->field_3198);
}
