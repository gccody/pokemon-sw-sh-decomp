// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24185a0 {
public:
    virtual ~Unk_24185a0();
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
PKMN_OFFSET_ASSERT(Unk_24185a0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_24185a0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_24185a0, field_14, 0x14);

// 0x71011039c0
u32 Unk_24185a0::vf3() {
    return 1;
}

// 0x7101103c20
void Unk_24185a0::vf5() {
    field_14 = 0;
    field_10 = 1;
}

// 0x7101103c30
void Unk_24185a0::vf6(u64 value) {
    field_8 = value;
}

// 0x7101103c40
u64 Unk_24185a0::vf7() {
    return field_8;
}

// 0x7101103c50
u8 Unk_24185a0::vf8() {
    return field_10;
}

// 0x71011039b0
void Unk_24185a0::vf9(u32 value) {
    field_14 = value;
}

// 0x71011039a0
u32 Unk_24185a0::vf10() {
    return field_14;
}

class Unk_2418680 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101103d00
void Unk_2418680::vf0() {}

// 0x7101103d10
void Unk_2418680::vf1() {}

// 0x7101103d20
void Unk_2418680::vf2() {}
