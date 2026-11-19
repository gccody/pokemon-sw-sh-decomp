// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_113d9c0(void* self);

class Unk_241c508 {
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
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
};

// 0x71011777b0
void Unk_241c508::vf6() {
    Unk_113d9c0(this);
}

class Unk_241c5d8 {
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
};

// 0x71011779e0
void Unk_241c5d8::vf5() {
    Unk_113d9c0(this);
}

class Unk_241c648 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x71011779f0
void Unk_241c648::vf0() {
    Unk_113d9c0(this);
}

class Unk_241c888 {
public:
    virtual ~Unk_241c888();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101179bc0
void Unk_241c888::vf4() {}

// 0x7101179bd0
void Unk_241c888::vf5() {
    ::operator delete(this);
}
