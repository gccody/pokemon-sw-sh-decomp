// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e67540(void* self);

class Unk_23f2df0 {
public:
    virtual ~Unk_23f2df0();
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
    virtual void vf13() = 0;
    virtual void vf14();
    virtual void vf15();
    virtual void vf16() = 0;
};

// 0x7100e67490
void Unk_23f2df0::vf6() {
    Unk_e67540(this);
}

// 0x7100e67320
u32 Unk_23f2df0::vf9() {
    return 1;
}

// 0x7100e674a0
void Unk_23f2df0::vf10() {}

// 0x7100e674b0
void Unk_23f2df0::vf11() {}

// 0x7100e674c0
void Unk_23f2df0::vf14() {}

// 0x7100e674d0
void Unk_23f2df0::vf15() {}

class Unk_23f2e88 {
public:
    virtual ~Unk_23f2e88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e67500
void Unk_23f2e88::vf5() {
    Unk_e67540(this);
}

class Unk_23f2ec8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e67510
void Unk_23f2ec8::vf0() {
    Unk_e67540(this);
}
