// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24174f0 {
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
PKMN_OFFSET_ASSERT(Unk_24174f0, field_68, 0x68);

// 0x71010f17b0
void Unk_24174f0::vf7() {
    field_68 = 0x101;
}

class Unk_24175b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24175b0, field_8, 0x8);

// 0x71010f17c0
void Unk_24175b0::vf0() {
    field_8 = 0x101;
}

// 0x71010f1e60
void Unk_24175b0::vf2() {}

class Unk_24175f0 {
public:
    virtual ~Unk_24175f0();
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
PKMN_OFFSET_ASSERT(Unk_24175f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24175f0, field_14, 0x14);

// 0x71010f1bb0
u32 Unk_24175f0::vf3() {
    return 1;
}

// 0x71010f1f90
void Unk_24175f0::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010f1fa0
void Unk_24175f0::vf6(u64 value) {
    field_8 = value;
}

// 0x71010f1fb0
u64 Unk_24175f0::vf7() {
    return field_8;
}

// 0x71010f1fc0
u8 Unk_24175f0::vf8() {
    return field_10;
}

// 0x71010f1ba0
void Unk_24175f0::vf9(u32 value) {
    field_14 = value;
}

// 0x71010f1b90
u32 Unk_24175f0::vf10() {
    return field_14;
}
