// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>
#include "gflib3/Unk_239a4c0.h"

class Unk_23d0c48 : public Unk_239a4c0 {
public:
    ~Unk_23d0c48() override;
    u8 _54[0x1c];
    Unk_239a418_Ref<Unk_239a418> field_70;
    u8 _78[0x18];
    Unk_239a418_Ref<Unk_239a418> field_90;
    u8 _98[0x18];
    Unk_239a418_Ref<Unk_239a418> field_b0;
    u8 _b8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_d0;
    u8 _d8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_f0;
    u8 _f8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_110;
    u8 _118[0x18];
    Unk_239a418_Ref<Unk_239a418> field_130;
    u8 _138[0x18];
    Unk_239a418_Ref<Unk_239a418> field_150;
    u8 _158[0x18];
    Unk_239a418_Ref<Unk_239a418> field_170;
    u8 _178[0x18];
    Unk_239a418_Ref<Unk_239a418> field_190;
    u8 _198[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1b0;
    u8 _1b8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1d0;
    u8 _1d8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_1f0;
    u8 _1f8[0x18];
    Unk_239a418_Ref<Unk_239a418> field_210;
    u8 _218[0x18];
    Unk_239a418_Ref<Unk_239a418> field_230;
    u8 _238[0x18];
    Unk_239a418_Ref<Unk_239a418> field_250;
};
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_130, 0x130);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_150, 0x150);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_170, 0x170);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_190, 0x190);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_1d0, 0x1d0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_1f0, 0x1f0);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_210, 0x210);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_230, 0x230);
PKMN_OFFSET_ASSERT(Unk_23d0c48, field_250, 0x250);

// 0x7100b75450: its key function
Unk_23d0c48::~Unk_23d0c48() {}

class Unk_23d0cb0 {
public:
    virtual ~Unk_23d0cb0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual bool vf11();
    virtual void vf12();
    virtual void vf13();
    virtual bool vf14();
    virtual bool vf15();
    virtual void vf16();
    u8 _8[0x70];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23d0cb0, field_78, 0x78);

// 0x7100b76130
bool Unk_23d0cb0::vf11() {
    return field_78 == 4;
}

// 0x7100b76140
bool Unk_23d0cb0::vf14() {
    return field_78 == 0;
}

// 0x7100b76150
bool Unk_23d0cb0::vf15() {
    return (field_78 | 4) == 4;
}

class Unk_23d0db0 {
public:
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
    virtual u32 vf16();
};

// 0x7100b765d0
void Unk_23d0db0::vf7() {}

// 0x7100b765e0
void Unk_23d0db0::vf8() {}

// 0x7100b765f0
void Unk_23d0db0::vf9() {}

// 0x7100b76600
void Unk_23d0db0::vf10() {}

// 0x7100b76610
void Unk_23d0db0::vf12() {}

// 0x7100b76620
void Unk_23d0db0::vf13() {}

// 0x7100b76630
u32 Unk_23d0db0::vf16() {
    return 1;
}

class Unk_23d0eb0 {
public:
    virtual ~Unk_23d0eb0();
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
    virtual void vf17();
    virtual u64 vf18();
    virtual u64 vf19();
    u8 _8[0x98];
    u64 field_a0;
    u64 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_23d0eb0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_23d0eb0, field_a8, 0xa8);

// 0x7100b77330
u64 Unk_23d0eb0::vf18() {
    return field_a0;
}

// 0x7100b77340
u64 Unk_23d0eb0::vf19() {
    return field_a8;
}

class Unk_23d1560 {
public:
    virtual ~Unk_23d1560();
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
    u8 _8[0x70];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23d1560, field_78, 0x78);

// 0x7100b80690
void Unk_23d1560::vf13() {
    field_78 = 0;
}

class Unk_23d1660 {
public:
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
    u8 _8[0x70];
    u32 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23d1660, field_78, 0x78);

// 0x7100b81210
void Unk_23d1660::vf13() {
    field_78 = 0;
}
