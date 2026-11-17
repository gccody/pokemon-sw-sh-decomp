// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a85130(void* self);

class Unk_23c71a0 {
public:
    virtual ~Unk_23c71a0();
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

// 0x7100a850c0
void Unk_23c71a0::vf6() {
    Unk_a85130(this);
}

// 0x7100a850a0
void Unk_23c71a0::vf9() {}

class Unk_23c7208 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a850f0
void Unk_23c7208::vf5() {
    Unk_a85130(this);
}

class Unk_23c7248 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a85100
void Unk_23c7248::vf0() {
    Unk_a85130(this);
}
