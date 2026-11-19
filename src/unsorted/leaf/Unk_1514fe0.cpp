// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

u32 Unk_eb6530();

// 0x7101514fe0
u32 Unk_1514fe0_call() {
    u32 r0 = Unk_eb6530();
    return ~r0 & 1;
}

struct Unk_1515000 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515000, field_5cc, 0x5cc);

// 0x7101515000
void Unk_1515000_clearField5cc(Unk_1515000* self) {
    self->field_5cc = 0;
}

struct Unk_1515010 {
    u8 _0[0x5cc];
    u32 field_5cc;
};
PKMN_OFFSET_ASSERT(Unk_1515010, field_5cc, 0x5cc);

// 0x7101515010
u32 Unk_1515010_getField5cc(const Unk_1515010* self) {
    return self->field_5cc;
}

// 0x7101516ee0
void Unk_1516ee0_update() {}

struct Unk_1516ef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516ef0_arg1, field_0, 0x0);

struct Unk_1516ef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516ef0, field_0, 0x0);

// 0x7101516ef0
void Unk_1516ef0_set(const Unk_1516ef0* self, Unk_1516ef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1516f00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516f00_arg1, field_0, 0x0);

struct Unk_1516f00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1516f00, field_0, 0x0);

// 0x7101516f00
void Unk_1516f00_set(const Unk_1516f00* self, Unk_1516f00_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71015180e0
void Unk_15180e0_update() {}

struct Unk_15180f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15180f0_arg1, field_0, 0x0);

struct Unk_15180f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_15180f0, field_0, 0x0);

// 0x71015180f0
void Unk_15180f0_set(const Unk_15180f0* self, Unk_15180f0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1518100_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1518100_arg1, field_0, 0x0);

struct Unk_1518100 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1518100, field_0, 0x0);

// 0x7101518100
void Unk_1518100_set(const Unk_1518100* self, Unk_1518100_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710151a420
u32 Unk_151a420() {
    return 9;
}

struct Unk_27f1d04_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27f1d04_Data, field_18, 0x18);

extern Unk_27f1d04_Data Unk_27f1d04 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710151bf30
void Unk_151bf30_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27f1d04.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27f1d04.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27f1d04.field_18 = 0xffff;
    Unk_27f1d04.field_10 = 0;
    Unk_27f1d04.field_8 = r2;
    Unk_27f1d04.field_c = 0;
    Unk_27f1d04.field_14 = 0xffffffff;
}
