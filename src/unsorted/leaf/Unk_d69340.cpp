// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d69340 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual u32 vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    u8 _8[0x1e0];
    u32 field_1e8;
    u8 _1ec[0x539];
    u8 field_725;
    u8 field_726;
};
PKMN_OFFSET_ASSERT(Unk_d69340, field_1e8, 0x1e8);
PKMN_OFFSET_ASSERT(Unk_d69340, field_725, 0x725);
PKMN_OFFSET_ASSERT(Unk_d69340, field_726, 0x726);

// 0x7100d69340
void Unk_d69340_call(Unk_d69340* self) {
    if (self->field_725 != 0) {
        self->field_725 = 0;
        if (self->field_726 == 0)
            return;
        self->vf45();
        u32 r1 = self->vf17();
        if ((r1 & 1) != 0)
            return;
        self->field_1e8 = 1;
    }
}

struct Unk_d69840 {
    u8 _0[0x720];
    u8 field_720;
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d69840, field_720, 0x720);
PKMN_OFFSET_ASSERT(Unk_d69840, field_721, 0x721);

// 0x7100d69840
void Unk_d69840_set(Unk_d69840* self, u8 value) {
    if (self->field_721 == value) {
        if (self->field_720 != 0) {
            if (self->field_720 != value) {
                self->field_720 = value;
                return;
            }
            return;
        }
        return;
    }
    self->field_720 = value;
}

struct Unk_d69870 {
    u8 _0[0x727];
    u8 field_727;
    u8 field_728;
};
PKMN_OFFSET_ASSERT(Unk_d69870, field_727, 0x727);
PKMN_OFFSET_ASSERT(Unk_d69870, field_728, 0x728);

// 0x7100d69870
void Unk_d69870_set(Unk_d69870* self, u8 value) {
    if (self->field_728 != (value)) {
        self->field_727 = value;
    }
}

struct Unk_d699d0 {
    u8 _0[0x6c0];
    u64 field_6c0;
    u64 field_6c8;
};
PKMN_OFFSET_ASSERT(Unk_d699d0, field_6c0, 0x6c0);
PKMN_OFFSET_ASSERT(Unk_d699d0, field_6c8, 0x6c8);

// 0x7100d699d0
void Unk_d699d0_set(Unk_d699d0* self) {
    if (self->field_6c0 != self->field_6c8) {
        self->field_6c8 = self->field_6c8 - 0x30;
    }
}

struct Unk_d699f0 {
    u8 _0[0x720];
    u8 field_720;
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d699f0, field_720, 0x720);
PKMN_OFFSET_ASSERT(Unk_d699f0, field_721, 0x721);

// 0x7100d699f0
u8 Unk_d699f0_get(const Unk_d699f0* self) {
    if (self->field_720 != 0) {
        return self->field_720;
    }
    return self->field_721;
}

struct Unk_d69a10 {
    u8 _0[0x721];
    u8 field_721;
};
PKMN_OFFSET_ASSERT(Unk_d69a10, field_721, 0x721);

// 0x7100d69a10
u8 Unk_d69a10_getField721(const Unk_d69a10* self) {
    return self->field_721;
}

struct Unk_27dd3e4_Data {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_c;
    u16 field_10;
    u8 _12[0x2];
    u32 field_14;
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_27dd3e4_Data, field_18, 0x18);

extern Unk_27dd3e4_Data Unk_27dd3e4 __attribute__((visibility("hidden")));
namespace nn {
namespace ldn {
u64 MakeIpv4Address(u8, u8, u8, u8);
}
}  // namespace nn

// 0x7100d6c390
void Unk_d6c390_call() {
    u32 r0 = nn::ldn::MakeIpv4Address(0x7f, 0, 0, 1);
    Unk_27dd3e4.field_0 = r0;
    u32 r1 = nn::ldn::MakeIpv4Address(0xff, 0xff, 0xff, 0xff);
    Unk_27dd3e4.field_4 = r1;
    u32 r2 = nn::ldn::MakeIpv4Address(0, 0, 0, 0);
    Unk_27dd3e4.field_18 = 0xffff;
    Unk_27dd3e4.field_10 = 0;
    Unk_27dd3e4.field_8 = r2;
    Unk_27dd3e4.field_c = 0;
    Unk_27dd3e4.field_14 = 0xffffffff;
}
