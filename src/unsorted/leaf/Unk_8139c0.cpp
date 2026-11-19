// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8139c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8139c0, field_0, 0x0);

// 0x71008139c0
void Unk_8139c0_clearField0(Unk_8139c0* self) {
    self->field_0 = 0;
}

struct Unk_8139d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8139d0, field_0, 0x0);

// 0x71008139d0
void Unk_8139d0_clearField0(Unk_8139d0* self) {
    self->field_0 = 0;
}

struct Unk_8139e0 {
    u32 field_0;
    u32 field_4;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_8139e0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_8139e0, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_8139e0, field_8, 0x8);

extern "C" void* memcpy(void*, const void*, unsigned long);

// 0x71008139e0
void Unk_8139e0_call(Unk_8139e0* self, void* value, u16 arg2) {
    memcpy(&self->field_8, value, arg2);
    self->field_0 = arg2;
    self->field_4 = 0;
}

struct Unk_813a20 {
    u8 _0[0x8];
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_813a20, field_8, 0x8);

// 0x7100813a20
u8* Unk_813a20_getField8Ptr(Unk_813a20* self) {
    return &self->field_8;
}

struct Unk_813a30 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_813a30, field_0, 0x0);

// 0x7100813a30
u32 Unk_813a30_getField0(const Unk_813a30* self) {
    return self->field_0;
}

struct Unk_813b20 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_813b20, field_4, 0x4);

// 0x7100813b20
u32 Unk_813b20_getField4(const Unk_813b20* self) {
    return self->field_4;
}

struct Unk_813b30 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_813b30, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_813b30, field_4, 0x4);

// 0x7100813b30
bool Unk_813b30_check(const Unk_813b30* self) {
    return self->field_4 == self->field_0;
}

struct Unk_813d50 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_813d50, field_4, 0x4);

// 0x7100813d50
void Unk_813d50_setField4(Unk_813d50* self, u32 value) {
    self->field_4 = value;
}

struct Unk_7fe1e0;
struct Unk_817c60 {
    u8 _0[0x10];
    Unk_7fe1e0* field_10;
};
PKMN_OFFSET_ASSERT(Unk_817c60, field_10, 0x10);

u64 Unk_7fe1e0_getField28(const Unk_7fe1e0*);
void Unk_7ffb80();

// 0x7100817c60
void Unk_817c60_call(const Unk_817c60* self) {
    Unk_7fe1e0_getField28(self->field_10);
    Unk_7ffb80();
}

struct Unk_8181d0 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_8181d0, field_10, 0x10);

void Unk_7fe2f0(u64);
void Unk_802630();

// 0x71008181d0
void Unk_8181d0_call(const Unk_8181d0* self) {
    Unk_7fe2f0(self->field_10);
    Unk_802630();
}

struct Unk_8185d0 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_8185d0, field_18, 0x18);

void Unk_818a60(void*, u32, u32, u32, void*, u64);

// 0x71008185d0
void Unk_8185d0_call(const Unk_8185d0* self, u32 value, u32 arg2, u32 arg3, void* arg4, u64 arg5) {
    Unk_818a60(self->field_18, value, arg2, arg3, arg4, arg5);
}

struct Unk_8185e0 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_8185e0, field_18, 0x18);

void Unk_818b90(void*, u32, u32);

// 0x71008185e0
void Unk_8185e0_call(const Unk_8185e0* self, u32 value, u32 arg2) {
    Unk_818b90(self->field_18, value, arg2);
}

struct Unk_8185f0 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_8185f0, field_18, 0x18);

void Unk_864ed0(void*, u32, u32, void*);

// 0x71008185f0
void Unk_8185f0_call(const Unk_8185f0* self, u32 value, u32 arg2, void* arg3) {
    Unk_864ed0(self->field_18, value, arg2, arg3);
}

struct Unk_818600 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_818600, field_18, 0x18);

void Unk_864ff0(void*, u32, u32);

// 0x7100818600
void Unk_818600_call(const Unk_818600* self, u32 value, u32 arg2) {
    Unk_864ff0(self->field_18, value, arg2);
}

struct Unk_818610 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_818610, field_18, 0x18);

void Unk_865090(void*, u32, u32);

// 0x7100818610
void Unk_818610_call(const Unk_818610* self, u32 value, u32 arg2) {
    Unk_865090(self->field_18, value, arg2);
}

struct Unk_818620 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_818620, field_18, 0x18);

void Unk_865120(void*, u32, u32);

// 0x7100818620
void Unk_818620_call(const Unk_818620* self, u32 value, u32 arg2) {
    Unk_865120(self->field_18, value, arg2);
}

struct Unk_818630 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_818630, field_18, 0x18);

void Unk_87d760(void*, u32, u64);

// 0x7100818630
void Unk_818630_call(const Unk_818630* self, u32 value, u64 arg2) {
    Unk_87d760(self->field_18, value, arg2);
}

struct Unk_818640 {
    u8 _0[0x18];
    void* field_18;
};
PKMN_OFFSET_ASSERT(Unk_818640, field_18, 0x18);

void Unk_87d7f0(void*, u32);

// 0x7100818640
void Unk_818640_call(const Unk_818640* self, u32 value) {
    Unk_87d7f0(self->field_18, value);
}

struct Unk_27cef74_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cef74_Data, field_18, 0x18);

extern Unk_27cef74_Data Unk_27cef74 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100818790
void Unk_818790_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cef74.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cef74.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cef74.field_18 = 0xffff;
    Unk_27cef74.field_10 = 0;
    Unk_27cef74.field_8 = r2;
    Unk_27cef74.field_c = 0;
    Unk_27cef74.field_14 = 0xffffffff;
}
