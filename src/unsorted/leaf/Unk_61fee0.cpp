// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_61fee0 {
    u8 _0[0x1c8];
    u64 field_1c8;
    u32 field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_61fee0, field_1c8, 0x1c8);
PKMN_OFFSET_ASSERT(Unk_61fee0, field_1d0, 0x1d0);

void Unk_615d40(u64, u32);

// 0x710061fee0
void Unk_61fee0_call(const Unk_61fee0* self) {
    Unk_615d40(self->field_1c8, self->field_1d0);
}

struct Unk_620820 {
    f32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_620820, field_0, 0x0);

// 0x7100620820
void Unk_620820_setField0(Unk_620820* self, f32 value) {
    self->field_0 = value;
}

struct Unk_620d60 {
    u8 _0[0x8];
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_620d60, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_620d60, field_10, 0x10);

// 0x7100620d60
u64 Unk_620d60_get(const Unk_620d60* self) {
    return (self->field_10 - self->field_8) >> 3;
}

struct Unk_621410 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_621410, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_621410, field_8, 0x8);

// 0x7100621410
u64 Unk_621410_get(const Unk_621410* self) {
    return (self->field_8 - self->field_0) >> 3;
}

struct Unk_6323a0 {
    u8 _0[0x1a8];
    u64 field_1a8;
};
PKMN_OFFSET_ASSERT(Unk_6323a0, field_1a8, 0x1a8);

void Unk_6342b0(u64);

// 0x71006323a0
void Unk_6323a0_call(const Unk_6323a0* self) {
    Unk_6342b0(self->field_1a8);
}

struct Unk_63bea0_arg1 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bea0_arg1, field_0, 0x0);

struct Unk_63bea0_arg2 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bea0_arg2, field_0, 0x0);

struct Unk_63bea0 {
    u8 _0[0x634];
    u16 field_634;
    u16 field_636;
};
PKMN_OFFSET_ASSERT(Unk_63bea0, field_634, 0x634);
PKMN_OFFSET_ASSERT(Unk_63bea0, field_636, 0x636);

// 0x710063bea0
void Unk_63bea0_set(Unk_63bea0* self, const Unk_63bea0_arg1* value, const Unk_63bea0_arg2* arg2) {
    self->field_634 = value->field_0;
    self->field_636 = arg2->field_0;
}

struct Unk_63bec0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bec0_arg1, field_0, 0x0);

struct Unk_63bec0 {
    u8 _0[0x6c0];
    u32 field_6c0;
};
PKMN_OFFSET_ASSERT(Unk_63bec0, field_6c0, 0x6c0);

// 0x710063bec0
void Unk_63bec0_set(Unk_63bec0* self, const Unk_63bec0_arg1* value) {
    self->field_6c0 = value->field_0;
}

struct Unk_63bed0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bed0_arg1, field_0, 0x0);

struct Unk_63bed0 {
    u8 _0[0x6c4];
    u32 field_6c4;
};
PKMN_OFFSET_ASSERT(Unk_63bed0, field_6c4, 0x6c4);

// 0x710063bed0
void Unk_63bed0_set(Unk_63bed0* self, const Unk_63bed0_arg1* value) {
    self->field_6c4 = value->field_0;
}

struct Unk_63bee0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bee0_arg1, field_0, 0x0);

struct Unk_63bee0 {
    u8 _0[0x628];
    u32 field_628;
};
PKMN_OFFSET_ASSERT(Unk_63bee0, field_628, 0x628);

// 0x710063bee0
void Unk_63bee0_set(Unk_63bee0* self, const Unk_63bee0_arg1* value) {
    self->field_628 = value->field_0;
}

struct Unk_63bef0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bef0_arg1, field_0, 0x0);

struct Unk_63bef0 {
    u8 _0[0x62c];
    u32 field_62c;
};
PKMN_OFFSET_ASSERT(Unk_63bef0, field_62c, 0x62c);

// 0x710063bef0
void Unk_63bef0_set(Unk_63bef0* self, const Unk_63bef0_arg1* value) {
    self->field_62c = value->field_0;
}

struct Unk_63bf00_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bf00_arg1, field_0, 0x0);

