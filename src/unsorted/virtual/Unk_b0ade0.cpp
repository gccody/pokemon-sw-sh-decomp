// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23cd948 {
public:
    virtual ~Unk_23cd948();
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
    u8 _8[0x9c];
    u8 field_a4;
    u8 _a5[0x3];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_23cd948, field_a4, 0xa4);
PKMN_OFFSET_ASSERT(Unk_23cd948, field_a8, 0xa8);

// 0x7100b0ade0
void Unk_23cd948::vf9() {}

// 0x7100b0caa0
void Unk_23cd948::vf11() {
    field_a8 = 2;
    field_a4 = 1;
}

// 0x7100b0cb80
void Unk_23cd948::vf14() {
    field_a8 = 0x12;
    field_a4 = 1;
}

class Unk_23cda40 {
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
    u8 _8[0x14];
    u8 field_1c;
    u8 _1d[0x3];
    u32 field_20;
};
PKMN_OFFSET_ASSERT(Unk_23cda40, field_1c, 0x1c);
PKMN_OFFSET_ASSERT(Unk_23cda40, field_20, 0x20);

// 0x7100b0cac0
void Unk_23cda40::vf2() {
    field_20 = 2;
    field_1c = 1;
}

// 0x7100b0cba0
void Unk_23cda40::vf5() {
    field_20 = 0x12;
    field_1c = 1;
}
