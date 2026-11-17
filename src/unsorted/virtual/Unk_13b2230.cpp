// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2434918 {
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
    virtual u32 vf9();
    virtual u32 vf10();
    virtual u32 vf11();
};

// 0x71013b2230
u32 Unk_2434918::vf9() {
    return 1;
}

// 0x71013b2240
u32 Unk_2434918::vf10() {
    return 1;
}

// 0x71013b2250
u32 Unk_2434918::vf11() {
    return 1;
}
