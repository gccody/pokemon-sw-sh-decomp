// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24173f0 {
public:
    virtual ~Unk_24173f0();
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

// 0x71010f0d20
u32 Unk_24173f0::vf3() {
    return 1;
}

class Unk_24173b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71010f11a0
void Unk_24173b0::vf0() {}

// 0x71010f11b0
void Unk_24173b0::vf1() {}

// 0x71010f11c0
void Unk_24173b0::vf3() {}

// 0x71010f11d0
void Unk_24173b0::vf5() {}
