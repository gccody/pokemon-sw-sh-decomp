// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_9275c0(void* self);

class Unk_23bf1a0 {
public:
    virtual ~Unk_23bf1a0();
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

// 0x7100927550
void Unk_23bf1a0::vf6() {
    Unk_9275c0(this);
}

// 0x7100927530
void Unk_23bf1a0::vf9() {}

class Unk_23bf208 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100927580
void Unk_23bf208::vf5() {
    Unk_9275c0(this);
}

class Unk_23bf248 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100927590
void Unk_23bf248::vf0() {
    Unk_9275c0(this);
}
