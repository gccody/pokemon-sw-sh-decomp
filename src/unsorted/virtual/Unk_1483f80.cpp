// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1484170(void* self);

class Unk_243f988 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101483f80
void Unk_243f988::vf6() {
    Unk_1484170(this);
}

class Unk_243f9d0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101484070
void Unk_243f9d0::vf5() {
    Unk_1484170(this);
}

class Unk_243fa10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101484080
void Unk_243fa10::vf0() {
    Unk_1484170(this);
}
