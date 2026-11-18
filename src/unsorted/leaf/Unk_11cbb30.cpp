// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_112e3e0(void*, u32);

// 0x71011cbb30
void Unk_11cbb30_call(void* self) {
    Unk_112e3e0(self, 0);
}

struct Unk_11cc3a0 {
    u8 _0[0x2bc];
    u32 field_2bc;
};
PKMN_OFFSET_ASSERT(Unk_11cc3a0, field_2bc, 0x2bc);

// 0x71011cc3a0
void Unk_11cc3a0_setField2bc(Unk_11cc3a0* self, u32 value) {
    self->field_2bc = value;
}

struct Unk_11cd2e0 {
    u8 _0[0xb8];
    u32 field_b8;
};
PKMN_OFFSET_ASSERT(Unk_11cd2e0, field_b8, 0xb8);

// 0x71011cd2e0
void Unk_11cd2e0_setFieldb8(Unk_11cd2e0* self, u32 value) {
    self->field_b8 = value;
}

struct Unk_11ceb20 {
    u8 _0[0xb0];
    bool field_b0;
};
PKMN_OFFSET_ASSERT(Unk_11ceb20, field_b0, 0xb0);

// 0x71011ceb20
void Unk_11ceb20_set(Unk_11ceb20* self, bool value) {
    self->field_b0 = value;
}

struct Unk_11d18f0 {
    u8 _0[0xb0];
    f32 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_11d18f0, field_b0, 0xb0);

// 0x71011d18f0
f32 Unk_11d18f0_getFieldb0(const Unk_11d18f0* self) {
    return self->field_b0;
}

struct Unk_11d2670 {
    u8 _0[0x81];
    u8 field_81;
};
PKMN_OFFSET_ASSERT(Unk_11d2670, field_81, 0x81);

// 0x71011d2670
u8 Unk_11d2670_getField81(const Unk_11d2670* self) {
    return self->field_81;
}

struct Unk_11d2680 {
    u8 _0[0x82];
    u8 field_82;
};
PKMN_OFFSET_ASSERT(Unk_11d2680, field_82, 0x82);

// 0x71011d2680
u8 Unk_11d2680_getField82(const Unk_11d2680* self) {
    return self->field_82;
}

struct Unk_11d2690 {
    u8 _0[0x7c];
    u32 field_7c;
};
PKMN_OFFSET_ASSERT(Unk_11d2690, field_7c, 0x7c);

// 0x71011d2690
u32 Unk_11d2690_getField7c(const Unk_11d2690* self) {
    return self->field_7c;
}

struct Unk_11d26a0 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_11d26a0, field_80, 0x80);

// 0x71011d26a0
u8 Unk_11d26a0_getField80(const Unk_11d26a0* self) {
    return self->field_80;
}

struct Unk_11d26b0 {
    u8 _0[0x80];
    bool field_80;
};
PKMN_OFFSET_ASSERT(Unk_11d26b0, field_80, 0x80);

// 0x71011d26b0
void Unk_11d26b0_set(Unk_11d26b0* self, bool value) {
    self->field_80 = value;
}

struct Unk_11d4500 {
    u8 _0[0xd8];
    u32 field_d8;
    u8 _dc[0x118];
    u32 field_1f4;
    u32 field_1f8;
    f32 field_1fc;
};
PKMN_OFFSET_ASSERT(Unk_11d4500, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_11d4500, field_1f4, 0x1f4);
PKMN_OFFSET_ASSERT(Unk_11d4500, field_1f8, 0x1f8);
PKMN_OFFSET_ASSERT(Unk_11d4500, field_1fc, 0x1fc);

// 0x71011d4500
void Unk_11d4500_set(Unk_11d4500* self, f32 fvalue) {
    self->field_1f4 = 0x3e03126f;
    self->field_1f8 = self->field_d8;
    self->field_1fc = fvalue;
}

struct Unk_11d7390 {
    u8 _0[0x150];
    f32 field_150;
};
PKMN_OFFSET_ASSERT(Unk_11d7390, field_150, 0x150);

// 0x71011d7390
f32 Unk_11d7390_getField150(const Unk_11d7390* self) {
    return self->field_150;
}

struct Unk_11d73a0 {
    u8 _0[0x224];
    u8 field_224;
};
PKMN_OFFSET_ASSERT(Unk_11d73a0, field_224, 0x224);

// 0x71011d73a0
u8 Unk_11d73a0_getField224(const Unk_11d73a0* self) {
    return self->field_224;
}

// 0x71011d7630
void Unk_11d7630_update() {}

struct Unk_11d7640 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11d7640, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11d7640, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11d7640, field_10, 0x10);

// 0x71011d7640
void Unk_11d7640_set(const Unk_11d7640* self, Unk_11d7640* value) {
    *value = *self;
}

