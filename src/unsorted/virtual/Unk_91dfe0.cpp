// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_91e2c0(void* self);

class Unk_23be6c8 {
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
};

// 0x710091e0d0
void Unk_23be6c8::vf6() {
    Unk_91e2c0(this);
}

// 0x710091dfe0
void Unk_23be6c8::vf9() {}

class Unk_23be730 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710091e1c0
void Unk_23be730::vf5() {
    Unk_91e2c0(this);
}

class Unk_23be770 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710091e1d0
void Unk_23be770::vf0() {
    Unk_91e2c0(this);
}
