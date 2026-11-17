// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_799dd0(void* self);

class Unk_23a80b0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100792950
void Unk_23a80b0::vf2() {}

class Unk_23a80e0 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71007929d0
void Unk_23a80e0::vf0() {}

class Unk_23a8100 {
public:
    virtual ~Unk_23a8100();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x71007944a0, 0x71007944b0
Unk_23a8100::~Unk_23a8100() {}

class Unk_23a81a8 {
public:
    virtual ~Unk_23a81a8();
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

// 0x7100799410
u32 Unk_23a81a8::vf25() {
    return 1;
}

class Unk_23a8358 {
public:
    virtual ~Unk_23a8358();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100799d60
void Unk_23a8358::vf6() {
    Unk_799dd0(this);
}

class Unk_23a83a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100799d90
void Unk_23a83a0::vf5() {
    Unk_799dd0(this);
}

class Unk_23a83e0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100799da0
void Unk_23a83e0::vf0() {
    Unk_799dd0(this);
}
