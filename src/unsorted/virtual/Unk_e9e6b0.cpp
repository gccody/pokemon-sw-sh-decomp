// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_e9dc10(u64);
void Unk_ea01d0(void*, u64);

class Unk_23f5078 {
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
    u8 _8[0x298];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23f5078, field_2a0, 0x2a0);

// 0x7100e9e6b0
void Unk_23f5078::vf8() {
    Unk_e9dc10(field_2a0);
}

class Unk_23f51f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100e9fd70
void Unk_23f51f0::vf1() {}

class Unk_23f5228 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x7100e9fd80
void Unk_23f5228::vf0() {}

// 0x7100e9fd90
void Unk_23f5228::vf1() {}

class Unk_23f5258 {
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
    u8 _8[0x298];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23f5258, field_2a0, 0x2a0);

// 0x7100e9ff60
void Unk_23f5258::vf8() {
    Unk_ea01d0(this, field_2a0);
}

class Unk_23d99a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual u32 vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
};

// 0x7100ea0970
u32 Unk_23d99a8::vf7() {
    return 1;
}

// 0x7100ea09a0
u32 Unk_23d99a8::vf11() {
    return 1;
}

class Unk_23aa1b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual u32 vf17();
    virtual void vf18();
};

// 0x7100ea0990
void Unk_23aa1b8::vf15() {}

// 0x7100ea09b0
void Unk_23aa1b8::vf16() {}

// 0x7100ea09c0
void Unk_23aa1b8::vf18() {}
