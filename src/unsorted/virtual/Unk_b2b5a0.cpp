// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_b2b8c0(void* self);

class Unk_23ce710 {
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

// 0x7100b2b890
void Unk_23ce710::vf6() {
    Unk_b2b8c0(this);
}

// 0x7100b2b5a0
u32 Unk_23ce710::vf7() {
    return 1;
}

// 0x7100b2b5b0
void Unk_23ce710::vf8() {}

// 0x7100b2b5c0
void Unk_23ce710::vf10() {}

class Unk_23ce778 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100b2b8a0
void Unk_23ce778::vf5() {
    Unk_b2b8c0(this);
}

class Unk_23ce7b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100b2b8b0
void Unk_23ce7b8::vf0() {
    Unk_b2b8c0(this);
}
