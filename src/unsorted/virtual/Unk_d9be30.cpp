// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d9c840(void* self);

class Unk_23ee950 {
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

// 0x7100d9c590
void Unk_23ee950::vf6() {
    Unk_d9c840(this);
}

// 0x7100d9be30
u32 Unk_23ee950::vf7() {
    return 1;
}

class Unk_23ee9b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d9c6e0
void Unk_23ee9b8::vf5() {
    Unk_d9c840(this);
}

class Unk_23ee9f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d9c6f0
void Unk_23ee9f8::vf0() {
    Unk_d9c840(this);
}
