// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24127e8 {
public:
    virtual ~Unk_24127e8();
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
PKMN_OFFSET_ASSERT(Unk_24127e8, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24127e8, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24127e8, field_14, 0x14);

// 0x71010b94d0
u32 Unk_24127e8::vf3() {
    return 1;
}

// 0x71010b95c0
void Unk_24127e8::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x71010b95d0
void Unk_24127e8::vf6(u64 value) {
    field_8 = value;
}

// 0x71010b95e0
u64 Unk_24127e8::vf7() {
    return field_8;
}

// 0x71010b95f0
u8 Unk_24127e8::vf8() {
    return field_10;
}

// 0x71010b9600
void Unk_24127e8::vf9(u32 value) {
    field_14 = value;
}

// 0x71010b9610
u32 Unk_24127e8::vf10() {
    return field_14;
}
