// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_69e310_58 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_69e310 {
    u8 _0[0x50];
    u64 field_50;
    Unk_69e310_58* field_58;
    u64 field_60;
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_69e310, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_69e310, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_69e310, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_69e310, field_68, 0x68);

void Unk_69ea20(u64);

// 0x710069e310
void Unk_69e310_call(Unk_69e310* self) {
    u64 v0 = self->field_50;
    self->field_50 = 0;
    if (v0 != 0) {
        Unk_69ea20(v0);
        self->field_58->vf3(v0, self->field_60, self->field_68);
    }
}

struct Unk_69e360_50_20 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_69e360_50_20, field_48, 0x48);

struct Unk_69e360_50 {
    u8 _0[0x20];
    Unk_69e360_50_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_69e360_50, field_20, 0x20);

struct Unk_69e360 {
    u8 _0[0x50];
    Unk_69e360_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69e360, field_50, 0x50);

void Unk_69df60(void*);

// 0x710069e360
u32 Unk_69e360_call(const Unk_69e360* self) {
    Unk_69df60(self->field_50);
    return self->field_50->field_20->field_48;
}

struct Unk_69e390_50_20 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_69e390_50_20, field_48, 0x48);

struct Unk_69e390_50 {
    u8 _0[0x20];
    Unk_69e390_50_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_69e390_50, field_20, 0x20);

struct Unk_69e390 {
    u8 _0[0x50];
    Unk_69e390_50* field_50;
};
PKMN_OFFSET_ASSERT(Unk_69e390, field_50, 0x50);

// 0x710069e390
bool Unk_69e390_check(const Unk_69e390* self) {
    return self->field_50->field_20->field_48 == 0;
}

struct Unk_69e3b0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_69e3b0, field_50, 0x50);

// 0x710069e3b0
bool Unk_69e3b0_check(const Unk_69e3b0* self) {
    return self->field_50 != 0;
}

struct Unk_2778b94_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2778b94_Data, field_18, 0x18);

extern Unk_2778b94_Data Unk_2778b94 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x710069f610
void Unk_69f610_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_2778b94.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_2778b94.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_2778b94.field_10 = 0xffff;
    Unk_2778b94.field_8 = r2;
    Unk_2778b94.field_c = 0xffffffff;
    Unk_2778b94.field_18 = 0;
    Unk_2778b94.field_14 = 0;
}
