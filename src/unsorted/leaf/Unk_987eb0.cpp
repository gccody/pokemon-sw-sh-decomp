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

struct Unk_98aee0_0 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_98aee0_0, field_20, 0x20);

struct Unk_98aee0 {
    Unk_98aee0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_98aee0, field_0, 0x0);

// 0x710098aee0
void Unk_98aee0_set(const Unk_98aee0* self) {
    self->field_0->field_20 = self->field_0->field_20 | 1;
}

// 0x710098af00
void Unk_98af00_update() {}

struct Unk_98af10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_98af10_arg1, field_0, 0x0);

struct Unk_98af10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_98af10, field_0, 0x0);

// 0x710098af10
void Unk_98af10_set(const Unk_98af10* self, Unk_98af10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_98af20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_98af20_arg1, field_0, 0x0);

struct Unk_98af20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_98af20, field_0, 0x0);

// 0x710098af20
void Unk_98af20_set(const Unk_98af20* self, Unk_98af20_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9a4600_0 {
    u8 _0[0x3d0];
    u64 field_3d0;
    u64 field_3d8;
};
PKMN_OFFSET_ASSERT(Unk_9a4600_0, field_3d0, 0x3d0);
PKMN_OFFSET_ASSERT(Unk_9a4600_0, field_3d8, 0x3d8);

struct Unk_9a4600_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a4600_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a4600_arg1, field_8, 0x8);

struct Unk_9a4600 {
    Unk_9a4600_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4600, field_0, 0x0);

// 0x71009a4600
void Unk_9a4600_set(const Unk_9a4600* self, const Unk_9a4600_arg1* value) {
    Unk_9a4600_0* p0 = self->field_0;
    p0->field_3d8 = value->field_8;
    p0->field_3d0 = value->field_0;
}

struct Unk_9a4680_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4680_arg1, field_0, 0x0);

struct Unk_9a4680 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4680, field_0, 0x0);

// 0x71009a4680
void Unk_9a4680_set(Unk_9a4680* self, Unk_9a4680_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_9a4690_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_9a4690_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_9a4690_0, field_3f8, 0x3f8);

struct Unk_9a4690_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a4690_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a4690_arg1, field_8, 0x8);

struct Unk_9a4690 {
    Unk_9a4690_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4690, field_0, 0x0);

// 0x71009a4690
void Unk_9a4690_set(const Unk_9a4690* self, const Unk_9a4690_arg1* value) {
    Unk_9a4690_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

struct Unk_9a4710_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4710_arg1, field_0, 0x0);

struct Unk_9a4710 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4710, field_0, 0x0);

// 0x71009a4710
void Unk_9a4710_set(Unk_9a4710* self, Unk_9a4710_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_9a4720_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_9a4720_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_9a4720_0, field_3c8, 0x3c8);

struct Unk_9a4720_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a4720_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a4720_arg1, field_8, 0x8);

struct Unk_9a4720 {
    Unk_9a4720_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4720, field_0, 0x0);

// 0x71009a4720
void Unk_9a4720_set(const Unk_9a4720* self, const Unk_9a4720_arg1* value) {
    Unk_9a4720_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

struct Unk_9a47a0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a47a0_arg1, field_0, 0x0);

struct Unk_9a47a0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a47a0, field_0, 0x0);

// 0x71009a47a0
void Unk_9a47a0_set(Unk_9a47a0* self, Unk_9a47a0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_9a47b0_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_9a47b0_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_9a47b0_0, field_3c8, 0x3c8);

struct Unk_9a47b0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a47b0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a47b0_arg1, field_8, 0x8);

struct Unk_9a47b0 {
    Unk_9a47b0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a47b0, field_0, 0x0);

// 0x71009a47b0
void Unk_9a47b0_set(const Unk_9a47b0* self, const Unk_9a47b0_arg1* value) {
    Unk_9a47b0_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

struct Unk_9a4830_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4830_arg1, field_0, 0x0);

