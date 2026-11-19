// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100e67870
void Unk_e67870() {}

// 0x7100e67880
u32 Unk_e67880_get() {
    return 1;
}

struct Unk_e67a00 {
    u8 _0[0x18];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_e67a00, field_18, 0x18);

void Unk_e67e80(u64);

// 0x7100e67a00
void Unk_e67a00_call(const Unk_e67a00* self) {
    Unk_e67e80(self->field_18);
}

// 0x7100e68360
void Unk_e68360_update() {}

struct Unk_e68370_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e68370_arg1, field_0, 0x0);

struct Unk_e68370 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e68370, field_0, 0x0);

// 0x7100e68370
void Unk_e68370_set(const Unk_e68370* self, Unk_e68370_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e68380_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e68380_arg1, field_0, 0x0);

struct Unk_e68380 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_e68380, field_0, 0x0);

// 0x7100e68380
void Unk_e68380_set(const Unk_e68380* self, Unk_e68380_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_e68f30 {
    u8 _0[0x73];
    u8 field_73;
};
PKMN_OFFSET_ASSERT(Unk_e68f30, field_73, 0x73);

// 0x7100e68f30
u32 Unk_e68f30_get(Unk_e68f30* self) {
    if (self->field_73 != 0) {
        self->field_73 = 0;
    }
    return 1;
}

struct Unk_e69de0_5d8 {
    u8 _0[0x30];
    f32 field_30;
    f32 field_34;
    u32 field_38;
    u8 _3c[0x1c];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_34, 0x34);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_e69de0_5d8, field_58, 0x58);

struct Unk_e69de0 {
    u8 _0[0x5d8];
    Unk_e69de0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_e69de0, field_5d8, 0x5d8);

// 0x7100e69de0
void Unk_e69de0_set(const Unk_e69de0* self, f32 fvalue, f32 farg1) {
    Unk_e69de0_5d8* p0 = self->field_5d8;
    p0->field_30 = fvalue;
    p0->field_34 = farg1;
    p0->field_38 = 0;
    p0->field_58 = p0->field_58 | 0x10;
}

struct Unk_27e041c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e041c_Data, field_18, 0x18);

extern Unk_27e041c_Data Unk_27e041c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100e6d200
void Unk_e6d200_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e041c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e041c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e041c.field_18 = 0xffff;
    Unk_27e041c.field_10 = 0;
    Unk_27e041c.field_8 = r2;
    Unk_27e041c.field_c = 0;
    Unk_27e041c.field_14 = 0xffffffff;
}
