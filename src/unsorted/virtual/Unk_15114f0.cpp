// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1513650(void* self);

class Unk_2447268 {
public:
    virtual ~Unk_2447268();
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

// 0x71015114f0
void Unk_2447268::vf22() {}

// 0x7101511800
u32 Unk_2447268::vf25() {
    return 1;
}

class Unk_24471b8 {
public:
    virtual ~Unk_24471b8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101511c20
void Unk_24471b8::vf6() {
    Unk_1513650(this);
}

class Unk_2447200 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101511c50
void Unk_2447200::vf5() {
    Unk_1513650(this);
}

class Unk_2447240 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101511c60
void Unk_2447240::vf0() {
    Unk_1513650(this);
}
