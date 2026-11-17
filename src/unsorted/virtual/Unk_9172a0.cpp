// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_9177a0(void* self);

class Unk_23be058 {
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

// 0x71009172a0
void Unk_23be058::vf6() {
    Unk_9177a0(this);
}

class Unk_23be0f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100917470
void Unk_23be0f0::vf5() {
    Unk_9177a0(this);
}

class Unk_23be130 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100917480
void Unk_23be130::vf0() {
    Unk_9177a0(this);
}
