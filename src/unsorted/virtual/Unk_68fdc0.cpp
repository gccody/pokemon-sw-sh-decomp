// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_690130(void* self);
void Unk_690e40(void* self);

class Unk_23a1af8 {
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
};

// 0x710068fdc0
void Unk_23a1af8::vf6() {
    Unk_690130(this);
}

class Unk_23a1b80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710068feb0
void Unk_23a1b80::vf5() {
    Unk_690130(this);
}

class Unk_23a1bc0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710068fec0
void Unk_23a1bc0::vf0() {
    Unk_690130(this);
}

class Unk_23a1be8 {
public:
    virtual ~Unk_23a1be8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x71006900c0
void Unk_23a1be8::vf6() {
    Unk_690e40(this);
}

class Unk_23a1c30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71006900f0
void Unk_23a1c30::vf5() {
    Unk_690e40(this);
}

class Unk_23a1c70 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100690100
void Unk_23a1c70::vf0() {
    Unk_690e40(this);
}

class Unk_23a1f18 {
public:
    virtual ~Unk_23a1f18();
};

// 0x7100694160, 0x7100696610
Unk_23a1f18::~Unk_23a1f18() {}

class Unk_23a1ee8 {
public:
    virtual ~Unk_23a1ee8();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100696600, 0x71006965c0
Unk_23a1ee8::~Unk_23a1ee8() {}

class Unk_23a20c8 {
public:
    virtual ~Unk_23a20c8();
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

// 0x710069a2a0
void Unk_23a20c8::vf15() {}
