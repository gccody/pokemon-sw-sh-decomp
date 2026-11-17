// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2432458 {
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
    virtual u8* vf11();
    virtual u32 vf12();
    virtual void vf13();
    u8 _8[0x58];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_2432458, field_60, 0x60);

// 0x7101368ec0
u8* Unk_2432458::vf11() {
    return &field_60;
}

// 0x7101368ed0
u32 Unk_2432458::vf12() {
    return 0x12f8;
}

class Unk_2432d90 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101380310
u32 Unk_2432d90::vf0() {
    return 2;
}
