// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10ff940 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ff940, field_18, 0x18);

// 0x71010ff940
u8* Unk_10ff940_getField18Ptr(Unk_10ff940* self) {
    return &self->field_18;
}

struct Unk_10ff9c0 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ff9c0, field_18, 0x18);

// 0x71010ff9c0
u8* Unk_10ff9c0_getField18Ptr(Unk_10ff9c0* self) {
    return &self->field_18;
}

struct Unk_10ffb10 {
    u8 _0[0x18];
    u8 field_18;
};
PKMN_OFFSET_ASSERT(Unk_10ffb10, field_18, 0x18);

// 0x71010ffb10
u8* Unk_10ffb10_getField18Ptr(Unk_10ffb10* self) {
    return &self->field_18;
}

struct Unk_10ffcf0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_10ffcf0, field_30, 0x30);

// 0x71010ffcf0
u8* Unk_10ffcf0_getField30Ptr(Unk_10ffcf0* self) {
    return &self->field_30;
}

struct Unk_27e507c_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e507c_Data, field_18, 0x18);

extern Unk_27e507c_Data Unk_27e507c __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x71011003a0
void Unk_11003a0_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e507c.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e507c.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e507c.field_10 = 0xffff;
    Unk_27e507c.field_8 = r2;
    Unk_27e507c.field_c = 0xffffffff;
    Unk_27e507c.field_18 = 0;
    Unk_27e507c.field_14 = 0;
}
