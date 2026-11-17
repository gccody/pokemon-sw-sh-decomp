// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_11fd2e0(void* self);

class Unk_2422c78 {
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

// 0x71011fd070
void Unk_2422c78::vf6() {
    Unk_11fd2e0(this);
}

// 0x71011fcfc0
void Unk_2422c78::vf9() {}

class Unk_2422ce0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71011fd120
void Unk_2422ce0::vf5() {
    Unk_11fd2e0(this);
}

class Unk_2422d20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011fd130
void Unk_2422d20::vf0() {
    Unk_11fd2e0(this);
}
