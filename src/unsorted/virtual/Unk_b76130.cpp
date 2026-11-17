// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

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
