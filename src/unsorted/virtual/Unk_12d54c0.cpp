// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12d57f0(void* self);

class Unk_242d2f8 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x71012d54c0
void Unk_242d2f8::vf6() {
    Unk_12d57f0(this);
}

class Unk_242d390 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012d5650
void Unk_242d390::vf5() {
    Unk_12d57f0(this);
}

class Unk_242d3d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012d5660
void Unk_242d3d0::vf0() {
    Unk_12d57f0(this);
}
