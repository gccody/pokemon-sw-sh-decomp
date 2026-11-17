// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_8b0ee0(void*);

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
    u8 _d1[0x7];
    u64 field_d8;
    u8 _e0[0x8];
    u8 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23b9c10, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_23b9c10, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_23b9c10, field_e8, 0xe8);

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

// 0x71008b0ec0
void Unk_23b9c10::vf12() {
    if (field_d8 != 0) {
        Unk_8b0ee0(&field_e8);
    }
}

// 0x71008b1480
void Unk_23b9c10::vf18() {}

class Unk_23b9cd0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0xc0];
    u64 field_c8;
    u8 _d0[0x8];
    u8 field_d8;
};
PKMN_OFFSET_ASSERT(Unk_23b9cd0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_23b9cd0, field_d8, 0xd8);

// 0x71008b1000
void Unk_23b9cd0::vf0() {
    if (field_c8 != 0) {
        Unk_8b0ee0(&field_d8);
    }
}

class Unk_23b9cb8 {
public:
    virtual void vf0();
};

// 0x71008b1490
void Unk_23b9cb8::vf0() {}
