// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_91cf70(void* self);

class Unk_23be4d0 {
public:
    virtual ~Unk_23be4d0();
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

// 0x710091cf00
void Unk_23be4d0::vf6() {
    Unk_91cf70(this);
}

class Unk_23be568 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710091cf30
void Unk_23be568::vf5() {
    Unk_91cf70(this);
}

class Unk_23be5a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710091cf40
void Unk_23be5a8::vf0() {
    Unk_91cf70(this);
}
