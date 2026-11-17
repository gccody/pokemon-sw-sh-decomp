// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12ca440(void* self);

class Unk_242cfd0 {
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

// 0x71012ca410
void Unk_242cfd0::vf6() {
    Unk_12ca440(this);
}

// 0x71012ca0e0
u32 Unk_242cfd0::vf7() {
    return 1;
}

class Unk_242d038 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012ca420
void Unk_242d038::vf5() {
    Unk_12ca440(this);
}

class Unk_242d078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012ca430
void Unk_242d078::vf0() {
    Unk_12ca440(this);
}
