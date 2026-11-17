// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a8a2d0(void* self);

class Unk_23c7a90 {
public:
    virtual ~Unk_23c7a90();
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

// 0x7100a8a260
void Unk_23c7a90::vf6() {
    Unk_a8a2d0(this);
}

// 0x7100a8a240
void Unk_23c7a90::vf9() {}

class Unk_23c7af8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a8a290
void Unk_23c7af8::vf5() {
    Unk_a8a2d0(this);
}

class Unk_23c7b38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a8a2a0
void Unk_23c7b38::vf0() {
    Unk_a8a2d0(this);
}
