// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d7e740(void* self);

class Unk_23edac0 {
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

// 0x7100d7cc60
u32 Unk_23edac0::vf7() {
    return 1;
}

class Unk_23edb90 {
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

// 0x7100d7e710
void Unk_23edb90::vf6() {
    Unk_d7e740(this);
}

// 0x7100d7e440
u32 Unk_23edb90::vf7() {
    return 1;
}

// 0x7100d7e450
void Unk_23edb90::vf8() {}

// 0x7100d7e700
void Unk_23edb90::vf10() {}

class Unk_23edbf8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d7e720
void Unk_23edbf8::vf5() {
    Unk_d7e740(this);
}

class Unk_23edc38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d7e730
void Unk_23edc38::vf0() {
    Unk_d7e740(this);
}
