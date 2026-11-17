// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12a53e0(void* self);

class Unk_242b7a0 {
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

// 0x71012a51f0
void Unk_242b7a0::vf6() {
    Unk_12a53e0(this);
}

class Unk_242b808 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012a52e0
void Unk_242b808::vf5() {
    Unk_12a53e0(this);
}

class Unk_242b848 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012a52f0
void Unk_242b848::vf0() {
    Unk_12a53e0(this);
}
