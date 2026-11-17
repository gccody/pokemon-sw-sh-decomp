// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_96c590(void* self);
void Unk_cea850(void* self);
void Unk_cff640(void* self);
void Unk_d03c40(void* self);
void Unk_d100d0(void* self);
void Unk_d349d0(void* self);
void Unk_d3bca0(void* self);
void Unk_d51de0(void* self);
void Unk_d5f290(void* self);
void Unk_13b1c90(void* self);
void Unk_13ed330(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_c64ad0(u64, u32, u32);

class Unk_23dd630 {
public:
    virtual ~Unk_23dd630();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual bool vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    u8 _8[0x17c];
    s32 field_184;
};
PKMN_OFFSET_ASSERT(Unk_23dd630, field_184, 0x184);

// 0x7100c7bec0
bool Unk_23dd630::vf8() {
    return field_184 > 3;
}

// 0x7100c79ed0
void Unk_23dd630::vf11() {}

// 0x7100c7a030
void Unk_23dd630::vf13() {}

struct Unk_23dd760_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23dd760_18, field_170, 0x170);

class Unk_23dd760 {
public:
    virtual ~Unk_23dd760();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23dd760_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23dd760, field_18, 0x18);

// 0x7100c7e8c0
bool Unk_23dd760::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}

struct Unk_23dd790_18 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_23dd790_18, field_170, 0x170);

class Unk_23dd790 {
public:
    virtual ~Unk_23dd790();
    virtual bool vf2();
    virtual void vf3();
    u8 _8[0x10];
    Unk_23dd790_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_23dd790, field_18, 0x18);

// 0x7100c7f630
bool Unk_23dd790::vf2() {
    if (field_18 == nullptr) {
        return false;
    }
    return field_18->field_170 != 0;
}

class Unk_23dd820 {
public:
    virtual ~Unk_23dd820();
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
    virtual u8 vf14();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual u32 vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    u8 _8[0x4c0];
    u8 field_4c8;
};
PKMN_OFFSET_ASSERT(Unk_23dd820, field_4c8, 0x4c8);

// 0x7100c836d0
void Unk_23dd820::vf6() {
    Unk_13b1c90(this);
}

// 0x7100c836e0
u8 Unk_23dd820::vf14() {
    return field_4c8;
}

// 0x7100c836f0
u32 Unk_23dd820::vf69() {
    return 0;
}

// 0x7100c83700
void Unk_23dd820::vf70() {}

// 0x7100c83710
void Unk_23dd820::vf71() {}

// 0x7100c83720
void Unk_23dd820::vf72() {}

class Unk_23dda80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c83750
void Unk_23dda80::vf5() {
    Unk_13b1c90(this);
}

class Unk_23ddac0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c83760
void Unk_23ddac0::vf0() {
    Unk_13b1c90(this);
}

class Unk_23ddae8 {
public:
    virtual ~Unk_23ddae8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c839b0
void Unk_23ddae8::vf4() {}

class Unk_23ddb30 {
public:
    virtual ~Unk_23ddb30();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100c83df0
void Unk_23ddb30::vf4() {}

class Unk_23ddd68 {
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100c85b50
void Unk_23ddd68::vf6() {
    Unk_96c590(this);
}

class Unk_23ddfa8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c85c00
void Unk_23ddfa8::vf5() {
    Unk_96c590(this);
}

class Unk_23ddfe8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c85c10
void Unk_23ddfe8::vf0() {
    Unk_96c590(this);
}

class Unk_23de060 {
public:
    virtual ~Unk_23de060();
    virtual void vf2();
    virtual void vf3();
    virtual u8 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x138];
    u8 field_140;
};
PKMN_OFFSET_ASSERT(Unk_23de060, field_140, 0x140);

// 0x7100c87440
u8 Unk_23de060::vf4() {
    return field_140;
}

// 0x7100c87450
void Unk_23de060::vf5() {
    field_140 = 1;
}

class Unk_23de0b0 {
public:
    virtual ~Unk_23de0b0();
    virtual void vf2();
    virtual void vf3();
    virtual u8 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x138];
    u8 field_140;
};
PKMN_OFFSET_ASSERT(Unk_23de0b0, field_140, 0x140);

// 0x7100c87e80
u8 Unk_23de0b0::vf4() {
    return field_140;
}

// 0x7100c87e90
void Unk_23de0b0::vf5() {
    field_140 = 1;
}

class Unk_23de100 {
public:
    virtual ~Unk_23de100();
    virtual void vf2();
    virtual void vf3();
    virtual u8 vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x138];
    u8 field_140;
};
PKMN_OFFSET_ASSERT(Unk_23de100, field_140, 0x140);

