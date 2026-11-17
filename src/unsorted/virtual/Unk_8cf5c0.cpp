// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23bb818 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008cf5c0
u32 Unk_23bb818::vf0() {
    return 0xc;
}

class Unk_23bb848 {
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

// 0x71008cfb90
u32 Unk_23bb848::vf7() {
    return 1;
}

// 0x71008cfd00
void Unk_23bb848::vf10() {}

class Unk_23bb958 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71008d0940
u32 Unk_23bb958::vf0() {
    return 1;
}
