// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f3af70(void* self);

class Unk_23fd448 {
public:
    virtual ~Unk_23fd448();
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

// 0x7100f3af00
void Unk_23fd448::vf6() {
    Unk_f3af70(this);
}

// 0x7100f3abd0
void Unk_23fd448::vf9() {}

class Unk_23fd4b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f3af30
void Unk_23fd4b0::vf5() {
    Unk_f3af70(this);
}

class Unk_23fd4f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f3af40
void Unk_23fd4f0::vf0() {
    Unk_f3af70(this);
}
