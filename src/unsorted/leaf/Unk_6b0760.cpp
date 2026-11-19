// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6b0760 {
    u8 _0[0x400];
    u8 field_400;
    u8 _401[0x17];
    u64 field_418;
};
PKMN_OFFSET_ASSERT(Unk_6b0760, field_400, 0x400);
PKMN_OFFSET_ASSERT(Unk_6b0760, field_418, 0x418);

// 0x71006b0760
void Unk_6b0760_set(Unk_6b0760* self) {
    if (self->field_400 != 0) {
        self->field_400 = 0;
    }
    self->field_418 = 0;
}

struct Unk_6b0780 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_6b0780, field_98, 0x98);

// 0x71006b0780
bool Unk_6b0780_check(const Unk_6b0780* self) {
    return self->field_98 != 0;
}

struct Unk_6b0b50 {
    u8 _0[0x98];
    u64 field_98;
    u8 _a0[0x58];
    u64 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_6b0b50, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_6b0b50, field_f8, 0xf8);

// 0x71006b0b50
void Unk_6b0b50_set(Unk_6b0b50* self) {
    self->field_98 = 0;
    self->field_f8 = 0;
}

extern void* Unk_27fc0a8;
void Unk_172bd80(void*);

// 0x71006b1490
void Unk_6b1490_call(u64 /*unused*/) {
    if (Unk_27fc0a8 != 0) {
        Unk_172bd80(Unk_27fc0a8);
    }
}

struct Unk_6b2c10 {
    u8 _0[0x1f0];
    u32 field_1f0;
};
PKMN_OFFSET_ASSERT(Unk_6b2c10, field_1f0, 0x1f0);

// 0x71006b2c10
void Unk_6b2c10_setField1f0(Unk_6b2c10* self, u32 value) {
    self->field_1f0 = value;
}

struct Unk_6b2c20 {
    u8 _0[0x4c8];
    u64 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_6b2c20, field_4c8, 0x4c8);

// 0x71006b2c20
void Unk_6b2c20_clearField4c8(Unk_6b2c20* self) {
    self->field_4c8 = 0;
}

struct Unk_2778e8c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778e8c_Data, field_18, 0x18);

extern Unk_2778e8c_Data Unk_2778e8c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006b3710
void Unk_6b3710_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778e8c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778e8c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778e8c.field_10 = 0xffff;
    Unk_2778e8c.field_8 = r2;
    Unk_2778e8c.field_c = 0xffffffff;
    Unk_2778e8c.field_18 = 0;
    Unk_2778e8c.field_14 = 0;
}
