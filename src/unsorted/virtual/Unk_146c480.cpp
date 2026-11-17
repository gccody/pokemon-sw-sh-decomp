// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_146c7b0(void* self);

class Unk_243d7a0 {
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
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x710146c480
void Unk_243d7a0::vf6() {
    Unk_146c7b0(this);
}

class Unk_243d838 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710146c610
void Unk_243d838::vf5() {
    Unk_146c7b0(this);
}

class Unk_243d878 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710146c620
void Unk_243d878::vf0() {
    Unk_146c7b0(this);
}
