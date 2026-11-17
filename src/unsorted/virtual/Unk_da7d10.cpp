// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da7f10(void* self);

class Unk_23ef178 {
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

// 0x7100da7ee0
void Unk_23ef178::vf6() {
    Unk_da7f10(this);
}

// 0x7100da7d10
u32 Unk_23ef178::vf7() {
    return 1;
}

class Unk_23ef1e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da7ef0
void Unk_23ef1e0::vf5() {
    Unk_da7f10(this);
}

class Unk_23ef220 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da7f00
void Unk_23ef220::vf0() {
    Unk_da7f10(this);
}
