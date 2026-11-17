// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24109d0 {
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
    u8 _8[0x60];
    u16 field_68;
};
PKMN_OFFSET_ASSERT(Unk_24109d0, field_68, 0x68);

// 0x71010a4170
void Unk_24109d0::vf8() {
    field_68 = 1;
}

class Unk_2410a90 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2410a90, field_8, 0x8);

// 0x71010a4c80
void Unk_2410a90::vf1() {}

// 0x71010a4180
void Unk_2410a90::vf5() {
    field_8 = 1;
}

class Unk_2410ad8 {
public:
    virtual ~Unk_2410ad8();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u64 value);
    virtual u64 vf7();
    virtual u8 vf8();
    virtual void vf9(u32 value);
    virtual u32 vf10();
    virtual void vf11();
    u64 field_8;
    u8 field_10;
    u8 _11[0x3];
    u32 field_14;
};
PKMN_OFFSET_ASSERT(Unk_2410ad8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2410ad8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2410ad8, field_14, 0x14);

// 0x71010a4800
u32 Unk_2410ad8::vf3() {
    return 1;
}

// 0x71010a4df0
void Unk_2410ad8::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010a4e00
void Unk_2410ad8::vf6(u64 value) {
    field_8 = value;
}

// 0x71010a4e10
u64 Unk_2410ad8::vf7() {
    return field_8;
}

// 0x71010a4e20
u8 Unk_2410ad8::vf8() {
    return field_10;
}

// 0x71010a46b0
void Unk_2410ad8::vf9(u32 value) {
    field_14 = value;
}

// 0x71010a46a0
u32 Unk_2410ad8::vf10() {
    return field_14;
}
