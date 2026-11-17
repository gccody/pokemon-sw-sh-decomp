// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f353a0(void* self);

class Unk_23fc910 {
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

// 0x7100f34e80
void Unk_23fc910::vf6() {
    Unk_f353a0(this);
}

// 0x7100f32cd0
void Unk_23fc910::vf9() {}

class Unk_23fc978 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f34ff0
void Unk_23fc978::vf5() {
    Unk_f353a0(this);
}

class Unk_23fc9b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f35000
void Unk_23fc9b8::vf0() {
    Unk_f353a0(this);
}
