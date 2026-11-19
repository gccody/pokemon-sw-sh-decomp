// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_e3dfe0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3dfe0_arg1, field_0, 0x0);

struct Unk_e3dfe0 {
    u8 _0[0x90];
    u32 field_90;
    u8 _94[0x4];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_e3dfe0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_e3dfe0, field_98, 0x98);

// 0x7100e3dfe0
void Unk_e3dfe0_set(Unk_e3dfe0* self, const Unk_e3dfe0_arg1* value) {
    self->field_90 = 2;
    self->field_98 = value->field_0;
}

struct Unk_e3e3b0 {
    u8 _0[0x1a0];
    u32 field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_e3e3b0, field_1a0, 0x1a0);

// 0x7100e3e3b0
bool Unk_e3e3b0_check(const Unk_e3e3b0* self) {
    return self->field_1a0 != 0xfffffffe;
}

struct Unk_14a92b0;
struct Unk_e3e3c0 {
    u8 _0[0x68];
    Unk_14a92b0* field_68;
};
PKMN_OFFSET_ASSERT(Unk_e3e3c0, field_68, 0x68);

u32 Unk_14a92b0_getField78(const Unk_14a92b0*);

// 0x7100e3e3c0
bool Unk_e3e3c0_call(const Unk_e3e3c0* self) {
    u32 r0 = Unk_14a92b0_getField78(self->field_68);
    return r0 == 6;
}

struct Unk_e3efd0_60 {
    u8 _0[0x140];
    u32 field_140;
};
PKMN_OFFSET_ASSERT(Unk_e3efd0_60, field_140, 0x140);

struct Unk_e3efd0 {
    u8 _0[0x60];
    Unk_e3efd0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_e3efd0, field_60, 0x60);

// 0x7100e3efd0
void Unk_e3efd0_set(const Unk_e3efd0* self) {
    self->field_60->field_140 = 0xb5;
}

struct Unk_e3f1d0_0 {
    u8 _0[0x1a0];
    u32 field_1a0;
};
PKMN_OFFSET_ASSERT(Unk_e3f1d0_0, field_1a0, 0x1a0);

struct Unk_e3f1d0_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f1d0_arg1, field_0, 0x0);

struct Unk_e3f1d0 {
    Unk_e3f1d0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f1d0, field_0, 0x0);

// 0x7100e3f1d0
void Unk_e3f1d0_set(const Unk_e3f1d0* self, const Unk_e3f1d0_arg1* value) {
    self->field_0->field_1a0 = value->field_0;
}

// 0x7100e3f1e0
void Unk_e3f1e0_update() {}

struct Unk_e3f1f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f1f0_arg1, field_0, 0x0);

struct Unk_e3f1f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f1f0, field_0, 0x0);

// 0x7100e3f1f0
void Unk_e3f1f0_set(const Unk_e3f1f0* self, Unk_e3f1f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e3f200_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f200_arg1, field_0, 0x0);

struct Unk_e3f200 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f200, field_0, 0x0);

// 0x7100e3f200
void Unk_e3f200_set(const Unk_e3f200* self, Unk_e3f200_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100e3f420
void Unk_e3f420_update() {}

struct Unk_e3f430_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f430_arg1, field_0, 0x0);

struct Unk_e3f430 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f430, field_0, 0x0);

// 0x7100e3f430
void Unk_e3f430_set(const Unk_e3f430* self, Unk_e3f430_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e3f440_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f440_arg1, field_0, 0x0);

struct Unk_e3f440 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e3f440, field_0, 0x0);

// 0x7100e3f440
void Unk_e3f440_set(const Unk_e3f440* self, Unk_e3f440_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_27e00f4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e00f4_Data, field_18, 0x18);

extern Unk_27e00f4_Data Unk_27e00f4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e3f450
void Unk_e3f450_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e00f4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e00f4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e00f4.field_18 = 0xffff;
    Unk_27e00f4.field_10 = 0;
    Unk_27e00f4.field_8 = r2;
    Unk_27e00f4.field_c = 0;
    Unk_27e00f4.field_14 = 0xffffffff;
}