struct Unk_11d7660 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11d7660, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11d7660, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11d7660, field_10, 0x10);

// 0x71011d7660
void Unk_11d7660_set(const Unk_11d7660* self, Unk_11d7660* value) {
    *value = *self;
}

// 0x71011d7750
void Unk_11d7750_update() {}

struct Unk_11d7760_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11d7760_arg1, field_0, 0x0);

struct Unk_11d7760 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11d7760, field_0, 0x0);

// 0x71011d7760
void Unk_11d7760_set(const Unk_11d7760* self, Unk_11d7760_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11d7770_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11d7770_arg1, field_0, 0x0);

struct Unk_11d7770 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11d7770, field_0, 0x0);

// 0x71011d7770
void Unk_11d7770_set(const Unk_11d7770* self, Unk_11d7770_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011db8d0
void Unk_11db8d0_update() {}

struct Unk_11db8e0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11db8e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11db8e0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11db8e0, field_10, 0x10);

// 0x71011db8e0
void Unk_11db8e0_set(const Unk_11db8e0* self, Unk_11db8e0* value) {
    *value = *self;
}

struct Unk_11db900 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11db900, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11db900, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11db900, field_10, 0x10);

// 0x71011db900
void Unk_11db900_set(const Unk_11db900* self, Unk_11db900* value) {
    *value = *self;
}

// 0x71011e1220
void Unk_11e1220_update() {}

struct Unk_11e1230 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11e1230, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e1230, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11e1230, field_10, 0x10);

// 0x71011e1230
void Unk_11e1230_set(const Unk_11e1230* self, Unk_11e1230* value) {
    *value = *self;
}

struct Unk_11e1250 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11e1250, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e1250, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11e1250, field_10, 0x10);

// 0x71011e1250
void Unk_11e1250_set(const Unk_11e1250* self, Unk_11e1250* value) {
    *value = *self;
}

// 0x71011e1ea0
void Unk_11e1ea0_update() {}

struct Unk_11e1eb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1eb0_arg1, field_0, 0x0);

struct Unk_11e1eb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1eb0, field_0, 0x0);

// 0x71011e1eb0
void Unk_11e1eb0_set(const Unk_11e1eb0* self, Unk_11e1eb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e1ec0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1ec0_arg1, field_0, 0x0);

struct Unk_11e1ec0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1ec0, field_0, 0x0);

// 0x71011e1ec0
void Unk_11e1ec0_set(const Unk_11e1ec0* self, Unk_11e1ec0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011e1f30
void Unk_11e1f30_update() {}

struct Unk_11e1f40_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1f40_arg1, field_0, 0x0);

struct Unk_11e1f40 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1f40, field_0, 0x0);

// 0x71011e1f40
void Unk_11e1f40_set(const Unk_11e1f40* self, Unk_11e1f40_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e1f50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1f50_arg1, field_0, 0x0);

struct Unk_11e1f50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e1f50, field_0, 0x0);

// 0x71011e1f50
void Unk_11e1f50_set(const Unk_11e1f50* self, Unk_11e1f50_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011e2510
void Unk_11e2510_update() {}

// 0x71011e2570
void Unk_11e2570_update() {}

struct Unk_11e2580_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e2580_arg1, field_0, 0x0);

struct Unk_11e2580 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e2580, field_0, 0x0);

// 0x71011e2580
void Unk_11e2580_set(const Unk_11e2580* self, Unk_11e2580_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e2590_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e2590_arg1, field_0, 0x0);

struct Unk_11e2590 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e2590, field_0, 0x0);

// 0x71011e2590
void Unk_11e2590_set(const Unk_11e2590* self, Unk_11e2590_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011e2670
void Unk_11e2670_update() {}

struct Unk_11e2680 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11e2680, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e2680, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11e2680, field_10, 0x10);

// 0x71011e2680
void Unk_11e2680_set(const Unk_11e2680* self, Unk_11e2680* value) {
    *value = *self;
}

struct Unk_11e26a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11e26a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11e26a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11e26a0, field_10, 0x10);

// 0x71011e26a0
void Unk_11e26a0_set(const Unk_11e26a0* self, Unk_11e26a0* value) {
    *value = *self;
}

struct Unk_11e26c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e26c0_arg1, field_0, 0x0);

struct Unk_11e26c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e26c0, field_0, 0x0);

// 0x71011e26c0
void Unk_11e26c0_set(const Unk_11e26c0* self, Unk_11e26c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11e26d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e26d0_arg1, field_0, 0x0);

struct Unk_11e26d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11e26d0, field_0, 0x0);

// 0x71011e26d0
void Unk_11e26d0_set(const Unk_11e26d0* self, Unk_11e26d0_arg1* value) {
    value->field_0 = self->field_0;
}
