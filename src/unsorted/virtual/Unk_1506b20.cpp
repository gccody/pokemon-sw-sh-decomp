// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1507000(void* self);

class Unk_2446738 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7101506fd0
void Unk_2446738::vf6() {
    Unk_1507000(this);
}

// 0x7101506b20
u32 Unk_2446738::vf7() {
    return 1;
}

class Unk_24467a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101506fe0
void Unk_24467a0::vf5() {
    Unk_1507000(this);
}

class Unk_24467e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101506ff0
void Unk_24467e0::vf0() {
    Unk_1507000(this);
}
