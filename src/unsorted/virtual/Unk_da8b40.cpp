// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_da9070(void* self);
void Unk_dab2e0(void* self);

class Unk_23ef318 {
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

// 0x7100da8ec0
void Unk_23ef318::vf6() {
    Unk_da9070(this);
}

// 0x7100da8b40
u32 Unk_23ef318::vf7() {
    return 1;
}

// 0x7100da8b50
void Unk_23ef318::vf8() {}

// 0x7100da8df0
void Unk_23ef318::vf10() {}

class Unk_23ef380 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100da8f90
void Unk_23ef380::vf5() {
    Unk_da9070(this);
}

class Unk_23ef3c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100da8fa0
void Unk_23ef3c0::vf0() {
    Unk_da9070(this);
}

class Unk_23ef3e8 {
public:
    virtual ~Unk_23ef3e8();
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
};

// 0x7100dac4d0
void Unk_23ef3e8::vf11() {
    Unk_dab2e0(this);
}
