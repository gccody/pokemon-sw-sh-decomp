// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1454900(void* self);

class Unk_243c9c8 {
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

// 0x7101454690
void Unk_243c9c8::vf6() {
    Unk_1454900(this);
}

// 0x71014541a0
u32 Unk_243c9c8::vf7() {
    return 1;
}

// 0x71014541b0
void Unk_243c9c8::vf8() {}

// 0x71014543c0
void Unk_243c9c8::vf10() {}

class Unk_243ca30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014547c0
void Unk_243ca30::vf5() {
    Unk_1454900(this);
}

class Unk_243ca70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014547d0
void Unk_243ca70::vf0() {
    Unk_1454900(this);
}

class Unk_243cad8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101455280
u32 Unk_243cad8::vf0() {
    return 1;
}
