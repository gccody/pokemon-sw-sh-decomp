// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_240a058 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7101039d90
void Unk_240a058::vf1() {}

// 0x7101039da0
void Unk_240a058::vf2() {}

// 0x7101039db0
void Unk_240a058::vf3() {}

// 0x7101039dc0
void Unk_240a058::vf4() {}

// 0x7101039dd0
void Unk_240a058::vf5() {}

// 0x7101039de0
void Unk_240a058::vf6() {}

// 0x7101039df0
void Unk_240a058::vf7() {}

class Unk_240a200 {
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
PKMN_OFFSET_ASSERT(Unk_240a200, field_78, 0x78);

// 0x710103b330
u64 Unk_240a200::vf7() {
    return field_78;
}
