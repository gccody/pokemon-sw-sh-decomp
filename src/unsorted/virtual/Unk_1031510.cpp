// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24096c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101031510
void Unk_24096c8::vf5() {}

class Unk_2409710 {
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

// 0x7101031ab0
void Unk_2409710::vf1() {}

// 0x7101031ac0
void Unk_2409710::vf2() {}

// 0x7101031ad0
void Unk_2409710::vf3() {}

// 0x7101031520
void Unk_2409710::vf5() {}

// 0x7101031ae0
void Unk_2409710::vf6() {}

// 0x7101031af0
void Unk_2409710::vf7() {}
