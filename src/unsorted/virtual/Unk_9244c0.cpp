// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_924560(void* self);

class Unk_23bec40 {
public:
    virtual ~Unk_23bec40();
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

// 0x71009244f0
void Unk_23bec40::vf6() {
    Unk_924560(this);
}

// 0x71009244c0
u32 Unk_23bec40::vf8() {
    return 0;
}

// 0x71009244d0
void Unk_23bec40::vf9() {}

class Unk_23beca8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100924520
void Unk_23beca8::vf5() {
    Unk_924560(this);
}

class Unk_23bece8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100924530
void Unk_23bece8::vf0() {
    Unk_924560(this);
}
