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
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x71011039c0
u32 Unk_24185a0::vf3() {
    return 1;
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
