// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6d7ac0(u64, u64, u32);

struct Unk_2405578_a8 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_2405578_a8, field_2a0, 0x2a0);

class Unk_2405578 {
public:
    virtual ~Unk_2405578();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u64 /*unused*/, u64 arg2);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    u8 _8[0x89];
    u8 field_91;
    u8 field_92;
    u8 _93[0x15];
    Unk_2405578_a8* field_a8;
};
PKMN_OFFSET_ASSERT(Unk_2405578, field_91, 0x91);
PKMN_OFFSET_ASSERT(Unk_2405578, field_92, 0x92);
PKMN_OFFSET_ASSERT(Unk_2405578, field_a8, 0xa8);

// 0x7100fe7600
void Unk_2405578::vf7() {}

// 0x7100fe7620
void Unk_2405578::vf8() {
    field_91 = 1;
}

// 0x7100fe7640
void Unk_2405578::vf9(u64 /*unused*/, u64 arg2) {
    if (field_a8 != nullptr) {
        Unk_6d7ac0(field_a8->field_2a0, arg2, 1);
    }
}

// 0x7100fe7990
void Unk_2405578::vf11() {
    field_92 = 1;
}

class Unk_2405658 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x29];
    u8 field_31;
};
PKMN_OFFSET_ASSERT(Unk_2405658, field_31, 0x31);

// 0x7100fe7610
void Unk_2405658::vf0() {}

// 0x7100fe7630
void Unk_2405658::vf1() {
    field_31 = 1;
}

// 0x7100fe7bc0
void Unk_2405658::vf2() {}

// 0x7100fe7bd0
void Unk_2405658::vf3() {}

// 0x7100fe7be0
void Unk_2405658::vf4() {}

// 0x7100fe7bf0
void Unk_2405658::vf5() {}

// 0x7100fe7c00
void Unk_2405658::vf6() {}

// 0x7100fe7c10
void Unk_2405658::vf7() {}

struct Unk_24056a8_40 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_24056a8_40, field_2a0, 0x2a0);

class Unk_24056a8 {
public:
    virtual void vf0(u64 /*unused*/, u64 arg2);
    virtual void vf1();
    u8 _8[0x38];
    Unk_24056a8_40* field_40;
};
PKMN_OFFSET_ASSERT(Unk_24056a8, field_40, 0x40);

// 0x7100fe7660
void Unk_24056a8::vf0(u64 /*unused*/, u64 arg2) {
    if (field_40 != nullptr) {
        Unk_6d7ac0(field_40->field_2a0, arg2, 1);
    }
}

class Unk_24056c8 {
public:
    virtual void vf0();
    u8 _8[0x1a];
    u8 field_22;
};
PKMN_OFFSET_ASSERT(Unk_24056c8, field_22, 0x22);

// 0x7100fe79a0
void Unk_24056c8::vf0() {
    field_22 = 1;
}

class Unk_2405910 {
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
PKMN_OFFSET_ASSERT(Unk_2405910, field_78, 0x78);

// 0x7100fe9b10
u64 Unk_2405910::vf7() {
    return field_78;
}
