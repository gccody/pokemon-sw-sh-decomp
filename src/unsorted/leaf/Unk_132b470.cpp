// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_132b470 {
    u8 _0[0x5f8];
    u64 field_5f8;
};
PKMN_OFFSET_ASSERT(Unk_132b470, field_5f8, 0x5f8);

void Unk_14e1a30(u64, u32);

// 0x710132b470
void Unk_132b470_call(const Unk_132b470* self, bool value) {
    if (self->field_5f8 != 0) {
        Unk_14e1a30(self->field_5f8, value);
    }
}

struct Unk_132b9f0_0 {
    u8 _0[0x5e8];
    u8 field_5e8;
    u8 _5e9[0x3];
    u32 field_5ec;
};
PKMN_OFFSET_ASSERT(Unk_132b9f0_0, field_5e8, 0x5e8);
PKMN_OFFSET_ASSERT(Unk_132b9f0_0, field_5ec, 0x5ec);

struct Unk_132b9f0 {
    Unk_132b9f0_0* field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_132b9f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132b9f0, field_8, 0x8);

// 0x710132b9f0
void Unk_132b9f0_set(const Unk_132b9f0* self) {
    Unk_132b9f0_0* p0 = self->field_0;
    p0->field_5ec = self->field_8;
    p0->field_5e8 = 1;
}

// 0x710132ba10
void Unk_132ba10_update() {}

struct Unk_132ba20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_132ba20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132ba20, field_8, 0x8);

// 0x710132ba20
void Unk_132ba20_set(const Unk_132ba20* self, Unk_132ba20* value) {
    *value = *self;
}

struct Unk_132ba30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_132ba30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_132ba30, field_8, 0x8);

// 0x710132ba30
void Unk_132ba30_set(const Unk_132ba30* self, Unk_132ba30* value) {
    *value = *self;
}
