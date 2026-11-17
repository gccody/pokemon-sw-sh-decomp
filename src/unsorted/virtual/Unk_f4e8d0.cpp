// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f4ef40(void* self);

class Unk_23fe270 {
public:
    virtual ~Unk_23fe270();
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

// 0x7100f4eed0
void Unk_23fe270::vf6() {
    Unk_f4ef40(this);
}

// 0x7100f4e8d0
void Unk_23fe270::vf10() {}

class Unk_23fe308 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f4ef00
void Unk_23fe308::vf5() {
    Unk_f4ef40(this);
}

class Unk_23fe348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f4ef10
void Unk_23fe348::vf0() {
    Unk_f4ef40(this);
}