struct Unk_9a4830 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4830, field_0, 0x0);

// 0x71009a4830
void Unk_9a4830_set(Unk_9a4830* self, Unk_9a4830_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_9a4840_0 {
    u8 _0[0x3c0];
    u64 field_3c0;
    u64 field_3c8;
};
PKMN_OFFSET_ASSERT(Unk_9a4840_0, field_3c0, 0x3c0);
PKMN_OFFSET_ASSERT(Unk_9a4840_0, field_3c8, 0x3c8);

struct Unk_9a4840_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a4840_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a4840_arg1, field_8, 0x8);

struct Unk_9a4840 {
    Unk_9a4840_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4840, field_0, 0x0);

// 0x71009a4840
void Unk_9a4840_set(const Unk_9a4840* self, const Unk_9a4840_arg1* value) {
    Unk_9a4840_0* p0 = self->field_0;
    p0->field_3c8 = value->field_8;
    p0->field_3c0 = value->field_0;
}

struct Unk_9a48c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a48c0_arg1, field_0, 0x0);

struct Unk_9a48c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a48c0, field_0, 0x0);

// 0x71009a48c0
void Unk_9a48c0_set(Unk_9a48c0* self, Unk_9a48c0_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_9a48d0_0 {
    u8 _0[0x3f0];
    u64 field_3f0;
    u64 field_3f8;
};
PKMN_OFFSET_ASSERT(Unk_9a48d0_0, field_3f0, 0x3f0);
PKMN_OFFSET_ASSERT(Unk_9a48d0_0, field_3f8, 0x3f8);

struct Unk_9a48d0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9a48d0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9a48d0_arg1, field_8, 0x8);

struct Unk_9a48d0 {
    Unk_9a48d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a48d0, field_0, 0x0);

// 0x71009a48d0
void Unk_9a48d0_set(const Unk_9a48d0* self, const Unk_9a48d0_arg1* value) {
    Unk_9a48d0_0* p0 = self->field_0;
    p0->field_3f8 = value->field_8;
    p0->field_3f0 = value->field_0;
}

// 0x71009a48f0
void Unk_9a48f0_update() {}

struct Unk_9a4900_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4900_arg1, field_0, 0x0);

struct Unk_9a4900 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4900, field_0, 0x0);

// 0x71009a4900
void Unk_9a4900_set(const Unk_9a4900* self, Unk_9a4900_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9a4910_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4910_arg1, field_0, 0x0);

struct Unk_9a4910 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9a4910, field_0, 0x0);

// 0x71009a4910
void Unk_9a4910_set(const Unk_9a4910* self, Unk_9a4910_arg1* value) {
    value->field_0 = self->field_0;
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

// 0x71009ae1b0
void Unk_9ae1b0_update() {}

struct Unk_9ae1c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9ae1c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9ae1c0, field_8, 0x8);

// 0x71009ae1c0
void Unk_9ae1c0_set(const Unk_9ae1c0* self, Unk_9ae1c0* value) {
    *value = *self;
}

struct Unk_9ae1d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9ae1d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9ae1d0, field_8, 0x8);

// 0x71009ae1d0
void Unk_9ae1d0_set(const Unk_9ae1d0* self, Unk_9ae1d0* value) {
    *value = *self;
}

// 0x71009ae3b0
void Unk_9ae3b0_update() {}

struct Unk_9ae3c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9ae3c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9ae3c0, field_8, 0x8);

// 0x71009ae3c0
void Unk_9ae3c0_set(const Unk_9ae3c0* self, Unk_9ae3c0* value) {
    *value = *self;
}

struct Unk_9ae3d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_9ae3d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9ae3d0, field_8, 0x8);

// 0x71009ae3d0
void Unk_9ae3d0_set(const Unk_9ae3d0* self, Unk_9ae3d0* value) {
    *value = *self;
}
