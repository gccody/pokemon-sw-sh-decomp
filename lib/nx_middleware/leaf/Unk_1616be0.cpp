// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101616be0
u32 Unk_1616be0_get() {
    return 0;
}

// 0x71016180c0
u32 Unk_16180c0_get() {
    return 1;
}

// 0x71016180d0
u32 Unk_16180d0_get() {
    return 1;
}

struct Unk_1618570 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1618570, field_c, 0xc);

// 0x7101618570
void Unk_1618570_set(Unk_1618570* self, u32 value) {
    self->field_c = value;
}

struct Unk_1618830 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1618830, field_0, 0x0);

// 0x7101618830
u32 Unk_1618830_get(const Unk_1618830* self) {
    return self->field_0;
}

struct Unk_1618840 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_1618840, field_4, 0x4);

// 0x7101618840
u32 Unk_1618840_get(const Unk_1618840* self) {
    return self->field_4;
}

struct Unk_1618850 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_1618850, field_c, 0xc);

// 0x7101618850
u32 Unk_1618850_get(const Unk_1618850* self) {
    return self->field_c;
}

struct Unk_1618860 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1618860, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1618860, field_8, 0x8);

// 0x7101618860
void Unk_1618860_set(Unk_1618860* self) {
    self->field_0 = 0;
    self->field_8 = 0;
}

struct Unk_1618a20 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1618a20, field_0, 0x0);

// 0x7101618a20
u32 Unk_1618a20_get(const Unk_1618a20* self) {
    return self->field_0;
}

struct Unk_161cea0 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_161cea0, field_8, 0x8);

// 0x710161cea0
const u8* Unk_161cea0_get(const Unk_161cea0* self) {
    return &self->field_8;
}

// 0x71016224f0
void Unk_16224f0_update() {
}

// 0x71016234f0
void Unk_16234f0_update() {
}
