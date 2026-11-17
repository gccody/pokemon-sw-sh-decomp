// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1034d10(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_104bf60(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba150;

class Unk_24096c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71010314f0
void Unk_24096c8::vf4() {
    Unk_104bf60(Unk_24ba150);
}

// 0x7101031510
void Unk_24096c8::vf5() {}

class Unk_2409710 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7101031ab0
void Unk_2409710::vf1() {}

// 0x7101031ac0
void Unk_2409710::vf2() {}

// 0x7101031ad0
void Unk_2409710::vf3() {}

// 0x7101031500
void Unk_2409710::vf4() {
    Unk_104bf60(Unk_24ba150);
}

// 0x7101031520
void Unk_2409710::vf5() {}

// 0x7101031ae0
void Unk_2409710::vf6() {}

// 0x7101031af0
void Unk_2409710::vf7() {}

class Unk_2409c28 {
public:
    virtual ~Unk_2409c28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x7101034c90
void Unk_2409c28::vf5() {
    Unk_1034d10(this);
}

class Unk_2409c80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101034ca0
void Unk_2409c80::vf0() {
    Unk_1034d10(this);
}
