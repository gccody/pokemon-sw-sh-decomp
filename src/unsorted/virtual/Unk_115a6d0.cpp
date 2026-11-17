// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_115e980(void* self);

class Unk_241b228 {
public:
    virtual ~Unk_241b228();
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
};

// 0x710115e910
void Unk_241b228::vf6() {
    Unk_115e980(this);
}

// 0x710115a6d0
void Unk_241b228::vf11() {}

class Unk_241b2d8 {
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

// 0x710115e940
void Unk_241b2d8::vf5() {
    Unk_115e980(this);
}

class Unk_241b348 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710115e950
void Unk_241b348::vf0() {
    Unk_115e980(this);
}
