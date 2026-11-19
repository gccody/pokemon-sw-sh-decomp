// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710069a490
void Unk_69a490_update() {}

struct Unk_69a4a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4a0_arg1, field_0, 0x0);

struct Unk_69a4a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4a0, field_0, 0x0);

// 0x710069a4a0
void Unk_69a4a0_set(const Unk_69a4a0* self, Unk_69a4a0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69a4b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4b0_arg1, field_0, 0x0);

struct Unk_69a4b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a4b0, field_0, 0x0);

// 0x710069a4b0
void Unk_69a4b0_set(const Unk_69a4b0* self, Unk_69a4b0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710069a510
void Unk_69a510_update() {}

struct Unk_69a520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a520_arg1, field_0, 0x0);

struct Unk_69a520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a520, field_0, 0x0);

// 0x710069a520
void Unk_69a520_set(const Unk_69a520* self, Unk_69a520_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69a530_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a530_arg1, field_0, 0x0);

struct Unk_69a530 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_69a530, field_0, 0x0);

// 0x710069a530
void Unk_69a530_set(const Unk_69a530* self, Unk_69a530_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_69bde0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bde0, field_50, 0x50);

void Unk_69a540(u64);

// 0x710069bde0
void Unk_69bde0_call(const Unk_69bde0* self) {
    Unk_69a540(self->field_50);
}

struct Unk_69bdf0_50 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0_50, field_b0, 0xb0);

struct Unk_69bdf0 {
    u8 _0[0x50];
    Unk_69bdf0_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69bdf0, field_50, 0x50);

// 0x710069bdf0
u8 Unk_69bdf0_get(const Unk_69bdf0* self) {
    return self->field_50->field_b0;
}

struct Unk_69c1e0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_69c1e0, field_50, 0x50);

void Unk_69b100(u64);

// 0x710069c1e0
void Unk_69c1e0_call(const Unk_69c1e0* self) {
    Unk_69b100(self->field_50);
}

struct Unk_69c250_50 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_69c250_50, field_68, 0x68);

struct Unk_69c250 {
    u8 _0[0x50];
    Unk_69c250_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69c250, field_50, 0x50);

u32 Unk_418310(u64);

// 0x710069c250
bool Unk_69c250_call(const Unk_69c250* self) {
    u32 r0 = Unk_418310(self->field_50->field_68);
    return r0 == 0;
}
