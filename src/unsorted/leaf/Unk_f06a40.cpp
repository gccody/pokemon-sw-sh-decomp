// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f06a40 {
    u8 _0[0x98];
    u64 field_98;
    u8 _a0[0x1];
    u8 field_a1;
};
PKMN_OFFSET_ASSERT(Unk_f06a40, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_f06a40, field_a1, 0xa1);

// 0x7100f06a40
void Unk_f06a40_set(Unk_f06a40* self, u64 value) {
    self->field_98 = value;
    self->field_a1 = 1;
}

struct Unk_f07b60 {
    u8 _0[0xa0];
    u8 field_a0;
    u8 _a1[0x2];
    u8 field_a3;
};
PKMN_OFFSET_ASSERT(Unk_f07b60, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_f07b60, field_a3, 0xa3);

void Unk_f06a50();

// 0x7100f07b60
bool Unk_f07b60_call(Unk_f07b60* self) {
    self->field_a3 = 1;
    Unk_f06a50();
    return self->field_a0 == 3;
}

struct Unk_f0cc20_0 {
    u8 _0[0x5d0];
    u64 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc20_0, field_5d0, 0x5d0);

struct Unk_f0cc20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc20_arg1, field_0, 0x0);

struct Unk_f0cc20 {
    Unk_f0cc20_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc20, field_0, 0x0);

// 0x7100f0cc20
void Unk_f0cc20_set(const Unk_f0cc20* self, const Unk_f0cc20_arg1* value) {
    self->field_0->field_5d0 = value->field_0;
}

// 0x7100f0cc30
void Unk_f0cc30_update() {}

struct Unk_f0cc40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc40_arg1, field_0, 0x0);

struct Unk_f0cc40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc40, field_0, 0x0);

// 0x7100f0cc40
void Unk_f0cc40_set(const Unk_f0cc40* self, Unk_f0cc40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f0cc50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc50_arg1, field_0, 0x0);

struct Unk_f0cc50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cc50, field_0, 0x0);

// 0x7100f0cc50
void Unk_f0cc50_set(const Unk_f0cc50* self, Unk_f0cc50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f0cf70_0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_f0cf70_0, field_5cc, 0x5cc);

struct Unk_f0cf70 {
    Unk_f0cf70_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cf70, field_0, 0x0);

// 0x7100f0cf70
void Unk_f0cf70_set(const Unk_f0cf70* self) {
    self->field_0->field_5cc = 2;
}

// 0x7100f0cf80
void Unk_f0cf80_update() {}

struct Unk_f0cf90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cf90_arg1, field_0, 0x0);

struct Unk_f0cf90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cf90, field_0, 0x0);

// 0x7100f0cf90
void Unk_f0cf90_set(const Unk_f0cf90* self, Unk_f0cf90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f0cfa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cfa0_arg1, field_0, 0x0);

struct Unk_f0cfa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0cfa0, field_0, 0x0);

// 0x7100f0cfa0
void Unk_f0cfa0_set(const Unk_f0cfa0* self, Unk_f0cfa0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f0ed70
void Unk_f0ed70_update() {}

struct Unk_f0ed80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0ed80_arg1, field_0, 0x0);

struct Unk_f0ed80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0ed80, field_0, 0x0);

// 0x7100f0ed80
void Unk_f0ed80_set(const Unk_f0ed80* self, Unk_f0ed80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f0ed90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0ed90_arg1, field_0, 0x0);

struct Unk_f0ed90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f0ed90, field_0, 0x0);

// 0x7100f0ed90
void Unk_f0ed90_set(const Unk_f0ed90* self, Unk_f0ed90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f0ffd0 {
    u8 _0[0x100];
    u8 field_100;
    u8 _101[0x4ca];
    u8 field_5cb;
};
PKMN_OFFSET_ASSERT(Unk_f0ffd0, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_f0ffd0, field_5cb, 0x5cb);

void Unk_e82ef0(void*, u32);

// 0x7100f0ffd0
void Unk_f0ffd0_call(Unk_f0ffd0* self) {
    Unk_e82ef0(&self->field_100, 0);
    self->field_5cb = 1;
}

// 0x7100f113c0
void Unk_f113c0_update() {}

struct Unk_f113d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f113d0_arg1, field_0, 0x0);

struct Unk_f113d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f113d0, field_0, 0x0);

// 0x7100f113d0
void Unk_f113d0_set(const Unk_f113d0* self, Unk_f113d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f113e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f113e0_arg1, field_0, 0x0);

struct Unk_f113e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f113e0, field_0, 0x0);

// 0x7100f113e0
void Unk_f113e0_set(const Unk_f113e0* self, Unk_f113e0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f165d0
void Unk_f165d0_update() {}

struct Unk_f165e0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f165e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f165e0, field_8, 0x8);

