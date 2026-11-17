// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2410378 {
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
PKMN_OFFSET_ASSERT(Unk_2410378, field_68, 0x68);

// 0x71010a0c10
void Unk_2410378::vf7() {
    field_68 = 0x101;
}

// 0x71010a0c30
void Unk_2410378::vf8() {
    field_68 = 1;
}

class Unk_2410438 {
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
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2410438, field_8, 0x8);

// 0x71010a0c20
void Unk_2410438::vf4() {
    field_8 = 0x101;
}

// 0x71010a0c40
void Unk_2410438::vf11() {
    field_8 = 1;
}

class Unk_24104b0 {
public:
    virtual ~Unk_24104b0();
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
PKMN_OFFSET_ASSERT(Unk_24104b0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24104b0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24104b0, field_14, 0x14);

// 0x71010a11d0
u32 Unk_24104b0::vf3() {
    return 1;
}

// 0x71010a15a0
void Unk_24104b0::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010a15b0
void Unk_24104b0::vf6(u64 value) {
    field_8 = value;
}

// 0x71010a15c0
u64 Unk_24104b0::vf7() {
    return field_8;
}

// 0x71010a15d0
u8 Unk_24104b0::vf8() {
    return field_10;
}

// 0x71010a11c0
void Unk_24104b0::vf9(u32 value) {
    field_14 = value;
}

// 0x71010a11b0
u32 Unk_24104b0::vf10() {
    return field_14;
}
