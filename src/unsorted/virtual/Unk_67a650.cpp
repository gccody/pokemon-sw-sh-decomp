// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_67d770(void* self);

class Unk_23a0cc8 {
public:
    virtual ~Unk_23a0cc8();
};

// 0x710067a650, 0x710067a660
Unk_23a0cc8::~Unk_23a0cc8() {}

class Unk_23a0ce8 {
public:
    virtual ~Unk_23a0ce8();
};

// 0x710067abb0, 0x710067abc0
Unk_23a0ce8::~Unk_23a0ce8() {}

class Unk_23a0d08 {
public:
    virtual ~Unk_23a0d08();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual u32 vf9();
    virtual void vf10();
    virtual void vf11();
};

// 0x710067b740
u32 Unk_23a0d08::vf9() {
    return 1;
}

// 0x710067b760
void Unk_23a0d08::vf10() {}

class Unk_23a0d78 {
public:
    virtual ~Unk_23a0d78();
    virtual void vf2();
    virtual u32 vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x710067b750
u32 Unk_23a0d78::vf3() {
    return 1;
}

class Unk_23a0980 {
public:
    virtual ~Unk_23a0980();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x710067b770
void Unk_23a0980::vf4() {}

class Unk_23a0f38 {
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
    virtual u32 vf13();
    virtual u32 vf14();
    virtual u32 vf15();
    virtual void vf16();
    virtual u32 vf17();
};

// 0x710067d900
void Unk_23a0f38::vf8() {
    Unk_67d770(this);
}

// 0x710067ebe0
void Unk_23a0f38::vf11() {}

// 0x710067ebf0
void Unk_23a0f38::vf12() {}

// 0x710067ec00
u32 Unk_23a0f38::vf13() {
    return 0;
}

// 0x710067ec10
u32 Unk_23a0f38::vf14() {
    return 1;
}

// 0x710067ec20
u32 Unk_23a0f38::vf15() {
    return 0;
}

// 0x710067ec30
void Unk_23a0f38::vf16() {}

// 0x710067ec40
u32 Unk_23a0f38::vf17() {
    return 0;
}

class Unk_23a10b8 {
public:
    virtual ~Unk_23a10b8();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100681630
void Unk_23a10b8::vf2() {}

class Unk_23a10e8 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x71006816b0
void Unk_23a10e8::vf0() {}
