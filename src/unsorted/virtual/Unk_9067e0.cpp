// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_906850(void* self);

class Unk_23bda50 {
public:
    virtual ~Unk_23bda50();
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

// 0x71009067e0
void Unk_23bda50::vf6() {
    Unk_906850(this);
}

class Unk_23bdae8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100906810
void Unk_23bdae8::vf5() {
    Unk_906850(this);
}

class Unk_23bdb28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100906820
void Unk_23bdb28::vf0() {
    Unk_906850(this);
}
