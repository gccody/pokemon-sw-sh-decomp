// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_dc8b00(void* self);
void Unk_dc8d90(void* self);
void Unk_dce9d0(void* self);
void Unk_dcf2b0(void* self);
void Unk_dcf560(void* self);
void Unk_dd2a30(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_dcb520(u64);
void Unk_dcb680(u64);
void Unk_dd48f0(void*);
void Unk_14ac3c0(u64, u32);

class Unk_23efd38 {
public:
    virtual ~Unk_23efd38();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100dc8a90
void Unk_23efd38::vf6() {
    Unk_dc8b00(this);
}

// 0x7100dc7ff0
u32 Unk_23efd38::vf7() {
    return 1;
}

// 0x7100dc8000
void Unk_23efd38::vf8() {}

// 0x7100dc8a70
void Unk_23efd38::vf10() {}

class Unk_23efda0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100dc8ac0
void Unk_23efda0::vf5() {
    Unk_dc8b00(this);
}

class Unk_23efde0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100dc8ad0
void Unk_23efde0::vf0() {
    Unk_dc8b00(this);
}

class Unk_23efe08 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual u32 vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual u32 vf13();
    virtual void vf14();
};

// 0x7100dc8d50
u32 Unk_23efe08::vf7() {
    return 1;
}

// 0x7100dc8d60
u32 Unk_23efe08::vf8() {
    return 1;
}

// 0x7100dc8d70
void Unk_23efe08::vf9() {}

// 0x7100dc8d80
void Unk_23efe08::vf10() {}

// 0x7100dca3b0
void Unk_23efe08::vf11() {
    Unk_dc8d90(this);
}

// 0x7100dca3c0
void Unk_23efe08::vf12() {}

// 0x7100dca3d0
u32 Unk_23efe08::vf13() {
    return 0;
}

// 0x7100dca3e0
void Unk_23efe08::vf14() {}

class Unk_23eff10 {
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
    virtual void vf14();
    u8 _8[0x60];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23eff10, field_68, 0x68);

// 0x7100dcb510
void Unk_23eff10::vf10() {
    if (field_68 != 0) {
        Unk_dcb520(field_68);
    }
}

// 0x7100dcb670
void Unk_23eff10::vf11() {
    if (field_68 != 0) {
        Unk_dcb680(field_68);
    }
}

// 0x7100dcbe70
void Unk_23eff10::vf12() {}

// 0x7100dcd830
u32 Unk_23eff10::vf13() {
    return 0;
}

// 0x7100dcd840
void Unk_23eff10::vf14() {}

class Unk_23f0000 {
public:
    virtual ~Unk_23f0000();
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
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
};

// 0x7100dce290
void Unk_23f0000::vf6() {
    Unk_dce9d0(this);
}

// 0x7100dce6d0
void Unk_23f0000::vf19() {}

class Unk_23f0260 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100dce710
void Unk_23f0260::vf5() {
    Unk_dce9d0(this);
}

class Unk_23f02a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100dce720
void Unk_23f02a0::vf0() {
    Unk_dce9d0(this);
}

class Unk_23f02c8 {
public:
    virtual ~Unk_23f02c8();
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
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
};

// 0x7100dceff0
void Unk_23f02c8::vf6() {
    Unk_dcf2b0(this);
}

// 0x7100dcf240
void Unk_23f02c8::vf19() {}

class Unk_23f0528 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100dcf270
void Unk_23f0528::vf5() {
    Unk_dcf2b0(this);
}

class Unk_23f0568 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100dcf280
void Unk_23f0568::vf0() {
    Unk_dcf2b0(this);
}

class Unk_23f06c0 {
public:
    virtual ~Unk_23f06c0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(bool value);
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    u8 _8[0x130];
    u64 field_138;
    u8 _140[0xe0];
    u32 field_220;
    u32 field_224;
    u8 field_228;
};
PKMN_OFFSET_ASSERT(Unk_23f06c0, field_138, 0x138);
PKMN_OFFSET_ASSERT(Unk_23f06c0, field_220, 0x220);
PKMN_OFFSET_ASSERT(Unk_23f06c0, field_224, 0x224);
PKMN_OFFSET_ASSERT(Unk_23f06c0, field_228, 0x228);

// 0x7100dd7460
void Unk_23f06c0::vf2() {
    field_220 = 0;
}

// 0x7100dd7470
void Unk_23f06c0::vf3() {
    Unk_dcf560(this);
}

// 0x7100dd7480
void Unk_23f06c0::vf4() {
    field_224 = 0;
}

// 0x7100dd7490
void Unk_23f06c0::vf5() {
    Unk_dd2a30(this);
}

// 0x7100dd74a0
void Unk_23f06c0::vf6() {
    Unk_dd48f0(&field_228);
}

// 0x7100dd7540
void Unk_23f06c0::vf9(bool value) {
    if (field_138 != 0) {
        Unk_14ac3c0(field_138, value);
    }
}

class Unk_23f0738 {
public:
    virtual ~Unk_23f0738();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u32 vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};

// 0x7100dd8110
u32 Unk_23f0738::vf7() {
    return 1;
}

// 0x7100dd8780
void Unk_23f0738::vf10() {}

class Unk_23f0820 {
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
};

// 0x7100ddb0b0
u32 Unk_23f0820::vf7() {
    return 1;
}
