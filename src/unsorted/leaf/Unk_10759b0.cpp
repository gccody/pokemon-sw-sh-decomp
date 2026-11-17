// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10759b0 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_10759b0, field_1, 0x1);

// 0x71010759b0
u8 Unk_10759b0_getField1(const Unk_10759b0* self) {
    return self->field_1;
}

struct Unk_10759c0 {
    u8 _0[0x20];
    f32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_10759c0, field_20, 0x20);

// 0x71010759c0
f32 Unk_10759c0_getField20(const Unk_10759c0* self) {
    return self->field_20;
}

struct Unk_1076130 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1076130, field_0, 0x0);

// 0x7101076130
bool Unk_1076130_check(const Unk_1076130* self) {
    return self->field_0 != 0;
}

struct Unk_1076140 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1076140, field_0, 0x0);

// 0x7101076140
u8 Unk_1076140_getField0(const Unk_1076140* self) {
    return self->field_0;
}

struct Unk_1076150 {
    u8 _0[0x1];
    u8 field_1;
};
PKMN_OFFSET_ASSERT(Unk_1076150, field_1, 0x1);

// 0x7101076150
u8 Unk_1076150_getField1(const Unk_1076150* self) {
    return self->field_1;
}

struct Unk_1076160 {
    u8 _0[0x2];
    u8 field_2;
};
PKMN_OFFSET_ASSERT(Unk_1076160, field_2, 0x2);

// 0x7101076160
u8 Unk_1076160_getField2(const Unk_1076160* self) {
    return self->field_2;
}

struct Unk_1076170 {
    u8 _0[0x3];
    u8 field_3;
};
PKMN_OFFSET_ASSERT(Unk_1076170, field_3, 0x3);

// 0x7101076170
u8 Unk_1076170_getField3(const Unk_1076170* self) {
    return self->field_3;
}

struct Unk_1076260 {
    u8 _0[0x10];
    u8 field_10;
};
PKMN_OFFSET_ASSERT(Unk_1076260, field_10, 0x10);

// 0x7101076260
u8* Unk_1076260_getField10Ptr(Unk_1076260* self) {
    return &self->field_10;
}
