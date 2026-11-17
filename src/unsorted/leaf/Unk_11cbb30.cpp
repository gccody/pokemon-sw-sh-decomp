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
