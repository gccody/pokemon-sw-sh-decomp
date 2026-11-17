// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2415328 {
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
PKMN_OFFSET_ASSERT(Unk_2415328, field_68, 0x68);

// 0x71010d9c40
void Unk_2415328::vf8() {
    field_68 = 1;
}

class Unk_24153e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    u16 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24153e8, field_8, 0x8);

// 0x71010da630
void Unk_24153e8::vf1() {}

// 0x71010d9c50
void Unk_24153e8::vf2() {
    field_8 = 1;
}

// 0x71010da640
void Unk_24153e8::vf3() {}

class Unk_2415418 {
public:
    virtual ~Unk_2415418();
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
PKMN_OFFSET_ASSERT(Unk_2415418, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2415418, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2415418, field_14, 0x14);

// 0x71010da1b0
u32 Unk_2415418::vf3() {
    return 1;
}

// 0x71010da7d0
void Unk_2415418::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010da7e0
void Unk_2415418::vf6(u64 value) {
    field_8 = value;
}

// 0x71010da7f0
u64 Unk_2415418::vf7() {
    return field_8;
}

// 0x71010da800
u8 Unk_2415418::vf8() {
    return field_10;
}

// 0x71010da1a0
void Unk_2415418::vf9(u32 value) {
    field_14 = value;
}

// 0x71010da190
u32 Unk_2415418::vf10() {
    return field_14;
}
