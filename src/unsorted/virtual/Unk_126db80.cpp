// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_126c9e0(void* self);

class Unk_2428680 {
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

// 0x710126db80
void Unk_2428680::vf6() {
    Unk_126c9e0(this);
}

class Unk_2428718 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710126dd50
void Unk_2428718::vf5() {
    Unk_126c9e0(this);
}

class Unk_2428758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710126dd60
void Unk_2428758::vf0() {
    Unk_126c9e0(this);
}
