// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1146270(void* self);

class Unk_241a068 {
public:
    virtual ~Unk_241a068();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x71011452f0
void Unk_241a068::vf6() {
    Unk_1146270(this);
}

// 0x7101142ce0
void Unk_241a068::vf7() {}

class Unk_241a128 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101142cf0
void Unk_241a128::vf0() {}

class Unk_241a0c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101145320
void Unk_241a0c0::vf5() {
    Unk_1146270(this);
}

class Unk_241a100 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101145330
void Unk_241a100::vf0() {
    Unk_1146270(this);
}
