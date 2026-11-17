// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e41a80(void* self);

class Unk_23f1b08 {
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
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
};

// 0x7100e417e0
void Unk_23f1b08::vf6() {
    Unk_e41a80(this);
}

// 0x7100e413e0
void Unk_23f1b08::vf8() {}

// 0x7100e413f0
u32 Unk_23f1b08::vf9() {
    return 1;
}

class Unk_23f1b80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e418b0
void Unk_23f1b80::vf5() {
    Unk_e41a80(this);
}

class Unk_23f1bc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e418c0
void Unk_23f1bc0::vf0() {
    Unk_e41a80(this);
}
