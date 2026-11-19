// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f3d7e0 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_f3d7e0, field_60, 0x60);

// 0x7100f3d7e0
u64 Unk_f3d7e0_getField60(const Unk_f3d7e0* self) {
    return self->field_60;
}

struct Unk_f3d7f0 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f3d7f0, field_70, 0x70);

// 0x7100f3d7f0
u32 Unk_f3d7f0_getField70(const Unk_f3d7f0* self) {
    return self->field_70;
}

struct Unk_f3d800 {
    u8 _0[0x6c];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_f3d800, field_6c, 0x6c);

// 0x7100f3d800
void Unk_f3d800_setField6c(Unk_f3d800* self, u32 value) {
    self->field_6c = value;
}

struct Unk_f3d810 {
    u8 _0[0x70];
    u32 field_70;
};
PKMN_OFFSET_ASSERT(Unk_f3d810, field_70, 0x70);

// 0x7100f3d810
bool Unk_f3d810_check(const Unk_f3d810* self) {
    return self->field_70 == 0;
}

struct Unk_f3da70 {
    u8 _0[0x78];
    u64 field_78;
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f3da70, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_f3da70, field_80, 0x80);
void Unk_eb7730(u64);

// 0x7100f3da70
void Unk_f3da70_update(Unk_f3da70* self) {
    if (self->field_80 != 0) {
        return;
    }
    Unk_eb7730(self->field_78);
    self->field_80 = 1;
}

struct Unk_f3dab0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_f3dab0, field_78, 0x78);

void Unk_eb7790(u64);

// 0x7100f3dab0
void Unk_f3dab0_call(const Unk_f3dab0* self) {
    Unk_eb7790(self->field_78);
}

struct Unk_f3dac0 {
    u8 _0[0x78];
    u64 field_78;
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_f3dac0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_f3dac0, field_80, 0x80);

void Unk_eb77f0(u64);

// 0x7100f3dac0
void Unk_f3dac0_call(Unk_f3dac0* self) {
    if (self->field_80 != 0) {
        Unk_eb77f0(self->field_78);
        self->field_80 = 0;
    }
}

struct Unk_f3daf0 {
    u8 _0[0x78];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_f3daf0, field_78, 0x78);

void Unk_eb7830(u64);

// 0x7100f3daf0
void Unk_f3daf0_call(const Unk_f3daf0* self) {
    Unk_eb7830(self->field_78);
}

struct Unk_f3db40 {
    u8 _0[0x760];
    u64 field_760;
};
PKMN_OFFSET_ASSERT(Unk_f3db40, field_760, 0x760);

// 0x7100f3db40
void Unk_f3db40_setField760(Unk_f3db40* self, u64 value) {
    self->field_760 = value;
}

struct Unk_27e1284_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e1284_Data, field_18, 0x18);

extern Unk_27e1284_Data Unk_27e1284 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100f41c50
void Unk_f41c50_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e1284.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e1284.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e1284.field_18 = 0xffff;
    Unk_27e1284.field_10 = 0;
    Unk_27e1284.field_8 = r2;
    Unk_27e1284.field_c = 0;
    Unk_27e1284.field_14 = 0xffffffff;
}
