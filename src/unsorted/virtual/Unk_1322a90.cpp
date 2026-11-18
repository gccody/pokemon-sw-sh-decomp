// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1323280(void* self);

class Unk_242ffd0 {
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

// 0x7101322e50
void Unk_242ffd0::vf6() {
    Unk_1323280(this);
}

// 0x7101322a90
void Unk_242ffd0::vf9() {}

class Unk_2430038 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101323060
void Unk_2430038::vf5() {
    Unk_1323280(this);
}

class Unk_2430078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101323070
void Unk_2430078::vf0() {
    Unk_1323280(this);
}
