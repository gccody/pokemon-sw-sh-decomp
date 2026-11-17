// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1253eb0(void* self);

class Unk_2426e88 {
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

// 0x7101253d00
void Unk_2426e88::vf6() {
    Unk_1253eb0(this);
}

// 0x71012538b0
u32 Unk_2426e88::vf7() {
    return 1;
}

class Unk_2426ef0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101253dd0
void Unk_2426ef0::vf5() {
    Unk_1253eb0(this);
}

class Unk_2426f30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101253de0
void Unk_2426f30::vf0() {
    Unk_1253eb0(this);
}

class Unk_2426f98 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101254740
u32 Unk_2426f98::vf0() {
    return 1;
}
