// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e6e460(void* self);

class Unk_23f3570 {
public:
    virtual ~Unk_23f3570();
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

// 0x7100e6e3f0
void Unk_23f3570::vf6() {
    Unk_e6e460(this);
}

class Unk_23f3608 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e6e420
void Unk_23f3608::vf5() {
    Unk_e6e460(this);
}

class Unk_23f3648 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e6e430
void Unk_23f3648::vf0() {
    Unk_e6e460(this);
}

class Unk_23f3670 {
public:
    virtual ~Unk_23f3670();
};

// 0x7100e6f320, 0x7100e6f330
Unk_23f3670::~Unk_23f3670() {}
