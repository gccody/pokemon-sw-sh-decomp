// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ee21f0(void* self);

class Unk_23f7e30 {
public:
    virtual ~Unk_23f7e30();
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
};

// 0x7100ee2180
void Unk_23f7e30::vf6() {
    Unk_ee21f0(this);
}

// 0x7100ee14a0
void Unk_23f7e30::vf12() {}

// 0x7100ee14c0
void Unk_23f7e30::vf13() {}

class Unk_23f7eb0 {
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
};

// 0x7100ee21b0
void Unk_23f7eb0::vf5() {
    Unk_ee21f0(this);
}

// 0x7100ee14b0
void Unk_23f7eb0::vf10() {}

// 0x7100ee14d0
void Unk_23f7eb0::vf11() {}

class Unk_23f7f20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ee21c0
void Unk_23f7f20::vf0() {
    Unk_ee21f0(this);
}
