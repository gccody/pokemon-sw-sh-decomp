// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7fc740 {
    u32 field_0;
    u16 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7fc740, field_4, 0x4);

// 0x71007fc740
void Unk_7fc740_set(Unk_7fc740* self) {
    self->field_4 = 0;
    self->field_0 = 0;
}

struct Unk_7fc7d0 {
    u8 _0[0x4];
    u8 field_4;
    u8 field_5;
};
PKMN_OFFSET_ASSERT(Unk_7fc7d0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7fc7d0, field_5, 0x5);

// 0x71007fc7d0
void Unk_7fc7d0_set(Unk_7fc7d0* self) {
    self->field_4 = self->field_5;
}

struct Unk_7fc7e0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7fc7e0, field_0, 0x0);

// 0x71007fc7e0
void Unk_7fc7e0_set(Unk_7fc7e0* self) {
    self->field_0 = 1;
}

struct Unk_7fc7f0 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7fc7f0, field_0, 0x0);

// 0x71007fc7f0
u8 Unk_7fc7f0_getField0(const Unk_7fc7f0* self) {
    return self->field_0;
}

struct Unk_7fc820 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc820, field_2, 0x2);

// 0x71007fc820
bool Unk_7fc820_check(const Unk_7fc820* self) {
    return self->field_2 == 0;
}

struct Unk_7fc850 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_7fc850, field_1, 0x1);

// 0x71007fc850
u8 Unk_7fc850_getField1(const Unk_7fc850* self) {
    return self->field_1;
}

struct Unk_7fc860 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc860, field_2, 0x2);

// 0x71007fc860
u8 Unk_7fc860_getField2(const Unk_7fc860* self) {
    return self->field_2;
}

struct Unk_7fc8d0 {
    u8 _0[0x1];
    u8 field_1;
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_7fc8d0, field_1, 0x1);
PKMN_OFFSET_ASSERT(Unk_7fc8d0, field_2, 0x2);

// 0x71007fc8d0
bool Unk_7fc8d0_check(const Unk_7fc8d0* self) {
    return self->field_1 <= self->field_2;
}

struct Unk_7fc8f0 {
    u8 _0[0x4];
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7fc8f0, field_4, 0x4);

// 0x71007fc8f0
u8 Unk_7fc8f0_getField4(const Unk_7fc8f0* self) {
    return self->field_4;
}
