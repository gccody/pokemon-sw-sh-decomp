// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23ed920 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100d76000
u32 Unk_23ed920::vf7() {
    return 1;
}

// 0x7100d79900
void Unk_23ed920::vf10() {}

class Unk_23ed9f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100d7b2b0
u32 Unk_23ed9f0::vf7() {
    return 1;
}

// 0x7100d7b2c0
void Unk_23ed9f0::vf8() {}

// 0x7100d7b950
void Unk_23ed9f0::vf10() {}
