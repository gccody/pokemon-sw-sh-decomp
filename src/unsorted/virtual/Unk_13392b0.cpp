// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1339320(void* self);
void Unk_133cb80(void* self);

class Unk_2430e10 {
public:
    virtual ~Unk_2430e10();
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

// 0x71013392b0
void Unk_2430e10::vf6() {
    Unk_1339320(this);
}

class Unk_2430e78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x71013392e0
void Unk_2430e78::vf5() {
    Unk_1339320(this);
}

class Unk_2430eb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71013392f0
void Unk_2430eb8::vf0() {
    Unk_1339320(this);
}

class Unk_2430ee0 {
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

// 0x710133c950
void Unk_2430ee0::vf6() {
    Unk_133cb80(this);
}

class Unk_2430f78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710133ca60
void Unk_2430f78::vf5() {
    Unk_133cb80(this);
}

class Unk_2430fb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710133ca70
void Unk_2430fb8::vf0() {
    Unk_133cb80(this);
}
