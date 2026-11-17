// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f431c0(void* self);
void Unk_f43f30(void* self);
void Unk_f48700(void* self);

class Unk_23fd920 {
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

// 0x7100f43cc0
void Unk_23fd920::vf6() {
    Unk_f43f30(this);
}

// 0x7100f431b0
void Unk_23fd920::vf8() {
    Unk_f431c0(this);
}

// 0x7100f43410
void Unk_23fd920::vf10() {}

class Unk_23fd9b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f43df0
void Unk_23fd9b8::vf5() {
    Unk_f43f30(this);
}

class Unk_23fd9f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f43e00
void Unk_23fd9f8::vf0() {
    Unk_f43f30(this);
}

class Unk_23fda38 {
public:
    virtual ~Unk_23fda38();
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
};

// 0x7100f480e0
void Unk_23fda38::vf6() {
    Unk_f48700(this);
}

// 0x7100f47ab0
void Unk_23fda38::vf13() {}

class Unk_23fdba0 {
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

// 0x7100f47ac0
void Unk_23fdba0::vf0() {}

class Unk_23fdad8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f48110
void Unk_23fdad8::vf5() {
    Unk_f48700(this);
}

class Unk_23fdb18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f48120
void Unk_23fdb18::vf0() {
    Unk_f48700(this);
}
