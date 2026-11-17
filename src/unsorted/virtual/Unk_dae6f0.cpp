// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_daedc0(void* self);

class Unk_23ef4d8 {
public:
    virtual ~Unk_23ef4d8();
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

// 0x7100daed50
void Unk_23ef4d8::vf6() {
    Unk_daedc0(this);
}

// 0x7100dae6f0
u32 Unk_23ef4d8::vf7() {
    return 1;
}

// 0x7100dae700
void Unk_23ef4d8::vf8() {}

// 0x7100daed30
void Unk_23ef4d8::vf10() {}

class Unk_23ef540 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100daed80
void Unk_23ef540::vf5() {
    Unk_daedc0(this);
}

class Unk_23ef580 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100daed90
void Unk_23ef580::vf0() {
    Unk_daedc0(this);
}
