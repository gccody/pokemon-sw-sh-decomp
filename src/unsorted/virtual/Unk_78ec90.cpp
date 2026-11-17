// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_790010(void* self);
void Unk_790e60(void* self);

class Unk_23a7d80 {
public:
    virtual ~Unk_23a7d80();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710078ec90, 0x710078eca0
Unk_23a7d80::~Unk_23a7d80() {}

class Unk_23a7e78 {
public:
    virtual ~Unk_23a7e78();
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
    virtual u32 vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual u32 vf25();
};

// 0x710078f500
u32 Unk_23a7e78::vf20() {
    return 1;
}

// 0x710078f510
void Unk_23a7e78::vf21() {}

// 0x710078f520
void Unk_23a7e78::vf22() {}

// 0x710078f610
u32 Unk_23a7e78::vf25() {
    return 1;
}

class Unk_23a7dc8 {
public:
    virtual ~Unk_23a7dc8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710078fa30
void Unk_23a7dc8::vf6() {
    Unk_790010(this);
}

class Unk_23a7e10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710078fa60
void Unk_23a7e10::vf5() {
    Unk_790010(this);
}

class Unk_23a7e50 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710078fa70
void Unk_23a7e50::vf0() {
    Unk_790010(this);
}

class Unk_23a7fe0 {
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
    virtual u32 vf10();
};

// 0x7100790cb0
void Unk_23a7fe0::vf6() {
    Unk_790e60(this);
}

// 0x7100790be0
void Unk_23a7fe0::vf9() {}

class Unk_23a8048 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100790d80
void Unk_23a8048::vf5() {
    Unk_790e60(this);
}

class Unk_23a8088 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100790d90
void Unk_23a8088::vf0() {
    Unk_790e60(this);
}
