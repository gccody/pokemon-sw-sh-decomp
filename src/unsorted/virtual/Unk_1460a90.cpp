// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_243d398 {
public:
    virtual ~Unk_243d398();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101460a90
void Unk_243d398::vf9() {}

class Unk_243d468 {
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

// 0x7101460e00
u32 Unk_243d468::vf7() {
    return 1;
}

// 0x7101460e10
void Unk_243d468::vf8() {}

// 0x7101460f00
void Unk_243d468::vf10() {}

class Unk_243d578 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101461cd0
u32 Unk_243d578::vf0() {
    return 4;
}
