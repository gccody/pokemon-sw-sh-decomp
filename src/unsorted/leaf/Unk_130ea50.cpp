// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_130ea50 {
    u8 _0[0xc20];
    u8 field_c20;
};
PKMN_OFFSET_ASSERT(Unk_130ea50, field_c20, 0xc20);

// 0x710130ea50
void Unk_130ea50_set(Unk_130ea50* self) {
    self->field_c20 = 1;
}

struct Unk_130ffe0 {
    u8 _0[0x120];
    u8 field_120;
};
PKMN_OFFSET_ASSERT(Unk_130ffe0, field_120, 0x120);

// 0x710130ffe0
u32 Unk_130ffe0_get(const Unk_130ffe0* self) {
    return self->field_120 == 0 ? 0 : 3;
}

// 0x7101310140
void Unk_1310140() {}

struct Unk_1310150 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1310150, field_60, 0x60);

// 0x7101310150
u8* Unk_1310150_getField60Ptr(Unk_1310150* self) {
    return &self->field_60;
}

struct Unk_13104e0_arg2 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(u64, u64);
};

// 0x71013104e0
void Unk_13104e0_call(u64 self, u64 value, Unk_13104e0_arg2* arg2) {
    arg2->vf2(self, value);
}

struct Unk_1310500_arg1 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

// 0x7101310500
void Unk_1310500_call(u64 self, Unk_1310500_arg1* value) {
    value->vf3(self, 0, 0);
}

struct Unk_1310850 {
    u8 _0[0x17138];
    u8 field_17138;
};
PKMN_OFFSET_ASSERT(Unk_1310850, field_17138, 0x17138);

// 0x7101310850
const u8* Unk_1310850_get(const Unk_1310850* self) {
    return &self->field_17138;
}

struct Unk_1311c60 {
    u8 _0[0x22c];
    u32 field_22c;
    u16 field_230;
    u8 _232[0x2];
    u32 field_234;
    u8 _238[0x4];
    u32 field_23c;
};
PKMN_OFFSET_ASSERT(Unk_1311c60, field_22c, 0x22c);
PKMN_OFFSET_ASSERT(Unk_1311c60, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_1311c60, field_234, 0x234);
PKMN_OFFSET_ASSERT(Unk_1311c60, field_23c, 0x23c);

void Unk_1311cc0(void*, u64);
void Unk_13120e0(void*, u64, u64, u32, u32);
void Unk_67bfa0(u64);

// 0x7101311c60
void Unk_1311c60_call(Unk_1311c60* self, u64 value, u64 arg2) {
    self->field_22c = 0;
    self->field_230 = 0;
    self->field_234 = 0;
    self->field_23c = 0;
    Unk_1311cc0(self, arg2);
    Unk_67bfa0(value);
    Unk_13120e0(self, value, arg2, 0, 0);
}

struct Unk_13193c0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_13193c0, field_60, 0x60);

// 0x71013193c0
u64 Unk_13193c0_getField60(const Unk_13193c0* self) {
    return self->field_60;
}

struct Unk_13193d0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_13193d0, field_70, 0x70);

// 0x71013193d0
u32 Unk_13193d0_getField70(const Unk_13193d0* self) {
    return self->field_70;
}

struct Unk_13193e0 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_13193e0, field_6c, 0x6c);

// 0x71013193e0
void Unk_13193e0_setField6c(Unk_13193e0* self, u32 value) {
    self->field_6c = value;
}

void Unk_131d440();

// 0x710131d430
void Unk_131d430_call() {
    Unk_131d440();
}

u32 Unk_eb6530();

// 0x710131dbc0
u32 Unk_131dbc0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_131dbe0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_131dbe0, field_5cc, 0x5cc);

// 0x710131dbe0
void Unk_131dbe0_clearField5cc(Unk_131dbe0* self) {
    self->field_5cc = 0;
}

struct Unk_131dbf0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_131dbf0, field_5cc, 0x5cc);

// 0x710131dbf0
u32 Unk_131dbf0_getField5cc(const Unk_131dbf0* self) {
    return self->field_5cc;
}

struct Unk_131e5a0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_131e5a0, field_5cc, 0x5cc);

// 0x710131e5a0
void Unk_131e5a0_set(Unk_131e5a0* self) {
    self->field_5cc = 2;
}

// 0x71013205a0
void Unk_13205a0_update() {}

struct Unk_13205b0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13205b0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13205b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13205b0, field_10, 0x10);

// 0x71013205b0
void Unk_13205b0_set(const Unk_13205b0* self, Unk_13205b0* value) {
    *value = *self;
}

struct Unk_13205d0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_13205d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_13205d0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_13205d0, field_10, 0x10);

// 0x71013205d0
void Unk_13205d0_set(const Unk_13205d0* self, Unk_13205d0* value) {
    *value = *self;
}

struct Unk_27ef364_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27ef364_Data, field_18, 0x18);

extern Unk_27ef364_Data Unk_27ef364 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71013205f0
void Unk_13205f0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27ef364.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27ef364.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27ef364.field_18 = 0xffff;
    Unk_27ef364.field_10 = 0;
    Unk_27ef364.field_8 = r2;
    Unk_27ef364.field_c = 0;
    Unk_27ef364.field_14 = 0xffffffff;
}
