// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d52ef0_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d52ef0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d52ef0_arg1, field_8, 0x8);
struct Unk_d52ef0 {
    u8 _0[0xb0];
    u64 field_b0;
    u64 field_b8;
    u8 field_c0;
    u8 _c1[0x498];
    u8 field_559;
};
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_d52ef0, field_559, 0x559);

// 0x7100d52ef0
void Unk_d52ef0_update(Unk_d52ef0* self, const Unk_d52ef0_arg1* value) {
    if (self->field_559 != 0) {
        return;
    }
    self->field_b8 = value->field_8;
    self->field_b0 = value->field_0;
    self->field_c0 = 1;
}

// 0x7100d538b0
void Unk_d538b0_update() {}

struct Unk_d538c0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538c0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538c0, field_8, 0x8);

// 0x7100d538c0
void Unk_d538c0_set(const Unk_d538c0* self, Unk_d538c0* value) {
    *value = *self;
}

struct Unk_d538d0 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d538d0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d538d0, field_8, 0x8);

// 0x7100d538d0
void Unk_d538d0_set(const Unk_d538d0* self, Unk_d538d0* value) {
    *value = *self;
}

struct Unk_27dcde4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dcde4_Data, field_18, 0x18);

extern Unk_27dcde4_Data Unk_27dcde4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d56d50
void Unk_d56d50_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dcde4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dcde4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dcde4.field_18 = 0xffff;
    Unk_27dcde4.field_10 = 0;
    Unk_27dcde4.field_8 = r2;
    Unk_27dcde4.field_c = 0;
    Unk_27dcde4.field_14 = 0xffffffff;
}
