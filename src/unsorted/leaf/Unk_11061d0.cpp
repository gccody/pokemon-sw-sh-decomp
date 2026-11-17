// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11061d0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061d0, field_8, 0x8);

// 0x71011061d0
void Unk_11061d0_set(Unk_11061d0* self) {
    self->field_0 = 0;
    self->field_8 = 0xffffffff;
}

struct Unk_11061e0_arg1 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061e0_arg1, field_8, 0x8);

struct Unk_11061e0 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_11061e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11061e0, field_8, 0x8);

// 0x71011061e0
void Unk_11061e0_set(Unk_11061e0* self, const Unk_11061e0_arg1* value) {
    self->field_0 = 0;
    self->field_8 = 0xffffffff;
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
}

struct Unk_1106200_arg1 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1106200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1106200_arg1, field_8, 0x8);

struct Unk_1106200 {
    u64 field_0;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1106200, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1106200, field_8, 0x8);

// 0x7101106200
void Unk_1106200_set(Unk_1106200* self, const Unk_1106200_arg1* value) {
    self->field_0 = value->field_0;
    self->field_8 = value->field_8;
}

struct Unk_767720;
struct Unk_1108720 {
    u8 _0[0x58];
    Unk_767720* field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108720, field_58, 0x58);

void Unk_767720_call(const Unk_767720*);

// 0x7101108720
void Unk_1108720_call(const Unk_1108720* self) {
    Unk_767720_call(self->field_58);
}

struct Unk_1108730 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108730, field_58, 0x58);

// 0x7101108730
u64 Unk_1108730_getField58(const Unk_1108730* self) {
    return self->field_58;
}

struct Unk_1108a70 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_1108a70, field_58, 0x58);

void Unk_763030(u64);

// 0x7101108a70
void Unk_1108a70_call(const Unk_1108a70* self) {
    Unk_763030(self->field_58);
}

struct Unk_110ca80 {
    u8 _0[0x120];
    u32 field_120;
};
PKMN_OFFSET_ASSERT(Unk_110ca80, field_120, 0x120);

// 0x710110ca80
u32 Unk_110ca80_getField120(const Unk_110ca80* self) {
    return self->field_120;
}

struct Unk_110ca90 {
    u8 _0[0x124];
    u32 field_124;
};
PKMN_OFFSET_ASSERT(Unk_110ca90, field_124, 0x124);

// 0x710110ca90
u32 Unk_110ca90_getField124(const Unk_110ca90* self) {
    return self->field_124;
}

struct Unk_110caa0 {
    u8 _0[0x120];
    u32 field_120;
    u32 field_124;
};
PKMN_OFFSET_ASSERT(Unk_110caa0, field_120, 0x120);
PKMN_OFFSET_ASSERT(Unk_110caa0, field_124, 0x124);

// 0x710110caa0
void Unk_110caa0_set(Unk_110caa0* self, u32 value, u32 arg2) {
    self->field_124 = value;
    self->field_120 = arg2;
}
