// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_ba5440(void* self);
void Unk_bb4d40(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6d7ac0(u64, u64, u32);

class Unk_23d3130 {
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
};

// 0x7100ba7a20
void Unk_23d3130::vf6() {
    Unk_ba5440(this);
}

// 0x7100ba7a30
void Unk_23d3130::vf17() {}

// 0x7100ba7a40
void Unk_23d3130::vf18() {}

class Unk_23d31d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100ba7b30
void Unk_23d31d8::vf5() {
    Unk_ba5440(this);
}

class Unk_23d3218 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100ba7b40
void Unk_23d3218::vf0() {
    Unk_ba5440(this);
}

class Unk_23d3240 {
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
    virtual u32 vf16();
    virtual void vf17();
    virtual void vf18();
};

// 0x7100bab600
u32 Unk_23d3240::vf16() {
    return 0;
}

class Unk_23d3368 {
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
    virtual u32 vf16();
    virtual void vf17();
    virtual void vf18();
};

// 0x7100bad500
void Unk_23d3368::vf10() {}

// 0x7100bad6f0
u32 Unk_23d3368::vf16() {
    return 0;
}

class Unk_23d3490 {
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
    u8 _8[0xe0];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_23d3490, field_e8, 0xe8);

// 0x7100bb11a0
u32 Unk_23d3490::vf10() {
    return field_e8;
}

struct Unk_23d3560_1d0 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23d3560_1d0, field_2a0, 0x2a0);

class Unk_23d3560 {
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
    virtual void vf15(u64 /*unused*/, u64 arg2);
    virtual void vf16();
    virtual void vf17();
    u8 _8[0x1a8];
    u32 field_1b0;
    u8 _1b4[0x16];
    u8 field_1ca;
    u8 field_1cb;
    u8 _1cc[0x4];
    Unk_23d3560_1d0* field_1d0;
};
PKMN_OFFSET_ASSERT(Unk_23d3560, field_1b0, 0x1b0);
PKMN_OFFSET_ASSERT(Unk_23d3560, field_1ca, 0x1ca);
PKMN_OFFSET_ASSERT(Unk_23d3560, field_1cb, 0x1cb);
PKMN_OFFSET_ASSERT(Unk_23d3560, field_1d0, 0x1d0);

// 0x7100bb4070
void Unk_23d3560::vf11() {
    field_1b0 = field_1b0 == 0xc ? 6 : (field_1b0 == 0x17 ? 0x1a : 0x18);
    field_1ca = 0;
}

// 0x7100bb40d0
void Unk_23d3560::vf12() {
    field_1b0 = 0x1a;
    field_1ca = 0;
}

// 0x7100bb40f0
void Unk_23d3560::vf13() {}

// 0x7100bb4110
void Unk_23d3560::vf14() {
    field_1cb = 1;
}

// 0x7100bb4130
void Unk_23d3560::vf15(u64 /*unused*/, u64 arg2) {
    if (field_1d0 != nullptr) {
        Unk_6d7ac0(field_1d0->field_2a0, arg2, 1);
    }
}

class Unk_23d3668 {
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
    u8 _8[0x18];
    u32 field_20;
    u8 _24[0x16];
    u8 field_3a;
};
PKMN_OFFSET_ASSERT(Unk_23d3668, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_23d3668, field_3a, 0x3a);

// 0x7100bb40a0
void Unk_23d3668::vf4() {
    field_20 = field_20 == 0xc ? 6 : (field_20 == 0x17 ? 0x1a : 0x18);
    field_3a = 0;
}

// 0x7100bb40e0
void Unk_23d3668::vf5() {
    field_20 = 0x1a;
    field_3a = 0;
}

class Unk_23d36c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x2b];
    u8 field_33;
};
PKMN_OFFSET_ASSERT(Unk_23d36c8, field_33, 0x33);

// 0x7100bb4100
void Unk_23d36c8::vf0() {}

// 0x7100bb4120
void Unk_23d36c8::vf1() {
    field_33 = 1;
}

// 0x7100bb4ce0
void Unk_23d36c8::vf2() {}

// 0x7100bb4cf0
void Unk_23d36c8::vf3() {}

// 0x7100bb4d00
void Unk_23d36c8::vf4() {}

// 0x7100bb4d10
void Unk_23d36c8::vf5() {}

// 0x7100bb4d20
void Unk_23d36c8::vf6() {}

// 0x7100bb4d30
void Unk_23d36c8::vf7() {}

struct Unk_23d3718_30 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23d3718_30, field_2a0, 0x2a0);

class Unk_23d3718 {
public:
    virtual void vf0(u64 /*unused*/, u64 arg2);
    virtual void vf1();
    u8 _8[0x28];
    Unk_23d3718_30* field_30;
};
PKMN_OFFSET_ASSERT(Unk_23d3718, field_30, 0x30);

// 0x7100bb4150
void Unk_23d3718::vf0(u64 /*unused*/, u64 arg2) {
    if (field_30 != nullptr) {
        Unk_6d7ac0(field_30->field_2a0, arg2, 1);
    }
}

class Unk_23d3e88 {
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
};

// 0x7100bb46f0
void Unk_23d3e88::vf6() {
    Unk_bb4d40(this);
}

class Unk_23d3600 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100bb48e0
void Unk_23d3600::vf5() {
    Unk_bb4d40(this);
}

class Unk_23d3640 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100bb48f0
void Unk_23d3640::vf0() {
    Unk_bb4d40(this);
}

class Unk_23d3b40 {
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
};

// 0x7100bb7b40
void Unk_23d3b40::vf8() {}
