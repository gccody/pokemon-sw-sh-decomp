// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_cffc00(void* self);
void Unk_d00210(void* self);
void Unk_d02730(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_cf4fc0(u64);
void Unk_cf5bd0(u64);
void Unk_cf5ee0(u64);
void Unk_cf72e0(u64);

// Globals other TUs define, named after their addresses.
extern u32 Unk_27dbaf8;
extern u32 Unk_27dbafc;
extern u32 Unk_27dbdb0;
extern u32 Unk_27dbdb4;

class Unk_23e4758 {
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
    virtual u32 vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual f32 vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual bool vf43();
    virtual void vf44();
    virtual void vf45();
    virtual bool vf46();
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
    virtual void vf74(bool value);
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    u8 _8[0x5a4];
    f32 field_5ac;
    u8 _5b0[0x8];
    bool field_5b8;
};
PKMN_OFFSET_ASSERT(Unk_23e4758, field_5ac, 0x5ac);
PKMN_OFFSET_ASSERT(Unk_23e4758, field_5b8, 0x5b8);

// 0x7100cf25b0
u32 Unk_23e4758::vf33() {
    return 1;
}

// 0x7100cf25c0
f32 Unk_23e4758::vf38() {
    return field_5ac;
}

// 0x7100cf25f0
void Unk_23e4758::vf40() {
    Unk_27dbaf8 = Unk_27dbaf8 + 1;
}

// 0x7100cf2610
void Unk_23e4758::vf41() {
    if (Unk_27dbaf8 != 0) {
        Unk_27dbaf8 = Unk_27dbaf8 - 1;
    }
}

// 0x7100cf2630
void Unk_23e4758::vf42() {
    Unk_27dbaf8 = 0;
}

// 0x7100cf2640
bool Unk_23e4758::vf43() {
    return Unk_27dbaf8 != 0;
}

// 0x7100cf2660
void Unk_23e4758::vf44() {
    Unk_27dbafc = Unk_27dbafc + 1;
}

// 0x7100cf2680
void Unk_23e4758::vf45() {
    Unk_27dbafc = 0;
}

// 0x7100cf2690
bool Unk_23e4758::vf46() {
    return Unk_27dbafc > 1;
}

// 0x7100cf26b0
void Unk_23e4758::vf74(bool value) {
    field_5b8 = value;
}

// 0x7100cf23d0
void Unk_23e4758::vf77() {}

class Unk_23e4b58 {
public:
    virtual ~Unk_23e4b58();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100cf4520, 0x7100cf43c0
Unk_23e4b58::~Unk_23e4b58() {}

// 0x7100cf4430
void Unk_23e4b58::vf4() {}

class Unk_23e4ba0 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23e4ba0, field_78, 0x78);

// 0x7100cf4f90
void Unk_23e4ba0::vf12() {}

// 0x7100cf4fb0
void Unk_23e4ba0::vf13() {
    Unk_cf4fc0(field_78);
}

class Unk_23e4c20 {
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
    u8 _8[0x28];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_23e4c20, field_30, 0x30);

// 0x7100cf4fa0
void Unk_23e4c20::vf10() {}

// 0x7100cf5110
void Unk_23e4c20::vf11() {
    Unk_cf4fc0(field_30);
}

class Unk_23e4cb8 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23e4cb8, field_78, 0x78);

// 0x7100cf5bc0
void Unk_23e4cb8::vf12() {
    Unk_cf5bd0(field_78);
}

// 0x7100cf5ed0
void Unk_23e4cb8::vf13() {
    Unk_cf5ee0(field_78);
}

class Unk_23e4d38 {
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
    u8 _8[0x28];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_23e4d38, field_30, 0x30);

// 0x7100cf5ec0
void Unk_23e4d38::vf10() {
    Unk_cf5bd0(field_30);
}

// 0x7100cf6c70
void Unk_23e4d38::vf11() {
    Unk_cf5ee0(field_30);
}

