// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_10783c0 {
    u8 _0[0x220];
    u64 field_220;
};
PKMN_OFFSET_ASSERT(Unk_10783c0, field_220, 0x220);

namespace nn {
namespace time {
namespace StandardSteadyClock {
u64 now();
}
}  // namespace time
}  // namespace nn

// 0x71010783c0
void Unk_10783c0_call(Unk_10783c0* self) {
    u64 r0 = nn::time::StandardSteadyClock::now();
    self->field_220 = r0;
}

struct Unk_10783f0 {
    u8 _0[0x1e8];
    u8 field_1e8;
};
PKMN_OFFSET_ASSERT(Unk_10783f0, field_1e8, 0x1e8);

// 0x71010783f0
u8* Unk_10783f0_getField1e8Ptr(Unk_10783f0* self) {
    return &self->field_1e8;
}

struct Unk_1078400 {
    u8 _0[0x190];
    u8 field_190;
};
PKMN_OFFSET_ASSERT(Unk_1078400, field_190, 0x190);

// 0x7101078400
u8* Unk_1078400_getField190Ptr(Unk_1078400* self) {
    return &self->field_190;
}

struct Unk_1078410 {
    u8 _0[0xe0];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_1078410, field_e0, 0xe0);

// 0x7101078410
u8* Unk_1078410_getFielde0Ptr(Unk_1078410* self) {
    return &self->field_e0;
}

struct Unk_1078420 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1078420, field_90, 0x90);

// 0x7101078420
u8* Unk_1078420_getField90Ptr(Unk_1078420* self) {
    return &self->field_90;
}

struct Unk_1078430 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1078430, field_60, 0x60);

// 0x7101078430
u8* Unk_1078430_getField60Ptr(Unk_1078430* self) {
    return &self->field_60;
}

struct Unk_1078440 {
    u8 _0[0x4c];
    u8 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_1078440, field_4c, 0x4c);

// 0x7101078440
u8* Unk_1078440_getField4cPtr(Unk_1078440* self) {
    return &self->field_4c;
}

struct Unk_1078450 {
    u8 _0[0x28];
    u8 field_28;
};
PKMN_OFFSET_ASSERT(Unk_1078450, field_28, 0x28);

// 0x7101078450
u8* Unk_1078450_getField28Ptr(Unk_1078450* self) {
    return &self->field_28;
}

struct Unk_1078460 {
    u8 _0[0x210];
    u8 field_210;
};
PKMN_OFFSET_ASSERT(Unk_1078460, field_210, 0x210);

// 0x7101078460
u8* Unk_1078460_getField210Ptr(Unk_1078460* self) {
    return &self->field_210;
}

struct Unk_1078470 {
    u8 _0[0x218];
    u8 field_218;
};
PKMN_OFFSET_ASSERT(Unk_1078470, field_218, 0x218);

// 0x7101078470
u8* Unk_1078470_getField218Ptr(Unk_1078470* self) {
    return &self->field_218;
}

struct Unk_1078480 {
    u8 _0[0x220];
    u8 field_220;
};
PKMN_OFFSET_ASSERT(Unk_1078480, field_220, 0x220);

// 0x7101078480
u8* Unk_1078480_getField220Ptr(Unk_1078480* self) {
    return &self->field_220;
}

struct Unk_1078490 {
    u8 _0[0x228];
    u8 field_228;
};
PKMN_OFFSET_ASSERT(Unk_1078490, field_228, 0x228);

// 0x7101078490
u8* Unk_1078490_getField228Ptr(Unk_1078490* self) {
    return &self->field_228;
}

struct Unk_10784a0 {
    u8 _0[0x230];
    u8 field_230;
};
PKMN_OFFSET_ASSERT(Unk_10784a0, field_230, 0x230);

// 0x71010784a0
u8* Unk_10784a0_getField230Ptr(Unk_10784a0* self) {
    return &self->field_230;
}

struct Unk_1078500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1078500_arg1, field_0, 0x0);

struct Unk_1078500 {
    u8 _0[0x210];
    u64 field_210;
};
PKMN_OFFSET_ASSERT(Unk_1078500, field_210, 0x210);

// 0x7101078500
void Unk_1078500_set(Unk_1078500* self, const Unk_1078500_arg1* value) {
    self->field_210 = value->field_0;
}

struct Unk_1078510_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1078510_arg1, field_0, 0x0);

struct Unk_1078510 {
    u8 _0[0x218];
    u32 field_218;
};
PKMN_OFFSET_ASSERT(Unk_1078510, field_218, 0x218);

// 0x7101078510
void Unk_1078510_set(Unk_1078510* self, const Unk_1078510_arg1* value) {
    self->field_218 = value->field_0;
}

struct Unk_1078520 {
    u8 _0[0x228];
    u64 field_228;
};
PKMN_OFFSET_ASSERT(Unk_1078520, field_228, 0x228);

namespace nn {
namespace time {
namespace StandardSteadyClock {
u64 now();
}
}  // namespace time
}  // namespace nn

// 0x7101078520
void Unk_1078520_call(Unk_1078520* self) {
    u64 r0 = nn::time::StandardSteadyClock::now();
    self->field_228 = r0;
}

struct Unk_1078600 {
    u32 field_0;
    u8 _4[0x22c];
    u32 field_230;
};
PKMN_OFFSET_ASSERT(Unk_1078600, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1078600, field_230, 0x230);

// 0x7101078600
u32 Unk_1078600_get(Unk_1078600* self) {
    if (self->field_0 >= 1 && self->field_0 <= 2) {
        self->field_0 = 4;
        self->field_230 = 2;
        return 1;
    }
    return 0;
}

// 0x7101078630
void Unk_1078630() {}

struct Unk_27e3d54_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27e3d54_Data, field_18, 0x18);

extern Unk_27e3d54_Data Unk_27e3d54 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7101078640
void Unk_1078640_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27e3d54.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27e3d54.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27e3d54.field_10 = 0xffff;
    Unk_27e3d54.field_8 = r2;
    Unk_27e3d54.field_c = 0xffffffff;
    Unk_27e3d54.field_18 = 0;
    Unk_27e3d54.field_14 = 0;
}
