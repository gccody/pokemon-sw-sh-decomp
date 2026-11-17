// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12cdff0(void* self);

class Unk_242ea28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71012ef770
void Unk_242ea28::vf6() {
    Unk_12cdff0(this);
}

class Unk_242ea70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012ef780
void Unk_242ea70::vf5() {
    Unk_12cdff0(this);
}

class Unk_242eab0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012ef790
void Unk_242eab0::vf0() {
    Unk_12cdff0(this);
}
