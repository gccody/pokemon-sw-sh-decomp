// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_dc2200(void* self);

class Unk_23efa58 {
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

// 0x7100dc1f10
void Unk_23efa58::vf6() {
    Unk_dc2200(this);
}

// 0x7100dbfa10
u32 Unk_23efa58::vf7() {
    return 1;
}

class Unk_23efac0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100dc2000
void Unk_23efac0::vf5() {
    Unk_dc2200(this);
}

class Unk_23efb00 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100dc2010
void Unk_23efb00::vf0() {
    Unk_dc2200(this);
}
