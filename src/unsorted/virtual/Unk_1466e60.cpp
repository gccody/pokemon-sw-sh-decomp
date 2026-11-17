// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1467080(void* self);

class Unk_243d5a8 {
public:
    virtual ~Unk_243d5a8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101466e60
void Unk_243d5a8::vf6() {
    Unk_1467080(this);
}

class Unk_243d5f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101466e90
void Unk_243d5f0::vf5() {
    Unk_1467080(this);
}

class Unk_243d630 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101466ea0
void Unk_243d630::vf0() {
    Unk_1467080(this);
}
