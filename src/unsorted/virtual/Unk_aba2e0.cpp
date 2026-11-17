// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_23c8808 {
public:
    virtual ~Unk_23c8808();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

// 0x7100aba2e0
void Unk_23c8808::vf14() {}

class Unk_23c8900 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100aba2f0
void Unk_23c8900::vf1() {}

class Unk_23c8928 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

// 0x7100abcf10
u32 Unk_23c8928::vf8() {
    return 1;
}

class Unk_23c8a48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

// 0x7100abd310
u32 Unk_23c8a48::vf8() {
    return 2;
}

class Unk_23c8b68 {
public:
    virtual ~Unk_23c8b68();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

// 0x7100abd7f0
u32 Unk_23c8b68::vf8() {
    return 3;
}
