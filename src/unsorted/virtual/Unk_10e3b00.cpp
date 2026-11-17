// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24160a8 {
public:
    virtual ~Unk_24160a8();
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
PKMN_OFFSET_ASSERT(Unk_24160a8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24160a8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24160a8, field_14, 0x14);

// 0x71010e3ed0
void Unk_24160a8::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010e3ee0
void Unk_24160a8::vf6(u64 value) {
    field_8 = value;
}

// 0x71010e3ef0
u64 Unk_24160a8::vf7() {
    return field_8;
}

// 0x71010e3f00
u8 Unk_24160a8::vf8() {
    return field_10;
}

// 0x71010e3b10
void Unk_24160a8::vf9(u32 value) {
    field_14 = value;
}

// 0x71010e3b00
u32 Unk_24160a8::vf10() {
    return field_14;
}

class Unk_2415fa8 {
public:
    virtual ~Unk_2415fa8();
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
    virtual void vf12();
    virtual void vf13();
};

// 0x71010e3b20
u32 Unk_2415fa8::vf3() {
    return 1;
}
