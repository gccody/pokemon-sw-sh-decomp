// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_aac6c0(void*, u32, u32, u64);

// 0x7100aac6b0
void Unk_aac6b0_call(void* self, u32 value, u32 arg2, u64 arg3) {
    Unk_aac6c0(self, value, arg2, arg3);
}

struct Unk_aad500 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_aad500, field_80, 0x80);

// 0x7100aad500
u32 Unk_aad500_getField80(const Unk_aad500* self) {
    return self->field_80;
}

struct Unk_aad510 {
    u8 _0[0x80];
    u32 field_80;
};
PKMN_OFFSET_ASSERT(Unk_aad510, field_80, 0x80);

// 0x7100aad510
void Unk_aad510_clearField80(Unk_aad510* self) {
    self->field_80 = 0;
}

struct Unk_aafb90 {
    u8 _0[0x690];
    u32 field_690;
    u8 field_694;
    u8 field_695;
    u16 field_696;
};
PKMN_OFFSET_ASSERT(Unk_aafb90, field_690, 0x690);
PKMN_OFFSET_ASSERT(Unk_aafb90, field_694, 0x694);
PKMN_OFFSET_ASSERT(Unk_aafb90, field_695, 0x695);
PKMN_OFFSET_ASSERT(Unk_aafb90, field_696, 0x696);

// 0x7100aafb90
void Unk_aafb90_set(Unk_aafb90* self, u32 value, u8 arg2, u8 arg3, u16 arg4) {
    self->field_690 = value;
    self->field_694 = arg2;
    self->field_695 = arg3;
    self->field_696 = arg4;
}

struct Unk_aafbb0 {
    u8 _0[0x690];
    u8 field_690;
};
PKMN_OFFSET_ASSERT(Unk_aafbb0, field_690, 0x690);

// 0x7100aafbb0
u8* Unk_aafbb0_getField690Ptr(Unk_aafbb0* self) {
    return &self->field_690;
}

struct Unk_ab16c0 {
    u8 _0[0x3008];
    u64 field_3008;
};
PKMN_OFFSET_ASSERT(Unk_ab16c0, field_3008, 0x3008);

// 0x7100ab16c0
void Unk_ab16c0_set(Unk_ab16c0* self) {
    self->field_3008 = 2;
}

struct Unk_ab1ad0 {
    u8 _0[0x3008];
    u8 field_3008;
};
PKMN_OFFSET_ASSERT(Unk_ab1ad0, field_3008, 0x3008);

// 0x7100ab1ad0
const u8* Unk_ab1ad0_get(const Unk_ab1ad0* self) {
    return &self->field_3008;
}

struct Unk_ab1df0 {
    u8 _0[0x3010];
    u8 field_3010;
    u8 _3011[0xb];
    u8 field_301c;
    u8 _301d[0xb];
    u8 field_3028;
    u8 _3029[0xb];
    u8 field_3034;
    u8 _3035[0xb];
    u8 field_3040;
    u8 _3041[0xb];
    u8 field_304c;
    u8 _304d[0xb];
    u8 field_3058;
    u8 _3059[0xb];
    u8 field_3064;
    u8 _3065[0xb];
    u8 field_3070;
    u8 _3071[0xb];
    u8 field_307c;
    u8 _307d[0xb];
    u8 field_3088;
    u8 _3089[0xb];
    u8 field_3094;
};
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3010, 0x3010);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_301c, 0x301c);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3028, 0x3028);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3034, 0x3034);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3040, 0x3040);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_304c, 0x304c);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3058, 0x3058);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3064, 0x3064);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3070, 0x3070);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_307c, 0x307c);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3088, 0x3088);
PKMN_OFFSET_ASSERT(Unk_ab1df0, field_3094, 0x3094);

void Unk_ab1ed0(void*, void*);

// 0x7100ab1df0
void Unk_ab1df0_call(Unk_ab1df0* self) {
    Unk_ab1ed0(self, &self->field_3010);
    Unk_ab1ed0(self, &self->field_301c);
    Unk_ab1ed0(self, &self->field_3028);
    Unk_ab1ed0(self, &self->field_3034);
    Unk_ab1ed0(self, &self->field_3040);
    Unk_ab1ed0(self, &self->field_304c);
    Unk_ab1ed0(self, &self->field_3058);
    Unk_ab1ed0(self, &self->field_3064);
    Unk_ab1ed0(self, &self->field_3070);
    Unk_ab1ed0(self, &self->field_307c);
    Unk_ab1ed0(self, &self->field_3088);
    Unk_ab1ed0(self, &self->field_3094);
}

struct Unk_ab2040 {
    u8 _0[0x300c];
    u32 field_300c;
};
PKMN_OFFSET_ASSERT(Unk_ab2040, field_300c, 0x300c);

void Unk_ab2050(void*, u64, u32);

// 0x7100ab2040
void Unk_ab2040_call(Unk_ab2040* self, u64 value) {
    Unk_ab2050(self, value, self->field_300c >> 0x1a);
}

void Unk_eb6230(void*, u32);

// 0x7100ab3ab0
void Unk_ab3ab0_call(void* self) {
    Unk_eb6230(self, 2);
}

void Unk_eb6230(void*, u32);

// 0x7100ab3ac0
void Unk_ab3ac0_call(void* self) {
    Unk_eb6230(self, 3);
}

u32 Unk_eb6530(void*);

// 0x7100ab3ad0
u32 Unk_ab3ad0_call(void* self) {
    u32 r0 = Unk_eb6530(self);
    return ~r0 & 1;
}

struct Unk_ab3af0 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_ab3af0, field_5cc, 0x5cc);

// 0x7100ab3af0
u32 Unk_ab3af0_getField5cc(const Unk_ab3af0* self) {
    return self->field_5cc;
}

struct Unk_ab3b00 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_ab3b00, field_5cc, 0x5cc);

// 0x7100ab3b00
void Unk_ab3b00_clearField5cc(Unk_ab3b00* self) {
    self->field_5cc = 0;
}

struct Unk_ab4130 {
    u8 _0[0x5cc];
    u32 field_5cc;
    u32 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ab4130, field_5cc, 0x5cc);
PKMN_OFFSET_ASSERT(Unk_ab4130, field_5d0, 0x5d0);

// 0x7100ab4130
void Unk_ab4130_set(Unk_ab4130* self, u32 value) {
    self->field_5cc = 1;
    self->field_5d0 = value;
}

struct Unk_ab4260 {
    u8 _0[0x5d0];
    u32 field_5d0;
};
PKMN_OFFSET_ASSERT(Unk_ab4260, field_5d0, 0x5d0);

// 0x7100ab4260
u32 Unk_ab4260_getField5d0(const Unk_ab4260* self) {
    return self->field_5d0;
}

// 0x7100ab4870
void Unk_ab4870_update() {}

struct Unk_ab4880 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ab4880, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ab4880, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ab4880, field_10, 0x10);

// 0x7100ab4880
void Unk_ab4880_set(const Unk_ab4880* self, Unk_ab4880* value) {
    *value = *self;
}

struct Unk_ab48a0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_ab48a0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_ab48a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_ab48a0, field_10, 0x10);

// 0x7100ab48a0
void Unk_ab48a0_set(const Unk_ab48a0* self, Unk_ab48a0* value) {
    *value = *self;
}
