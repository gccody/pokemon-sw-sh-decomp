// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ec490 {
    u8 _0[0x20];
    u64 field_20;
    u64 field_28;
    u32 field_30;
    bool field_34;
    u8 _35[0x3];
    u64 field_38;
    u16 field_40;
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_8ec490, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_8ec490, field_42, 0x42);

// 0x71008ec490
void Unk_8ec490_set(Unk_8ec490* self, u64 value, u64 arg2, u32 arg3, bool arg4, u64 arg5) {
    self->field_34 = arg4;
    self->field_20 = value;
    self->field_28 = arg2;
    self->field_30 = arg3;
    self->field_38 = arg5;
    self->field_40 = 1;
    self->field_42 = 0;
}

struct Unk_8ec4c0 {
    u8 _0[0x42];
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_8ec4c0, field_42, 0x42);

// 0x71008ec4c0
u8 Unk_8ec4c0_getField42(const Unk_8ec4c0* self) {
    return self->field_42;
}

struct Unk_8ec4d0_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec4d0_10, field_60, 0x60);

struct Unk_8ec4d0 {
    u8 _0[0x10];
    Unk_8ec4d0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec4d0, field_10, 0x10);

// 0x71008ec4d0
void Unk_8ec4d0_set(const Unk_8ec4d0* self) {
    self->field_10->field_60 = 1;
}

struct Unk_8ec510 {
    u8 _0[0x20];
    u64 field_20;
    u32 field_28;
    bool field_2c;
    u8 _2d[0x3];
    u64 field_30;
    u16 field_38;
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_8ec510, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_8ec510, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_8ec510, field_2c, 0x2c);
PKMN_OFFSET_ASSERT(Unk_8ec510, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_8ec510, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_8ec510, field_3a, 0x3a);

// 0x71008ec510
void Unk_8ec510_set(Unk_8ec510* self, u64 value, u32 arg2, bool arg3, u64 arg4) {
    self->field_2c = arg3;
    self->field_20 = value;
    self->field_28 = arg2;
    self->field_30 = arg4;
    self->field_38 = 1;
    self->field_3a = 0;
}

struct Unk_8ec540 {
    u8 _0[0x3a];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_8ec540, field_3a, 0x3a);

// 0x71008ec540
u8 Unk_8ec540_getField3a(const Unk_8ec540* self) {
    return self->field_3a;
}

struct Unk_8ec550_10 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_8ec550_10, field_60, 0x60);

struct Unk_8ec550 {
    u8 _0[0x10];
    Unk_8ec550_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec550, field_10, 0x10);

// 0x71008ec550
void Unk_8ec550_set(const Unk_8ec550* self) {
    self->field_10->field_60 = 1;
}
