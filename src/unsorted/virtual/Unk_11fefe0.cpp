// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1200540(void* self);

class Unk_2422d48 {
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

// 0x71012001d0
void Unk_2422d48::vf6() {
    Unk_1200540(this);
}

// 0x71011fefe0
void Unk_2422d48::vf9() {}

class Unk_2422db0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101200380
void Unk_2422db0::vf5() {
    Unk_1200540(this);
}

class Unk_2422df0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101200390
void Unk_2422df0::vf0() {
    Unk_1200540(this);
}
