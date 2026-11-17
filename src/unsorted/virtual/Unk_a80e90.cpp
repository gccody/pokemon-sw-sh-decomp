// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_a80f20(void* self);

class Unk_23c6af0 {
public:
    virtual ~Unk_23c6af0();
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

// 0x7100a80eb0
void Unk_23c6af0::vf6() {
    Unk_a80f20(this);
}

// 0x7100a80e90
void Unk_23c6af0::vf9() {}

class Unk_23c6b58 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100a80ee0
void Unk_23c6b58::vf5() {
    Unk_a80f20(this);
}

class Unk_23c6b98 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100a80ef0
void Unk_23c6b98::vf0() {
    Unk_a80f20(this);
}
