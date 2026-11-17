// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23f1ed8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e47110
u32 Unk_23f1ed8::vf0() {
    return 1;
}

class Unk_23f1f08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual u32 vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10();
    virtual void vf11();
};

// 0x7100e47360
void Unk_23f1f08::vf1() {}

// 0x7100e47370
void Unk_23f1f08::vf5() {}

// 0x7100e47380
u32 Unk_23f1f08::vf6() {
    return 1;
}

// 0x7100e47390
void Unk_23f1f08::vf7() {}

// 0x7100e473a0
void Unk_23f1f08::vf8() {}

// 0x7100e473b0
void Unk_23f1f08::vf9() {}

// 0x7100e473c0
u32 Unk_23f1f08::vf10() {
    return 1;
}

// 0x7100e473d0
void Unk_23f1f08::vf11() {}

class Unk_23f1f78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e473e0
void Unk_23f1f78::vf0() {}

// 0x7100e473f0
void Unk_23f1f78::vf1() {}

class Unk_23f1fa8 {
public:
    virtual ~Unk_23f1fa8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u32 value);
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    u8 _8[0x280];
    u32 field_288;
};
PKMN_OFFSET_ASSERT(Unk_23f1fa8, field_288, 0x288);

// 0x7100e4a640
void Unk_23f1fa8::vf5(u32 value) {
    field_288 = value;
}