// 0x7100f165e0
void Unk_f165e0_set(const Unk_f165e0* self, Unk_f165e0* value) {
    *value = *self;
}

struct Unk_f165f0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f165f0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f165f0, field_8, 0x8);

// 0x7100f165f0
void Unk_f165f0_set(const Unk_f165f0* self, Unk_f165f0* value) {
    *value = *self;
}

// 0x7100f16640
void Unk_f16640_update() {}

struct Unk_f16650 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16650, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16650, field_8, 0x8);

// 0x7100f16650
void Unk_f16650_set(const Unk_f16650* self, Unk_f16650* value) {
    *value = *self;
}

struct Unk_f16660 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16660, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16660, field_8, 0x8);

// 0x7100f16660
void Unk_f16660_set(const Unk_f16660* self, Unk_f16660* value) {
    *value = *self;
}

// 0x7100f166b0
void Unk_f166b0_update() {}

struct Unk_f166c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f166c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f166c0, field_8, 0x8);

// 0x7100f166c0
void Unk_f166c0_set(const Unk_f166c0* self, Unk_f166c0* value) {
    *value = *self;
}

struct Unk_f166d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f166d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f166d0, field_8, 0x8);

// 0x7100f166d0
void Unk_f166d0_set(const Unk_f166d0* self, Unk_f166d0* value) {
    *value = *self;
}

// 0x7100f16720
void Unk_f16720_update() {}

struct Unk_f16730 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16730, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16730, field_8, 0x8);

// 0x7100f16730
void Unk_f16730_set(const Unk_f16730* self, Unk_f16730* value) {
    *value = *self;
}

struct Unk_f16740 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16740, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16740, field_8, 0x8);

// 0x7100f16740
void Unk_f16740_set(const Unk_f16740* self, Unk_f16740* value) {
    *value = *self;
}

// 0x7100f16820
void Unk_f16820_update() {}

struct Unk_f16830 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16830, field_8, 0x8);

// 0x7100f16830
void Unk_f16830_set(const Unk_f16830* self, Unk_f16830* value) {
    *value = *self;
}

struct Unk_f16840 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16840, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16840, field_8, 0x8);

// 0x7100f16840
void Unk_f16840_set(const Unk_f16840* self, Unk_f16840* value) {
    *value = *self;
}

// 0x7100f16960
void Unk_f16960_update() {}

struct Unk_f16970 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16970, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16970, field_8, 0x8);

// 0x7100f16970
void Unk_f16970_set(const Unk_f16970* self, Unk_f16970* value) {
    *value = *self;
}

struct Unk_f16980 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16980, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16980, field_8, 0x8);

// 0x7100f16980
void Unk_f16980_set(const Unk_f16980* self, Unk_f16980* value) {
    *value = *self;
}

// 0x7100f16a90
void Unk_f16a90_update() {}

struct Unk_f16aa0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16aa0_arg1, field_0, 0x0);

struct Unk_f16aa0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16aa0, field_0, 0x0);

// 0x7100f16aa0
void Unk_f16aa0_set(const Unk_f16aa0* self, Unk_f16aa0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16ab0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ab0_arg1, field_0, 0x0);

struct Unk_f16ab0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ab0, field_0, 0x0);

// 0x7100f16ab0
void Unk_f16ab0_set(const Unk_f16ab0* self, Unk_f16ab0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16ac0_0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f16ac0_0, field_90, 0x90);

struct Unk_f16ac0 {
    Unk_f16ac0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ac0, field_0, 0x0);

// 0x7100f16ac0
void Unk_f16ac0_set(const Unk_f16ac0* self) {
    self->field_0->field_90 = 4;
}

// 0x7100f16ad0
void Unk_f16ad0_update() {}

struct Unk_f16ae0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ae0_arg1, field_0, 0x0);

struct Unk_f16ae0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ae0, field_0, 0x0);

// 0x7100f16ae0
void Unk_f16ae0_set(const Unk_f16ae0* self, Unk_f16ae0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16af0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16af0_arg1, field_0, 0x0);

struct Unk_f16af0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16af0, field_0, 0x0);

// 0x7100f16af0
void Unk_f16af0_set(const Unk_f16af0* self, Unk_f16af0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16b00_0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f16b00_0, field_90, 0x90);

struct Unk_f16b00 {
    Unk_f16b00_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16b00, field_0, 0x0);

// 0x7100f16b00
void Unk_f16b00_set(const Unk_f16b00* self) {
    self->field_0->field_90 = 1;
}

// 0x7100f16b10
void Unk_f16b10_update() {}

