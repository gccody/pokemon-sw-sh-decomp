// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_2418708 {
public:
    virtual ~Unk_2418708();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual u8 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual u32 vf12();
    virtual u32 vf13(u32 value);
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    u8 _8[0x269];
    u8 field_271;
};
PKMN_OFFSET_ASSERT(Unk_2418708, field_271, 0x271);

// 0x7101104c80
void Unk_2418708::vf5() {
    field_271 = 1;
}

// 0x7101104d70
void Unk_2418708::vf7() {
    field_271 = 0;
}

// 0x7101104c90
u8 Unk_2418708::vf8() {
    return field_271;
}

// 0x71011050f0
u32 Unk_2418708::vf12() {
    return 3;
}

// 0x7101105100
u32 Unk_2418708::vf13(u32 value) {
    return value;
}

class Unk_2418848 {
public:
    virtual ~Unk_2418848();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5() = 0;
    virtual void vf6();
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void vf10() = 0;
    virtual void vf11() = 0;
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
};

// 0x7101105910
void Unk_2418848::vf6() {}

class Unk_2418910 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7101105cf0
void Unk_2418910::vf2() {}

class Unk_2418940 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101105d70
void Unk_2418940::vf0() {}
