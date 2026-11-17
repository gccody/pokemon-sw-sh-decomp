// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2416c58 {
public:
    virtual ~Unk_2416c58();
    virtual void vf2() = 0;
    virtual void vf3() = 0;
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
PKMN_OFFSET_ASSERT(Unk_2416c58, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_2416c58, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_2416c58, field_14, 0x14);

// 0x71010eb280
void Unk_2416c58::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010eb290
void Unk_2416c58::vf6(u64 value) {
    field_8 = value;
}

// 0x71010eb2a0
u64 Unk_2416c58::vf7() {
    return field_8;
}

// 0x71010eb2b0
u8 Unk_2416c58::vf8() {
    return field_10;
}

// 0x71010eb0c0
void Unk_2416c58::vf9(u32 value) {
    field_14 = value;
}

// 0x71010eb0b0
u32 Unk_2416c58::vf10() {
    return field_14;
}

class Unk_2416b58 {
public:
    virtual ~Unk_2416b58();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(u32 value);
    virtual void vf13();
    u8 _8[0xc];
    u32 field_14;
    u8 _18[0x2a];
    u8 field_42;
};
PKMN_OFFSET_ASSERT(Unk_2416b58, field_14, 0x14);
PKMN_OFFSET_ASSERT(Unk_2416b58, field_42, 0x42);

// 0x71010eb0d0
u32 Unk_2416b58::vf3() {
    return 1;
}

// 0x71010eb0e0
void Unk_2416b58::vf12(u32 value) {
    field_42 = value == 0x1c8;
    field_14 = 2;
}