// 0x7100c88810
u8 Unk_23de100::vf4() {
    return field_140;
}

// 0x7100c88820
void Unk_23de100::vf5() {
    field_140 = 1;
}

class Unk_23de358 {
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100c8a1e0
void Unk_23de358::vf6() {
    Unk_cea850(this);
}

class Unk_23de598 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c8a290
void Unk_23de598::vf5() {
    Unk_cea850(this);
}

class Unk_23de5d8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c8a2a0
void Unk_23de5d8::vf0() {
    Unk_cea850(this);
}

class Unk_23de600 {
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
    virtual void vf37(u32 value);
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    u8 _8[0x5c8];
    u64 field_5d0;
    u8 _5d8[0x8];
    u32 field_5e0;
};
PKMN_OFFSET_ASSERT(Unk_23de600, field_5d0, 0x5d0);
PKMN_OFFSET_ASSERT(Unk_23de600, field_5e0, 0x5e0);

// 0x7100c8ac90
void Unk_23de600::vf6() {
    Unk_cff640(this);
}

// 0x7100c8ab50
void Unk_23de600::vf37(u32 value) {
    field_5e0 = value;
    if (field_5d0 != 0) {
        Unk_c64ad0(field_5d0, value, 1);
    }
}

class Unk_23de838 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c8ae60
void Unk_23de838::vf5() {
    Unk_cff640(this);
}

class Unk_23de878 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c8ae70
void Unk_23de878::vf0() {
    Unk_cff640(this);
}

class Unk_23dec90 {
public:
    virtual ~Unk_23dec90();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual u32 vf47();
};

// 0x7100c8c610
u32 Unk_23dec90::vf47() {
    return 0;
}

class Unk_23dee88 {
public:
    virtual ~Unk_23dee88();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100c8d290
void Unk_23dee88::vf6() {
    Unk_d03c40(this);
}

class Unk_23df0c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c8d2c0
void Unk_23df0c8::vf5() {
    Unk_d03c40(this);
}

class Unk_23df108 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c8d2d0
void Unk_23df108::vf0() {
    Unk_d03c40(this);
}

class Unk_23df130 {
public:
    virtual ~Unk_23df130();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
};

// 0x7100c8e930
void Unk_23df130::vf6() {
    Unk_d100d0(this);
}

class Unk_23df368 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c8e960
void Unk_23df368::vf5() {
    Unk_d100d0(this);
}

class Unk_23df3a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c8e970
void Unk_23df3a8::vf0() {
    Unk_d100d0(this);
}

class Unk_23df690 {
public:
    virtual ~Unk_23df690();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
};

// 0x7100c903b0
void Unk_23df690::vf6() {
    Unk_d349d0(this);
}

class Unk_23df8c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c903e0
void Unk_23df8c8::vf5() {
    Unk_d349d0(this);
}

class Unk_23df908 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c903f0
void Unk_23df908::vf0() {
    Unk_d349d0(this);
}

class Unk_23df930 {
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
};

// 0x7100c90b60
void Unk_23df930::vf6() {
    Unk_13ed330(this);
}

class Unk_23dfad0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c90c90
void Unk_23dfad0::vf5() {
    Unk_13ed330(this);
}

class Unk_23dfb10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c90ca0
void Unk_23dfb10::vf0() {
    Unk_13ed330(this);
}

class Unk_23dfb38 {
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100c91620
void Unk_23dfb38::vf6() {
    Unk_d3bca0(this);
}

class Unk_23dfd78 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c916d0
void Unk_23dfd78::vf5() {
    Unk_d3bca0(this);
}

class Unk_23dfdb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c916e0
void Unk_23dfdb8::vf0() {
    Unk_d3bca0(this);
}

class Unk_23dffd8 {
public:
    virtual ~Unk_23dffd8();
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
};

// 0x7100c92870
void Unk_23dffd8::vf6() {
    Unk_d51de0(this);
}

class Unk_23e0210 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c928a0
void Unk_23e0210::vf5() {
    Unk_d51de0(this);
}

class Unk_23e0250 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c928b0
void Unk_23e0250::vf0() {
    Unk_d51de0(this);
}

class Unk_23e0468 {
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
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
};

// 0x7100c945d0
void Unk_23e0468::vf6() {
    Unk_d5f290(this);
}

class Unk_23e06a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100c946c0
void Unk_23e06a8::vf5() {
    Unk_d5f290(this);
}

class Unk_23e06e8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100c946d0
void Unk_23e06e8::vf0() {
    Unk_d5f290(this);
}
