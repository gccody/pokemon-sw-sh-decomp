// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_e6a0f0(void* self);
void Unk_14e0b90(void* self);

class Unk_23f3030 {
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

// 0x7100e69f40
void Unk_23f3030::vf6() {
    Unk_e6a0f0(this);
}

class Unk_23f30c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e6a010
void Unk_23f30c8::vf5() {
    Unk_e6a0f0(this);
}

class Unk_23f3108 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e6a020
void Unk_23f3108::vf0() {
    Unk_e6a0f0(this);
}

class Unk_23f3330 {
public:
    virtual ~Unk_23f3330();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100e6b0c0
void Unk_23f3330::vf9() {}

class Unk_23f3400 {
public:
    virtual ~Unk_23f3400();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100e6b4e0
void Unk_23f3400::vf9() {}

class Unk_23f31e8 {
public:
    virtual ~Unk_23f31e8();
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
    virtual void vf25();
};

// 0x7100e6bc10
void Unk_23f31e8::vf22() {}

class Unk_23f3138 {
public:
    virtual ~Unk_23f3138();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100e6cb00
void Unk_23f3138::vf6() {
    Unk_14e0b90(this);
}

class Unk_23f3180 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100e6cb30
void Unk_23f3180::vf5() {
    Unk_14e0b90(this);
}

class Unk_23f31c0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100e6cb40
void Unk_23f31c0::vf0() {
    Unk_14e0b90(this);
}

class Unk_23f34d0 {
public:
    virtual ~Unk_23f34d0();
};

// 0x7100e6cb70, 0x7100e6cb80
Unk_23f34d0::~Unk_23f34d0() {}
