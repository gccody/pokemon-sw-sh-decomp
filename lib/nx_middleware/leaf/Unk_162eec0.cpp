// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_162eec0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_162eec0, field_20, 0x20);

// 0x710162eec0
u64 Unk_162eec0_get(const Unk_162eec0* self) {
    return self->field_20;
}

struct Unk_162fe20 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_162fe20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_162fe20, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_162fe20, field_18, 0x18);

u64 Unk_162fa90(void*, void*, u32);

// 0x710162fe20
bool Unk_162fe20_call(Unk_162fe20* self, void* value, u32 arg2) {
    u64 r0 = Unk_162fa90(self, value, arg2);
    self->field_10 = r0;
    self->field_18 = r0 != self->field_8;
    return r0 != self->field_8;
}

struct Unk_162fef0 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_162fef0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_162fef0, field_18, 0x18);

// 0x710162fef0
void Unk_162fef0_set(Unk_162fef0* self, u32 value, u64 arg2) {
    self->field_0 = value;
    self->field_8 = arg2;
    self->field_10 = 0;
    self->field_18 = 0;
}

struct Unk_16305b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_16305b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_16305b0, field_18, 0x18);

// 0x71016305b0
void Unk_16305b0_set(Unk_16305b0* self, u64 value, u64 arg2) {
    self->field_0 = value;
    self->field_8 = arg2;
    self->field_10 = 0;
    self->field_18 = 0;
}

// 0x7101630750
void Unk_1630750_update(u64 /*unused*/, u64 /*unused*/) {
}

struct Unk_1630a10 {
    u8 _0[0x48];
    u16 field_48;
};
PKMN_OFFSET_ASSERT(Unk_1630a10, field_48, 0x48);

// 0x7101630a10
void Unk_1630a10_set(Unk_1630a10* self, u16 value) {
    self->field_48 = value;
}

struct Unk_16323e0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_16323e0, field_60, 0x60);

// 0x71016323e0
void Unk_16323e0_set(Unk_16323e0* self, u32 value) {
    self->field_60 = self->field_60 | value;
}

struct Unk_1633bd0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_1633bd0, field_50, 0x50);

// 0x7101633bd0
void Unk_1633bd0_set(Unk_1633bd0* self, u64 value) {
    self->field_50 = value;
}

struct Unk_1634590_arg1 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1634590_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1634590_arg1, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1634590_arg1, field_10, 0x10);

struct Unk_1634590 {
    u8 _0[0x8];
    u8 field_8;
    u8 _9[0x3];
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1634590, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1634590, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_1634590, field_10, 0x10);

// 0x7101634590
void Unk_1634590_set(Unk_1634590* self, const Unk_1634590_arg1* value) {
    self->field_8 = value->field_8;
    self->field_c = value->field_c;
    self->field_10 = value->field_10;
}

// 0x7101634b90
void Unk_1634b90_update() {
}

// 0x7101634ba0
void Unk_1634ba0_update() {
}

// 0x7101634bb0
void Unk_1634bb0_update() {
}

struct Unk_1637270 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1637270, field_8, 0x8);

// 0x7101637270
u8 Unk_1637270_get(const Unk_1637270* self) {
    return self->field_8;
}
