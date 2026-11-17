// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f2cb20(void* self);

class Unk_23fc7a8 {
public:
    virtual ~Unk_23fc7a8();
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

// 0x7100f2cab0
void Unk_23fc7a8::vf6() {
    Unk_f2cb20(this);
}

// 0x7100f2ca90
void Unk_23fc7a8::vf9() {}

class Unk_23fc810 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f2cae0
void Unk_23fc810::vf5() {
    Unk_f2cb20(this);
}

class Unk_23fc850 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f2caf0
void Unk_23fc850::vf0() {
    Unk_f2cb20(this);
}
