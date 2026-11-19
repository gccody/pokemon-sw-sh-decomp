// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_50cb20(void*, u64, u32, u64, u32);

// 0x710050c9d0
void Unk_50c9d0_call(void* self, u64 value, u32 arg2, u64 arg3) {
    Unk_50cb20(self, value, arg2 == 1 ? 0 : arg2, arg3, 0);
}

// 0x710050d1a0
void Unk_50d1a0_update() {
}

// 0x710050d1b0
u32 Unk_50d1b0_get() {
    return 0;
}

struct Unk_50d890 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_50d890, field_0, 0x0);

void Unk_502810(u64, void*);

// 0x710050d890
void Unk_50d890_call(Unk_50d890* self) {
    Unk_502810(self->field_0, self);
}

struct Unk_50da30 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_50da30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_50da30, field_8, 0x8);

void Unk_50e030(u64, u64, u64);

// 0x710050da30
u32 Unk_50da30_call(const Unk_50da30* self, u64 value) {
    Unk_50e030(value, self->field_0 << 2, self->field_8 << 2);
    return 0;
}

struct Unk_510310 {
    u8 _0[0x18];
    u64 field_18;
    u32 field_20;
    u8 _24[0xc];
    u8 field_30;
    u8 _31[0x2f];
    u8 field_60;
    u8 _61[0x47];
    u64 field_a8;
    u8 _b0[0x30];
    u64 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_510310, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_510310, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_510310, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_510310, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_510310, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_510310, field_e0, 0xe0);

void Unk_512750(void*, u64);

// 0x7100510310
void Unk_510310_call(Unk_510310* self) {
    u64 v0 = self->field_18;
    self->field_a8 = 0;
    self->field_e0 = 0;
    Unk_512750(&self->field_30, v0);
    Unk_512750(&self->field_60, v0);
    self->field_20 = 0;
    self->field_18 = 0;
}

struct Unk_511580 {
    u8 _0[0x8];
    u32 field_8;
    u8 _c[0x4];
    u32 field_10;
    u8 _14[0x4];
    u32 field_18;
    u8 _1c[0xc];
    u32 field_28;
    u8 _2c[0xc];
    u32 field_38;
    u8 _3c[0xc];
    u32 field_48;
    u8 _4c[0xc];
    u32 field_58;
    u8 _5c[0xc];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_511580, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_511580, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_511580, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_511580, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_511580, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_511580, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_511580, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_511580, field_68, 0x68);

// 0x7100511580
void Unk_511580_set(Unk_511580* self) {
    self->field_8 = 0;
    self->field_18 = 0;
    self->field_10 = 1;
    self->field_28 = 0;
    self->field_38 = 0;
    self->field_48 = 0;
    self->field_58 = 0;
    self->field_68 = 0;
}

struct Unk_512200 {
    u8 _0[0x8];
    u32 field_8;
    u8 _c[0x4];
    u32 field_10;
    u8 _14[0x4];
    u32 field_18;
    u8 _1c[0xc];
    u32 field_28;
    u8 _2c[0xc];
    u32 field_38;
    u8 _3c[0xc];
    u32 field_48;
    u8 _4c[0xc];
    u32 field_58;
    u8 _5c[0xc];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_512200, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_512200, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_512200, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_512200, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_512200, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_512200, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_512200, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_512200, field_68, 0x68);

// 0x7100512200
void Unk_512200_set(Unk_512200* self) {
    self->field_8 = 0;
    self->field_18 = 0;
    self->field_10 = 2;
    self->field_28 = 0;
    self->field_38 = 0;
    self->field_48 = 0;
    self->field_58 = 0;
    self->field_68 = 0;
}

struct Unk_513680 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_513680, field_18, 0x18);

// 0x7100513680
u32 Unk_513680_update(Unk_513680* self, u64 value) {
    self->field_18 = value;
    return 0;
}

// 0x71005152d0
u32 Unk_5152d0_get() {
    return 0;
}

struct Unk_5152e0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_5152e0_arg1, field_0, 0x0);

// 0x71005152e0
u32 Unk_5152e0_update(void* /*unused*/, Unk_5152e0_arg1* value) {
    value->field_0 = 0;
    return 0;
}

void Unk_502810(u64, void*);

// 0x71005168e0
void Unk_5168e0_call(u64 self, void* value) {
    Unk_502810(self, value);
}

void Unk_502810(u64, void*);

// 0x71005205a0
void Unk_5205a0_call(u64 self, void* value) {
    Unk_502810(self, value);
}

struct Unk_5217d0 {
    u8 _0[0x78];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_5217d0, field_78, 0x78);

// 0x71005217d0
u32 Unk_5217d0_update(Unk_5217d0* self) {
    self->field_78 = 0x28;
    return 0;
}

// 0x71005217e0
void Unk_5217e0_update() {
}

struct Unk_522740 {
    u8 _0[0xe0];
    u8 field_e0;
    u8 _e1[0x7];
    u64 field_e8;
    u8 _f0[0x128];
    u64 field_218;
};
PKMN_OFFSET_ASSERT(Unk_522740, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_522740, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_522740, field_218, 0x218);

// 0x7100522740
u32 Unk_522740_update(Unk_522740* self) {
    self->field_218 = 0xffffffffffffffff;
    self->field_e0 = 0;
    self->field_e8 = 0xffffffff;
    return 0;
}

struct Unk_522760 {
    u8 _0[0xe0];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_522760, field_e0, 0xe0);

void Unk_52e860();

// 0x7100522760
void Unk_522760_call(Unk_522760* self) {
    Unk_52e860();
    self->field_e0 = 0;
}

struct Unk_522790_128 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_522790_128, field_0, 0x0);

struct Unk_522790 {
    u8 _0[0x128];
    Unk_522790_128* field_128;
};
PKMN_OFFSET_ASSERT(Unk_522790, field_128, 0x128);

void Unk_502820(u64);

// 0x7100522790
void Unk_522790_call(const Unk_522790* self) {
    Unk_502820(self->field_128->field_0);
}

struct Unk_529230 {
    u8 _0[0x1d8];
    u16 field_1d8;
};
PKMN_OFFSET_ASSERT(Unk_529230, field_1d8, 0x1d8);

// 0x7100529230
u16 Unk_529230_get(const Unk_529230* self) {
    return self->field_1d8;
}

struct Unk_530d70 {
    u8 _0[0x30];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_530d70, field_30, 0x30);

void Unk_5082e0(u64);

// 0x7100530d70
void Unk_530d70_call(const Unk_530d70* self) {
    Unk_5082e0(self->field_30);
}
