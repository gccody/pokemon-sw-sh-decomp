// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d94ab0(void* self);

class Unk_23ee258 {
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

// 0x7100d94900
void Unk_23ee258::vf6() {
    Unk_d94ab0(this);
}

// 0x7100d943c0
u32 Unk_23ee258::vf7() {
    return 1;
}

// 0x7100d943d0
void Unk_23ee258::vf8() {}

// 0x7100d94830
void Unk_23ee258::vf10() {}

class Unk_23ee2c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d949d0
void Unk_23ee2c0::vf5() {
    Unk_d94ab0(this);
}

class Unk_23ee300 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d949e0
void Unk_23ee300::vf0() {
    Unk_d94ab0(this);
}
