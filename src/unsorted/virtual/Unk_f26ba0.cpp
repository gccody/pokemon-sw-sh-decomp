// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f26c30(void* self);
void Unk_f2a590(void* self);

class Unk_23fbe78 {
public:
    virtual ~Unk_23fbe78();
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

// 0x7100f26bc0
void Unk_23fbe78::vf6() {
    Unk_f26c30(this);
}

// 0x7100f26ba0
void Unk_23fbe78::vf10() {}

class Unk_23fbf10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f26bf0
void Unk_23fbf10::vf5() {
    Unk_f26c30(this);
}

class Unk_23fbf50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f26c00
void Unk_23fbf50::vf0() {
    Unk_f26c30(this);
}

class Unk_23fc690 {
public:
    virtual ~Unk_23fc690();
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

// 0x7100f2a060
void Unk_23fc690::vf6() {
    Unk_f2a590(this);
}

class Unk_23fc728 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f2a090
void Unk_23fc728::vf5() {
    Unk_f2a590(this);
}

class Unk_23fc768 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f2a0a0
void Unk_23fc768::vf0() {
    Unk_f2a590(this);
}
