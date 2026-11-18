// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240ce88 {
public:
    virtual ~Unk_240ce88();
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
PKMN_OFFSET_ASSERT(Unk_240ce88, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_240ce88, field_14, 0x14);

// 0x7101079d10
void Unk_240ce88::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x7101079d20
void Unk_240ce88::vf6(u64 value) {
    field_8 = value;
}

// 0x7101079d30
u64 Unk_240ce88::vf7() {
    return field_8;
}

// 0x7101079d40
u8 Unk_240ce88::vf8() {
    return field_10;
}

// 0x7101079c10
void Unk_240ce88::vf9(u32 value) {
    field_14 = value;
}

// 0x7101079c00
u32 Unk_240ce88::vf10() {
    return field_14;
}

class Unk_240ce18 {
public:
    virtual ~Unk_240ce18();
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
};

// 0x7101079c20
u32 Unk_240ce18::vf3() {
    return 1;
}
