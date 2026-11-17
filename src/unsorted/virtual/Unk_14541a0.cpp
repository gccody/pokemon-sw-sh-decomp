// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243c9c8 {
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

// 0x71014541a0
u32 Unk_243c9c8::vf7() {
    return 1;
}

// 0x71014541b0
void Unk_243c9c8::vf8() {}

// 0x71014543c0
void Unk_243c9c8::vf10() {}

class Unk_243cad8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101455280
u32 Unk_243cad8::vf0() {
    return 1;
}
