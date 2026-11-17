// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_987eb0 {
    u8 _0[0x18];
    bool field_18;
};
PKMN_OFFSET_ASSERT(Unk_987eb0, field_18, 0x18);

// 0x7100987eb0
void Unk_987eb0_set(Unk_987eb0* self, bool value) {
    self->field_18 = value;
}

struct Unk_6323a0;
struct Unk_9a59d0 {
    u8 _0[0x10];
    Unk_6323a0* field_10;
};
PKMN_OFFSET_ASSERT(Unk_9a59d0, field_10, 0x10);

void Unk_6323a0_call(const Unk_6323a0*);

// 0x71009a59d0
void Unk_9a59d0_call(const Unk_9a59d0* self) {
    Unk_6323a0_call(self->field_10);
}

struct Unk_9a71a0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a71a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a71a0_arg1, field_8, 0x8);

struct Unk_9a71a0_arg2 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a71a0_arg2, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a71a0_arg2, field_8, 0x8);

struct Unk_9a71a0 {
    u8 _0[0x30];
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u8 _50[0x30];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a71a0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_9a71a0, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_9a71a0, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_9a71a0, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_9a71a0, field_80, 0x80);

// 0x71009a71a0
void Unk_9a71a0_set(Unk_9a71a0* self, const Unk_9a71a0_arg1* value, const Unk_9a71a0_arg2* arg2) {
    self->field_38 = value->field_8;
    self->field_30 = value->field_0;
    self->field_48 = arg2->field_8;
    self->field_40 = arg2->field_0;
    self->field_80 = 1;
}

struct Unk_9a71d0 {
    u8 _0[0x50];
    f32 field_50;
    u8 _54[0x2c];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a71d0, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_9a71d0, field_80, 0x80);

// 0x71009a71d0
void Unk_9a71d0_set(Unk_9a71d0* self, f32 fvalue) {
    self->field_50 = fvalue;
    self->field_80 = 1;
}

struct Unk_9a71e0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a71e0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a71e0_arg1, field_8, 0x8);

struct Unk_9a71e0 {
    u8 _0[0x60];
    u64 field_60;
    u64 field_68;
    u8 _70[0x10];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a71e0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_9a71e0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_9a71e0, field_80, 0x80);

// 0x71009a71e0
void Unk_9a71e0_set(Unk_9a71e0* self, const Unk_9a71e0_arg1* value) {
    self->field_68 = value->field_8;
    self->field_60 = value->field_0;
    self->field_80 = 1;
}

struct Unk_9a7200_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a7200_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a7200_arg1, field_8, 0x8);

struct Unk_9a7200 {
    u8 _0[0x70];
    u64 field_70;
    u64 field_78;
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a7200, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_9a7200, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_9a7200, field_80, 0x80);

// 0x71009a7200
void Unk_9a7200_set(Unk_9a7200* self, const Unk_9a7200_arg1* value) {
    self->field_78 = value->field_8;
    self->field_70 = value->field_0;
    self->field_80 = 1;
}

struct Unk_9a7220 {
    u8 _0[0x58];
    f32 field_58;
    u8 _5c[0x24];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a7220, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_9a7220, field_80, 0x80);

// 0x71009a7220
void Unk_9a7220_set(Unk_9a7220* self, f32 fvalue) {
    self->field_58 = fvalue;
    self->field_80 = 1;
}

struct Unk_9a7230 {
    u8 _0[0x5c];
    f32 field_5c;
    u8 _60[0x20];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a7230, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_9a7230, field_80, 0x80);

// 0x71009a7230
void Unk_9a7230_set(Unk_9a7230* self, f32 fvalue) {
    self->field_5c = fvalue;
    self->field_80 = 1;
}

struct Unk_9a7240 {
    u8 _0[0x54];
    f32 field_54;
    u8 _58[0x28];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_9a7240, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_9a7240, field_80, 0x80);

// 0x71009a7240
void Unk_9a7240_set(Unk_9a7240* self, f32 fvalue) {
    self->field_54 = fvalue;
    self->field_80 = 1;
}

struct Unk_9a78c0 {
    u8 _0[0x100];
    u8 field_100;
};
PKMN_OFFSET_ASSERT(Unk_9a78c0, field_100, 0x100);

// 0x71009a78c0
void Unk_9a78c0_clearField100(Unk_9a78c0* self) {
    self->field_100 = 0;
}

void Unk_9a78d0();

// 0x71009a8a10
void Unk_9a8a10_call() {
    Unk_9a78d0();
}
