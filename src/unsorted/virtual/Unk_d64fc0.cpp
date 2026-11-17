// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_d68110(void* self);
void Unk_d6c120(void* self);

class Unk_23ecbb8 {
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

// 0x7100d67f60
void Unk_23ecbb8::vf6() {
    Unk_d68110(this);
}

// 0x7100d64fc0
u32 Unk_23ecbb8::vf7() {
    return 1;
}

// 0x7100d64fd0
void Unk_23ecbb8::vf8() {}

// 0x7100d677c0
void Unk_23ecbb8::vf10() {}

class Unk_23ecc20 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d68030
void Unk_23ecc20::vf5() {
    Unk_d68110(this);
}

class Unk_23ecc60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d68040
void Unk_23ecc60::vf0() {
    Unk_d68110(this);
}

class Unk_23ecc88 {
public:
    virtual ~Unk_23ecc88();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100d68380
void Unk_23ecc88::vf4() {}

class Unk_23eccd0 {
public:
    virtual ~Unk_23eccd0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7100d68640
void Unk_23eccd0::vf4() {}

class Unk_23ecd18 {
public:
    virtual ~Unk_23ecd18();
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
    virtual u8 vf31();
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
    virtual u32 vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    u8 _8[0x71c];
    u8 field_724;
};
PKMN_OFFSET_ASSERT(Unk_23ecd18, field_724, 0x724);

// 0x7100d692d0
void Unk_23ecd18::vf29() {
    field_724 = 1;
}

// 0x7100d693a0
u8 Unk_23ecd18::vf31() {
    return field_724;
}

// 0x7100d6a3d0
u32 Unk_23ecd18::vf33() {
    return 0;
}

// 0x7100d69dd0
u32 Unk_23ecd18::vf69() {
    return 0;
}

class Unk_23ed100 {
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

// 0x7100d6bf30
void Unk_23ed100::vf6() {
    Unk_d6c120(this);
}

// 0x7100d6bbf0
u32 Unk_23ed100::vf7() {
    return 1;
}

// 0x7100d6bc00
void Unk_23ed100::vf8() {}

// 0x7100d6be40
void Unk_23ed100::vf10() {}

class Unk_23ed168 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100d6c020
void Unk_23ed168::vf5() {
    Unk_d6c120(this);
}

class Unk_23ed1a8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100d6c030
void Unk_23ed1a8::vf0() {
    Unk_d6c120(this);
}
