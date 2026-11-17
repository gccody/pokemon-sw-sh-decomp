// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a83180(void* self);

class Unk_23c7000 {
public:
    virtual ~Unk_23c7000();
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

// 0x7100a83110
void Unk_23c7000::vf6() {
    Unk_a83180(this);
}

// 0x7100a830f0
void Unk_23c7000::vf9() {}

class Unk_23c7068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a83140
void Unk_23c7068::vf5() {
    Unk_a83180(this);
}

class Unk_23c70a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a83150
void Unk_23c70a8::vf0() {
    Unk_a83180(this);
}
