// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239f8e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void* vf2();
};

// 0x710065dbb0
u32 Unk_239f8e8::vf0() {
    return 0xffffffff;
}

// 0x710065dbc0
void Unk_239f8e8::vf1() {}

// 0x710065dbd0
void* Unk_239f8e8::vf2() {
    return nullptr;
}

class Unk_236d0b8 {
public:
    virtual ~Unk_236d0b8();
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
    virtual void* vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
};

// 0x710065fb10
void* Unk_236d0b8::vf16() {
    return nullptr;
}

class Unk_23a08f0 {
public:
    virtual ~Unk_23a08f0();
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
};

// 0x71006791a0
void Unk_23a08f0::vf15() {}

class Unk_23a0a18 {
public:
    virtual ~Unk_23a0a18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100679cd0, 0x7100679c90
Unk_23a0a18::~Unk_23a0a18() {}

class Unk_23a0a50 {
public:
    virtual ~Unk_23a0a50();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100679ce0, 0x7100679cf0
Unk_23a0a50::~Unk_23a0a50() {}

class Unk_23a0a88 {
public:
    virtual ~Unk_23a0a88();
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
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
};

// 0x7100679d30, 0x7100679d40
Unk_23a0a88::~Unk_23a0a88() {}

class Unk_23a0be0 {
public:
    virtual ~Unk_23a0be0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
};

// 0x710067a0b0, 0x710067a0c0
Unk_23a0be0::~Unk_23a0be0() {}

class Unk_23a0c38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x710067a160
void Unk_23a0c38::vf1() {}

class Unk_23a0c80 {
public:
    virtual ~Unk_23a0c80();
};

// 0x710067a1c0, 0x710067a1d0
Unk_23a0c80::~Unk_23a0c80() {}