struct Unk_63bf00 {
    u8 _0[0x630];
    u32 field_630;
};
PKMN_OFFSET_ASSERT(Unk_63bf00, field_630, 0x630);

// 0x710063bf00
void Unk_63bf00_set(Unk_63bf00* self, const Unk_63bf00_arg1* value) {
    self->field_630 = value->field_0;
}

struct Unk_63bf10_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_63bf10_arg1, field_0, 0x0);

struct Unk_63bf10 {
    u8 _0[0x6c8];
    u32 field_6c8;
};
PKMN_OFFSET_ASSERT(Unk_63bf10, field_6c8, 0x6c8);

// 0x710063bf10
void Unk_63bf10_set(Unk_63bf10* self, const Unk_63bf10_arg1* value) {
    self->field_6c8 = value->field_0;
}

struct Unk_64d770 {
    u8 _0[0x270];
    f32 field_270;
};
PKMN_OFFSET_ASSERT(Unk_64d770, field_270, 0x270);

// 0x710064d770
void Unk_64d770_setField270(Unk_64d770* self, f32 value) {
    self->field_270 = value;
}

struct Unk_64e500 {
    u8 _0[0x330];
    f32 field_330;
    u8 _334[0x9c];
    u8 field_3d0;
};
PKMN_OFFSET_ASSERT(Unk_64e500, field_330, 0x330);
PKMN_OFFSET_ASSERT(Unk_64e500, field_3d0, 0x3d0);

// 0x710064e500
void Unk_64e500_set(Unk_64e500* self, f32 fvalue) {
    self->field_3d0 = 0;
    self->field_330 = fvalue;
}

void Unk_64fe20(void*, u64, u64, u64, u32);

// 0x7100650240
void Unk_650240_call(void* self, u64 value, u64 arg2, u64 arg3) {
    Unk_64fe20(self, value, arg2, arg3, 0);
}

void Unk_64fe20(void*, u64, u64, u64, u32);

// 0x7100650250
void Unk_650250_call(void* self, u64 value, u64 arg2) {
    Unk_64fe20(self, value, arg2, 0, 1);
}

struct Unk_650800_arg1_108 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_650800_arg1_108, field_60, 0x60);

struct Unk_650800_arg1 {
    u8 _0[0x108];
    Unk_650800_arg1_108* field_108;
};
PKMN_OFFSET_ASSERT(Unk_650800_arg1, field_108, 0x108);

void Unk_650270(void*, void*, u64, void*, u32, u64);

// 0x7100650800
void Unk_650800_call(void* self, Unk_650800_arg1* value, u64 arg2, u64 arg3) {
    Unk_650270(self, value, arg2, &value->field_108->field_60, 1, arg3);
}

struct Unk_6580f0_268 {
    u8 _0[0xfc];
    u32 field_fc;
};
PKMN_OFFSET_ASSERT(Unk_6580f0_268, field_fc, 0xfc);

struct Unk_6580f0 {
    u8 _0[0x268];
    Unk_6580f0_268* field_268;
    u8 _270[0x214];
    bool field_484;
    u8 field_485;
    u8 _486[0x2];
    u32 field_488;
};
PKMN_OFFSET_ASSERT(Unk_6580f0, field_268, 0x268);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_484, 0x484);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_485, 0x485);
PKMN_OFFSET_ASSERT(Unk_6580f0, field_488, 0x488);

// 0x71006580f0
void Unk_6580f0_set(Unk_6580f0* self, bool value) {
    self->field_484 = value;
    self->field_488 = ((value) & 0xfffffe01) | ((self->field_485 & 0xff) << 1);
    self->field_268->field_fc = ((value) & 0xfffffe01) | ((self->field_485 & 0xff) << 1);
}

struct Unk_658df0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_658df0, field_60, 0x60);

// 0x7100658df0
u32 Unk_658df0_getField60(const Unk_658df0* self) {
    return self->field_60;
}

struct Unk_65a0c0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_65a0c0_arg1, field_0, 0x0);

struct Unk_65a0c0 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_65a0c0, field_60, 0x60);

void Unk_659980();

// 0x710065a0c0
void Unk_65a0c0_call(Unk_65a0c0* self, const Unk_65a0c0_arg1* value) {
    self->field_60 = value->field_0;
    Unk_659980();
}
