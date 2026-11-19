// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7c58b0;
struct Unk_7e4240_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e4240_arg2, field_0, 0x0);

struct Unk_7e4240 {
    u8 _0[0x60];
    Unk_7c58b0* field_60;
};
PKMN_OFFSET_ASSERT(Unk_7e4240, field_60, 0x60);

u32 Unk_7c58b0_get(const Unk_7c58b0*);

// 0x71007e4240
void Unk_7e4240_call(const Unk_7e4240* self, u32 /*unused*/, Unk_7e4240_arg2* arg2) {
    u32 r0 = Unk_7c58b0_get(self->field_60);
    arg2->field_0 = r0 == 4 ? 0x24 : 2;
}

struct Unk_8925a0;
struct Unk_7e44c0_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e44c0_arg2, field_0, 0x0);

struct Unk_7e44c0 {
    u8 _0[0x5e8];
    Unk_8925a0* field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_7e44c0, field_5e8, 0x5e8);

u8 Unk_8925a0_getField84(const Unk_8925a0*);

// 0x71007e44c0
void Unk_7e44c0_call(const Unk_7e44c0* self, u32 /*unused*/, Unk_7e44c0_arg2* arg2) {
    u8 r0 = Unk_8925a0_getField84(self->field_5e8);
    arg2->field_0 = (r0 & 0xff) == 1 ? 6 : 0xa;
}

struct Unk_8925a0;
struct Unk_7e4850_arg2 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7e4850_arg2, field_0, 0x0);

struct Unk_7e4850 {
    u8 _0[0x5e8];
    Unk_8925a0* field_5e8;
};
PKMN_OFFSET_ASSERT(Unk_7e4850, field_5e8, 0x5e8);

u8 Unk_8925a0_getField84(const Unk_8925a0*);

// 0x71007e4850
void Unk_7e4850_call(const Unk_7e4850* self, u32 /*unused*/, Unk_7e4850_arg2* arg2) {
    u8 r0 = Unk_8925a0_getField84(self->field_5e8);
    arg2->field_0 = (r0 & 0xff) == 1 ? 6 : 0xa;
}

struct Unk_27cebfc_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cebfc_Data, field_18, 0x18);

extern Unk_27cebfc_Data Unk_27cebfc __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71007e7ac0
void Unk_7e7ac0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cebfc.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cebfc.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cebfc.field_18 = 0xffff;
    Unk_27cebfc.field_10 = 0;
    Unk_27cebfc.field_8 = r2;
    Unk_27cebfc.field_c = 0;
    Unk_27cebfc.field_14 = 0xffffffff;
}
