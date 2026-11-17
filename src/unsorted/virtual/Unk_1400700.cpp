// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14028b0(void* self);

class Unk_24373e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101400700
u32 Unk_24373e8::vf0() {
    return 0xa;
}

class Unk_2437578 {
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

// 0x7101402700
void Unk_2437578::vf6() {
    Unk_14028b0(this);
}

// 0x7101401dc0
u32 Unk_2437578::vf7() {
    return 1;
}

class Unk_24375e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71014027d0
void Unk_24375e0::vf5() {
    Unk_14028b0(this);
}

class Unk_2437620 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71014027e0
void Unk_2437620::vf0() {
    Unk_14028b0(this);
}
