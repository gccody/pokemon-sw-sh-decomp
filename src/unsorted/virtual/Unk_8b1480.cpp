// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23b9c10 {
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
    virtual void vf17();
    virtual void vf18();
    u8 _8[0xc8];
    u8 field_d0;
};
PKMN_OFFSET_ASSERT(Unk_23b9c10, field_d0, 0xd0);

// 0x71008b14a0
void Unk_23b9c10::vf0() {}

// 0x71008b14b0
void Unk_23b9c10::vf1() {
    field_d0 = 1;
}

// 0x71008b1760
void Unk_23b9c10::vf2() {}

// 0x71008b1770
void Unk_23b9c10::vf3() {}

// 0x71008b14c0
void Unk_23b9c10::vf4() {
    field_d0 = 1;
}

// 0x71008b14d0
void Unk_23b9c10::vf5() {
    field_d0 = 1;
}

// 0x71008b1780
void Unk_23b9c10::vf6() {}

// 0x71008b1790
void Unk_23b9c10::vf7() {}

// 0x71008b1480
void Unk_23b9c10::vf18() {}

class Unk_23b9cb8 {
public:
    virtual void vf0();
};

// 0x71008b1490
void Unk_23b9cb8::vf0() {}

class Unk_23b9e78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23b9e78, field_78, 0x78);

// 0x71008b2c60
u64 Unk_23b9e78::vf7() {
    return field_78;
}
