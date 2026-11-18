// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_12470e0(void* self);

class Unk_2426638 {
public:
    virtual ~Unk_2426638();
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x7101246860
void Unk_2426638::vf22() {}

// 0x7101246b10
u32 Unk_2426638::vf25() {
    return 1;
}

class Unk_2426780 {
public:
    virtual ~Unk_2426780();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101247070
void Unk_2426780::vf6() {
    Unk_12470e0(this);
}

class Unk_24267c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71012470a0
void Unk_24267c8::vf5() {
    Unk_12470e0(this);
}

class Unk_2426808 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71012470b0
void Unk_2426808::vf0() {
    Unk_12470e0(this);
}
