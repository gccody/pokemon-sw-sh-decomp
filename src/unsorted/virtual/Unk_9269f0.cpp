// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_926c70(void* self);

class Unk_23bf0d0 {
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
};

// 0x7100926ac0
void Unk_23bf0d0::vf6() {
    Unk_926c70(this);
}

// 0x71009269f0
void Unk_23bf0d0::vf9() {}

class Unk_23bf138 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100926b90
void Unk_23bf138::vf5() {
    Unk_926c70(this);
}

class Unk_23bf178 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100926ba0
void Unk_23bf178::vf0() {
    Unk_926c70(this);
}
