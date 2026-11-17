// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_239b1a8 {
public:
    virtual ~Unk_239b1a8();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005f9d30
void Unk_239b1a8::vf2() {}

class Unk_239b1d8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005f9d40
void Unk_239b1d8::vf0() {}

class Unk_239b548 {
public:
    virtual ~Unk_239b548();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005fd510
void Unk_239b548::vf2() {}

class Unk_239b578 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71005fd590
void Unk_239b578::vf0() {}

class Unk_239b720 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71005fe3a0
void Unk_239b720::vf1() {}

class Unk_239b758 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71005fe3b0
void Unk_239b758::vf0() {}

// 0x71005fe3c0
void Unk_239b758::vf1() {}

class Unk_239bb58 {
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

// 0x71006014f0
void Unk_239bb58::vf7() {}

// 0x71005ff390
void Unk_239bb58::vf9() {}

// 0x71005ff3a0
void Unk_239bb58::vf10() {}

class Unk_239a1f8 {
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
};

// 0x71006036e0
void Unk_239a1f8::vf15() {}

class Unk_239c100 {
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
};

// 0x7100609a40
void Unk_239c100::vf17() {}

class Unk_239c7a8 {
public:
    virtual ~Unk_239c7a8();
    virtual void vf2();
};

// 0x7100612340, 0x7100612350
Unk_239c7a8::~Unk_239c7a8() {}

class Unk_239cc00 {
public:
    virtual ~Unk_239cc00();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x7100619a80
u32 Unk_239cc00::vf4() {
    return 1;
}

class Unk_239cc70 {
public:
    virtual ~Unk_239cc70();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710061b1f0
u32 Unk_239cc70::vf3() {
    return 1;
}

class Unk_239cd48 {
public:
    virtual ~Unk_239cd48();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710061d200
u32 Unk_239cd48::vf4() {
    return 5;
}
