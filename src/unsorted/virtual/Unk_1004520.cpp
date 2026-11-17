// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

class Unk_24067f8 {
public:
    virtual ~Unk_24067f8();
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
    u8 _8[0x98];
    u8 field_a0;
    u8 _a1[0x2b0];
    u8 field_351;
};
PKMN_OFFSET_ASSERT(Unk_24067f8, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_24067f8, field_351, 0x351);

// 0x7101004520
void Unk_24067f8::vf22() {
    field_351 = 1;
}

// 0x71010045d0
void Unk_24067f8::vf24() {
    field_a0 = 1;
}

// 0x71010045f0
void Unk_24067f8::vf25() {
    field_a0 = 0;
}

// 0x7101004610
void Unk_24067f8::vf26() {
    field_a0 = 1;
}

class Unk_2406a38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    u8 _8[0x2d1];
    u8 field_2d9;
};
PKMN_OFFSET_ASSERT(Unk_2406a38, field_2d9, 0x2d9);

// 0x7101004530
void Unk_2406a38::vf2() {
    field_2d9 = 1;
}

class Unk_2406968 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x30];
    u8 field_38;
};
PKMN_OFFSET_ASSERT(Unk_2406968, field_38, 0x38);

// 0x71010045e0
void Unk_2406968::vf1() {
    field_38 = 1;
}

// 0x7101004780
void Unk_2406968::vf2() {}

// 0x7101004790
void Unk_2406968::vf3() {}

// 0x7101004600
void Unk_2406968::vf4() {
    field_38 = 0;
}

// 0x7101004620
void Unk_2406968::vf5() {
    field_38 = 1;
}

// 0x71010047a0
void Unk_2406968::vf6() {}

// 0x71010047b0
void Unk_2406968::vf7() {}

class Unk_24069b8 {
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
};

// 0x71010047c0
void Unk_24069b8::vf7() {}

class Unk_2406bb8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406bb8, field_78, 0x78);

// 0x7101005d10
u64 Unk_2406bb8::vf7() {
    return field_78;
}

class Unk_2406c80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406c80, field_78, 0x78);

// 0x7101006290
u64 Unk_2406c80::vf7() {
    return field_78;
}

class Unk_2406d48 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406d48, field_78, 0x78);

// 0x71010067f0
u64 Unk_2406d48::vf7() {
    return field_78;
}

class Unk_2406e10 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406e10, field_78, 0x78);

// 0x7101006d50
u64 Unk_2406e10::vf7() {
    return field_78;
}

class Unk_2406ed8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406ed8, field_78, 0x78);

// 0x71010072d0
u64 Unk_2406ed8::vf7() {
    return field_78;
}

class Unk_2406fa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2406fa0, field_78, 0x78);

// 0x7101007850
u64 Unk_2406fa0::vf7() {
    return field_78;
}

class Unk_2407068 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2407068, field_78, 0x78);

// 0x7101007dd0
u64 Unk_2407068::vf7() {
    return field_78;
}

class Unk_2407130 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual u64 vf7();
    virtual void vf8();
    virtual void vf9();
    u8 _8[0x70];
    u64 field_78;
};
PKMN_OFFSET_ASSERT(Unk_2407130, field_78, 0x78);

// 0x7101008360
u64 Unk_2407130::vf7() {
    return field_78;
}
