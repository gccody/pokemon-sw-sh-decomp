// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_967370(void* self);

class Unk_23bdd70 {
public:
    virtual ~Unk_23bdd70();
    virtual void vf2();
};

// 0x710090e2d0
void Unk_23bdd70::vf2() {}

class Unk_23bdd98 {
public:
    virtual ~Unk_23bdd98();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710090f020
void Unk_23bdd98::vf6() {
    Unk_967370(this);
}

class Unk_23bdde0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710090f050
void Unk_23bdde0::vf5() {
    Unk_967370(this);
}

class Unk_23bde20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710090f060
void Unk_23bde20::vf0() {
    Unk_967370(this);
}