struct Unk_f16b20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16b20_arg1, field_0, 0x0);

struct Unk_f16b20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16b20, field_0, 0x0);

// 0x7100f16b20
void Unk_f16b20_set(const Unk_f16b20* self, Unk_f16b20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16b30_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16b30_arg1, field_0, 0x0);

struct Unk_f16b30 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16b30, field_0, 0x0);

// 0x7100f16b30
void Unk_f16b30_set(const Unk_f16b30* self, Unk_f16b30_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f16c10
void Unk_f16c10_update() {}

struct Unk_f16c20 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16c20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16c20, field_8, 0x8);

// 0x7100f16c20
void Unk_f16c20_set(const Unk_f16c20* self, Unk_f16c20* value) {
    *value = *self;
}

struct Unk_f16c30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16c30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16c30, field_8, 0x8);

// 0x7100f16c30
void Unk_f16c30_set(const Unk_f16c30* self, Unk_f16c30* value) {
    *value = *self;
}

struct Unk_f16c40_0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f16c40_0, field_90, 0x90);

struct Unk_f16c40 {
    Unk_f16c40_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16c40, field_0, 0x0);

// 0x7100f16c40
void Unk_f16c40_set(const Unk_f16c40* self) {
    self->field_0->field_90 = 8;
}

// 0x7100f16c50
void Unk_f16c50_update() {}

struct Unk_f16c60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16c60_arg1, field_0, 0x0);

struct Unk_f16c60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16c60, field_0, 0x0);

// 0x7100f16c60
void Unk_f16c60_set(const Unk_f16c60* self, Unk_f16c60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16c70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16c70_arg1, field_0, 0x0);

struct Unk_f16c70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16c70, field_0, 0x0);

// 0x7100f16c70
void Unk_f16c70_set(const Unk_f16c70* self, Unk_f16c70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f16d60
void Unk_f16d60_update() {}

struct Unk_f16d70 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16d70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16d70, field_8, 0x8);

// 0x7100f16d70
void Unk_f16d70_set(const Unk_f16d70* self, Unk_f16d70* value) {
    *value = *self;
}

struct Unk_f16d80 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16d80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16d80, field_8, 0x8);

// 0x7100f16d80
void Unk_f16d80_set(const Unk_f16d80* self, Unk_f16d80* value) {
    *value = *self;
}

struct Unk_f16d90_0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f16d90_0, field_90, 0x90);

struct Unk_f16d90 {
    Unk_f16d90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16d90, field_0, 0x0);

// 0x7100f16d90
void Unk_f16d90_set(const Unk_f16d90* self) {
    self->field_0->field_90 = 8;
}

// 0x7100f16da0
void Unk_f16da0_update() {}

struct Unk_f16db0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16db0_arg1, field_0, 0x0);

struct Unk_f16db0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16db0, field_0, 0x0);

// 0x7100f16db0
void Unk_f16db0_set(const Unk_f16db0* self, Unk_f16db0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16dc0_arg1, field_0, 0x0);

struct Unk_f16dc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16dc0, field_0, 0x0);

// 0x7100f16dc0
void Unk_f16dc0_set(const Unk_f16dc0* self, Unk_f16dc0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100f16ea0
void Unk_f16ea0_update() {}

struct Unk_f16eb0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16eb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16eb0, field_8, 0x8);

// 0x7100f16eb0
void Unk_f16eb0_set(const Unk_f16eb0* self, Unk_f16eb0* value) {
    *value = *self;
}

struct Unk_f16ec0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_f16ec0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_f16ec0, field_8, 0x8);

// 0x7100f16ec0
void Unk_f16ec0_set(const Unk_f16ec0* self, Unk_f16ec0* value) {
    *value = *self;
}

struct Unk_f16ed0_0 {
    u8 _0[0x90];
    u32 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f16ed0_0, field_90, 0x90);

struct Unk_f16ed0 {
    Unk_f16ed0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ed0, field_0, 0x0);

// 0x7100f16ed0
void Unk_f16ed0_set(const Unk_f16ed0* self) {
    self->field_0->field_90 = 8;
}

// 0x7100f16ee0
void Unk_f16ee0_update() {}

struct Unk_f16ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ef0_arg1, field_0, 0x0);

struct Unk_f16ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16ef0, field_0, 0x0);

// 0x7100f16ef0
void Unk_f16ef0_set(const Unk_f16ef0* self, Unk_f16ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_f16f00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16f00_arg1, field_0, 0x0);

struct Unk_f16f00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_f16f00, field_0, 0x0);

// 0x7100f16f00
void Unk_f16f00_set(const Unk_f16f00* self, Unk_f16f00_arg1* value) {
    value->field_0 = self->field_0;
}
