// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a2a20 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_6a2a20, field_50, 0x50);

// 0x71006a2a20
void Unk_6a2a20_setField50(Unk_6a2a20* self, u64 value) {
    self->field_50 = value;
}

struct Unk_6a2a30 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_6a2a30, field_50, 0x50);

// 0x71006a2a30
void Unk_6a2a30_clearField50(Unk_6a2a30* self) {
    self->field_50 = 0;
}

struct Unk_6a2b60 {
    u8 _0[0x88];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_6a2b60, field_88, 0x88);

// 0x71006a2b60
u8 Unk_6a2b60_getField88(const Unk_6a2b60* self) {
    return self->field_88;
}

struct Unk_6a3240 {
    u8 _0[0x98];
    u8 field_98;
};
PKMN_OFFSET_ASSERT(Unk_6a3240, field_98, 0x98);

// 0x71006a3240
u8* Unk_6a3240_getField98Ptr(Unk_6a3240* self) {
    return &self->field_98;
}

struct Unk_6a3250 {
    u8 _0[0xc98];
    u64 field_c98;
};
PKMN_OFFSET_ASSERT(Unk_6a3250, field_c98, 0xc98);

// 0x71006a3250
u64 Unk_6a3250_getFieldc98(const Unk_6a3250* self) {
    return self->field_c98;
}

// 0x71006a35b0
void Unk_6a35b0_update() {}

// 0x71006a35c0
void Unk_6a35c0_update() {}

// 0x71006a35d0
void Unk_6a35d0_update() {}

struct Unk_2778d04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778d04_Data, field_18, 0x18);

extern Unk_2778d04_Data Unk_2778d04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71006a35e0
void Unk_6a35e0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778d04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778d04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778d04.field_10 = 0xffff;
    Unk_2778d04.field_8 = r2;
    Unk_2778d04.field_c = 0xffffffff;
    Unk_2778d04.field_18 = 0;
    Unk_2778d04.field_14 = 0;
}
