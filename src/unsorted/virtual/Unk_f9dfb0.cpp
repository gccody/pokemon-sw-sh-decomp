// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2401d00 {
public:
    virtual ~Unk_2401d00();
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
    u8 _8[0x88];
    u8 field_90;
    u8 field_91;
    u8 field_92;
    u8 field_93;
};
PKMN_OFFSET_ASSERT(Unk_2401d00, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_2401d00, field_91, 0x91);
PKMN_OFFSET_ASSERT(Unk_2401d00, field_92, 0x92);
PKMN_OFFSET_ASSERT(Unk_2401d00, field_93, 0x93);

// 0x7100f9dfb0
void Unk_2401d00::vf7() {
    field_90 = 1;
}

// 0x7100f9dfd0
void Unk_2401d00::vf8() {
    field_91 = 1;
}

// 0x7100f9dff0
void Unk_2401d00::vf9() {
    field_92 = 1;
}

// 0x7100f9e010
void Unk_2401d00::vf10() {
    field_93 = 1;
}

class Unk_2401df0 {
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
    u8 _8[0x28];
    u8 field_30;
    u8 field_31;
    u8 field_32;
    u8 field_33;
};
PKMN_OFFSET_ASSERT(Unk_2401df0, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_2401df0, field_31, 0x31);
PKMN_OFFSET_ASSERT(Unk_2401df0, field_32, 0x32);
PKMN_OFFSET_ASSERT(Unk_2401df0, field_33, 0x33);

// 0x7100f9dfc0
void Unk_2401df0::vf2() {
    field_30 = 1;
}

// 0x7100f9dfe0
void Unk_2401df0::vf4() {
    field_31 = 1;
}

// 0x7100f9e000
void Unk_2401df0::vf5() {
    field_32 = 1;
}

// 0x7100f9e020
void Unk_2401df0::vf6() {
    field_33 = 1;
}

class Unk_23ce100 {
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
    u32 field_8;
    u8 _c[0x44];
    u8 field_50;
};
PKMN_OFFSET_ASSERT(Unk_23ce100, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_23ce100, field_50, 0x50);

// 0x7100f9e750
void Unk_23ce100::vf3() {}
