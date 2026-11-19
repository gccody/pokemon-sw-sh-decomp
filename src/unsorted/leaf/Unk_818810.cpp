// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

extern const u8 Unk_23acae8[] __attribute__((visibility("hidden")));
struct Unk_818810 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_818810, field_0, 0x0);

// 0x7100818810
const u8* Unk_818810_update(Unk_818810* self) {
    self->field_0 = 1;
    return Unk_23acae8;
}

// 0x71008189b0
void Unk_8189b0_update() {}

extern const u8 Unk_23acb48[] __attribute__((visibility("hidden")));
struct Unk_8189c0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8189c0, field_0, 0x0);

// 0x71008189c0
const u8* Unk_8189c0_update(Unk_8189c0* self) {
    self->field_0 = 1;
    return Unk_23acb48;
}

extern const u8 Unk_23acb58[] __attribute__((visibility("hidden")));
struct Unk_8189e0 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8189e0, field_0, 0x0);

// 0x71008189e0
const u8* Unk_8189e0_update(Unk_8189e0* self) {
    self->field_0 = 2;
    return Unk_23acb58;
}

extern const u8 Unk_23acb78[] __attribute__((visibility("hidden")));
struct Unk_818a00 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_818a00, field_0, 0x0);

// 0x7100818a00
const u8* Unk_818a00_update(Unk_818a00* self) {
    self->field_0 = 2;
    return Unk_23acb78;
}

extern const u8 Unk_23acb98[] __attribute__((visibility("hidden")));
struct Unk_818a20 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_818a20, field_0, 0x0);

// 0x7100818a20
const u8* Unk_818a20_update(Unk_818a20* self) {
    self->field_0 = 1;
    return Unk_23acb98;
}

extern const u8 Unk_23acba8[] __attribute__((visibility("hidden")));
struct Unk_818a40 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_818a40, field_0, 0x0);

// 0x7100818a40
const u8* Unk_818a40_update(Unk_818a40* self) {
    self->field_0 = 1;
    return Unk_23acba8;
}

struct Unk_27cef94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27cef94_Data, field_18, 0x18);

extern Unk_27cef94_Data Unk_27cef94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100819580
void Unk_819580_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27cef94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27cef94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27cef94.field_18 = 0xffff;
    Unk_27cef94.field_10 = 0;
    Unk_27cef94.field_8 = r2;
    Unk_27cef94.field_c = 0;
    Unk_27cef94.field_14 = 0xffffffff;
}
