// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ebc30(void* self);

class Unk_242e568 {
public:
    virtual ~Unk_242e568();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x71012ebbc0
void Unk_242e568::vf6() {
    Unk_12ebc30(this);
}

// 0x71012ebb90
u32 Unk_242e568::vf8() {
    return 1;
}

// 0x71012ebba0
void Unk_242e568::vf9() {}

class Unk_242e5d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012ebbf0
void Unk_242e5d0::vf5() {
    Unk_12ebc30(this);
}

class Unk_242e610 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012ebc00
void Unk_242e610::vf0() {
    Unk_12ebc30(this);
}
