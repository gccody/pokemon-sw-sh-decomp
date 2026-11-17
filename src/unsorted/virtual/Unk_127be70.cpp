// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_127bf00(void* self);

class Unk_2429798 {
public:
    virtual ~Unk_2429798();
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

// 0x710127be90
void Unk_2429798::vf6() {
    Unk_127bf00(this);
}

// 0x710127be70
void Unk_2429798::vf9() {}

class Unk_2429800 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710127bec0
void Unk_2429800::vf5() {
    Unk_127bf00(this);
}

class Unk_2429840 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710127bed0
void Unk_2429840::vf0() {
    Unk_127bf00(this);
}