class Unk_23e4dd8 {
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
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23e4dd8, field_78, 0x78);

// 0x7100cf72d0
void Unk_23e4dd8::vf13() {
    Unk_cf72e0(field_78);
}

class Unk_23e4e58 {
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
    u8 _8[0x28];
    u64 field_30;
};
PKMN_OFFSET_ASSERT(Unk_23e4e58, field_30, 0x30);

// 0x7100cf78d0
void Unk_23e4e58::vf11() {
    Unk_cf72e0(field_30);
}

class Unk_23e54c0 {
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
    u8 _8[0x60];
    u8 field_68;
};
PKMN_OFFSET_ASSERT(Unk_23e54c0, field_68, 0x68);

// 0x7100cfe870
void Unk_23e54c0::vf10() {}

// 0x7100cfe860
void Unk_23e54c0::vf11() {
    field_68 = 0;
}

// 0x7100cfe850
void Unk_23e54c0::vf12() {
    field_68 = 1;
}

class Unk_23e55c0 {
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
    virtual u32 vf9();
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
    virtual bool vf43();
    virtual void vf44();
    virtual void vf45();
    virtual bool vf46();
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

// 0x7100cff110
u32 Unk_23e55c0::vf9() {
    return 1;
}

// 0x7100cff120
void Unk_23e55c0::vf40() {
    Unk_27dbdb0 = Unk_27dbdb0 + 1;
}

// 0x7100cff140
void Unk_23e55c0::vf41() {
    if (Unk_27dbdb0 != 0) {
        Unk_27dbdb0 = Unk_27dbdb0 - 1;
    }
}

// 0x7100cff160
void Unk_23e55c0::vf42() {
    Unk_27dbdb0 = 0;
}

// 0x7100cff170
bool Unk_23e55c0::vf43() {
    return Unk_27dbdb0 > 9;
}

// 0x7100cff190
void Unk_23e55c0::vf44() {
    Unk_27dbdb4 = Unk_27dbdb4 + 1;
}

// 0x7100cff1b0
void Unk_23e55c0::vf45() {
    Unk_27dbdb4 = 0;
}

// 0x7100cff1c0
bool Unk_23e55c0::vf46() {
    return Unk_27dbdb4 > 9;
}

class Unk_23e5860 {
public:
    virtual ~Unk_23e5860();
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
};

// 0x7100cffb90
void Unk_23e5860::vf6() {
    Unk_cffc00(this);
}

class Unk_23e59f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100cffbc0
void Unk_23e59f0::vf5() {
    Unk_cffc00(this);
}

class Unk_23e5a30 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100cffbd0
void Unk_23e5a30::vf0() {
    Unk_cffc00(this);
}

class Unk_23e5a58 {
public:
    virtual ~Unk_23e5a58();
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
};

// 0x7100d001a0
void Unk_23e5a58::vf6() {
    Unk_d00210(this);
}

class Unk_23e5be8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d001d0
void Unk_23e5be8::vf5() {
    Unk_d00210(this);
}

class Unk_23e5c28 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d001e0
void Unk_23e5c28::vf0() {
    Unk_d00210(this);
}

class Unk_23e5c50 {
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
    virtual u32 vf33();
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

// 0x7100d00be0
void Unk_23e5c50::vf19() {}

// 0x7100d01b50
u32 Unk_23e5c50::vf33() {
    return 1;
}

class Unk_23e5ef8 {
public:
    virtual ~Unk_23e5ef8();
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
};

// 0x7100d026c0
void Unk_23e5ef8::vf6() {
    Unk_d02730(this);
}

class Unk_23e6088 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d026f0
void Unk_23e6088::vf5() {
    Unk_d02730(this);
}

class Unk_23e60c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d02700
void Unk_23e60c8::vf0() {
    Unk_d02730(this);
}

class Unk_23e60f0 {
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

// 0x7100d02f30
void Unk_23e60f0::vf19() {}
