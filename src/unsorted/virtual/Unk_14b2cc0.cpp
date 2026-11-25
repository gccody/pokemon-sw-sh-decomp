// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_14b70f0(void* self);
void Unk_14b8030(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_685c60(u64, u32);
void Unk_14a9520(void*, u32);
void Unk_14ab040(u64, u64, u32);
void Unk_14ab080(u64, u64);
void Unk_14ab0c0(u64, u64);
void Unk_14ab200(u64, u64);
void Unk_14ab2b0(u64, u64);
void Unk_14ab380(u64, u64);
void Unk_14ab440(u64, u64, f32);
void Unk_14ab9a0(u64, u64, u64);
void Unk_14ac040(u64, u64, u64, u32);

class Unk_24422d8 {
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
    virtual void vf10(u64 value, bool arg2);
    virtual void vf11(u64 key);
    virtual void vf12(u64 key);
    virtual void vf13(u64 key);
    virtual void vf14(u64 key);
    virtual void vf15(u64 key);
    virtual void vf16(u64 key, f32 value);
    virtual void vf17();
    virtual u32 vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22(u64 value, u64 arg2);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27(u64 key, u64 arg2);
    u8 _8[0x50];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_24422d8, field_58, 0x58);

// 0x71014b2cc0
void Unk_24422d8::vf10(u64 value, bool arg2) {
    Unk_14ab040(field_58, value, arg2);
}

// 0x71014b2cd0
void Unk_24422d8::vf11(u64 key) {
    Unk_14ab080(field_58, key);
}

// 0x71014b2ce0
void Unk_24422d8::vf12(u64 key) {
    Unk_14ab0c0(field_58, key);
}

// 0x71014b2cf0
void Unk_24422d8::vf13(u64 key) {
    Unk_14ab200(field_58, key);
}

// 0x71014b2d00
void Unk_24422d8::vf14(u64 key) {
    Unk_14ab2b0(field_58, key);
}

// 0x71014b2d10
void Unk_24422d8::vf15(u64 key) {
    Unk_14ab380(field_58, key);
}

// 0x71014b2d20
void Unk_24422d8::vf16(u64 key, f32 value) {
    Unk_14ab440(field_58, key, value);
}

// 0x71014b2d60
u32 Unk_24422d8::vf18() {
    return 0;
}

// 0x71014b2f00
void Unk_24422d8::vf22(u64 value, u64 arg2) {
    Unk_14ac040(field_58, value, arg2, 0xa);
}

// 0x71014b3050
void Unk_24422d8::vf27(u64 key, u64 arg2) {
    Unk_14ab9a0(field_58, key, arg2);
}

class Unk_24423f8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x71014b3230
void Unk_24423f8::vf0() {}

// 0x71014b3250
void Unk_24423f8::vf1() {}

class Unk_2442430 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71014b3240
void Unk_2442430::vf0() {}

// 0x71014b3260
void Unk_2442430::vf1() {}

class Unk_2442460 {
public:
    virtual ~Unk_2442460();
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
    virtual u32 vf22();
    u8 _8[0xb8];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_2442460, field_c0, 0xc0);

// 0x71014b5a40
void Unk_2442460::vf8() {}

// 0x71014b5870
void Unk_2442460::vf13() {
    Unk_685c60(field_c0, 1);
}

// 0x71014b59b0
void Unk_2442460::vf21() {
    Unk_14a9520(this, 0);
}

// 0x71014b5880
u32 Unk_2442460::vf22() {
    return 3;
}

class Unk_24425f8 {
public:
    virtual ~Unk_24425f8();
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
    virtual u32 vf22();
    u8 _8[0xb8];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_24425f8, field_c0, 0xc0);

// 0x71014b6040
void Unk_24425f8::vf8() {}

// 0x71014b5f20
void Unk_24425f8::vf13() {
    Unk_685c60(field_c0, 1);
}

// 0x71014b5fb0
void Unk_24425f8::vf21() {
    Unk_14a9520(this, 0);
}

// 0x71014b5f30
u32 Unk_24425f8::vf22() {
    return 3;
}

class Unk_2442750 {
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
    virtual u32 vf22();
    u8 _8[0xb8];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_2442750, field_c0, 0xc0);

// 0x71014b64d0
void Unk_2442750::vf8() {}

// 0x71014b64e0
u32 Unk_2442750::vf9() {
    return 5;
}

// 0x71014b6310
void Unk_2442750::vf13() {
    Unk_685c60(field_c0, 1);
}

// 0x71014b6450
void Unk_2442750::vf21() {
    Unk_14a9520(this, 0);
}

// 0x71014b6320
u32 Unk_2442750::vf22() {
    return 3;
}

class Unk_24428a8 {
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
    virtual u32 vf22();
    u8 _8[0xb8];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_24428a8, field_c0, 0xc0);

// 0x71014b67a0
void Unk_24428a8::vf13() {
    Unk_685c60(field_c0, 1);
}

// 0x71014b6900
void Unk_24428a8::vf21() {
    Unk_14a9520(this, 0);
}

// 0x71014b67b0
u32 Unk_24428a8::vf22() {
    return 4;
}

struct Unk_2442a00_388 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2442a00_388, field_58, 0x58);

class Unk_2442a00 {
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
    virtual u32 vf22();
    virtual void vf23();
    virtual u32 vf24();
    virtual void vf25();
    virtual u32 vf26();
    u8 _8[0x380];
    Unk_2442a00_388* field_388;
};
PKMN_OFFSET_ASSERT(Unk_2442a00, field_388, 0x388);

// 0x71014b76a0
void Unk_2442a00::vf8() {
    Unk_14b70f0(this);
}

// 0x71014b7190
u32 Unk_2442a00::vf22() {
    return 7;
}

// 0x71014b75d0
u32 Unk_2442a00::vf24() {
    return 1;
}

// 0x71014b6e60
u32 Unk_2442a00::vf26() {
    return field_388->field_58 & 1;
}

struct Unk_2442b50_328 {
    u8 _0[0x58];
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_2442b50_328, field_58, 0x58);

class Unk_2442b50 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual u32 vf2();
    u8 _8[0x320];
    Unk_2442b50_328* field_328;
};
PKMN_OFFSET_ASSERT(Unk_2442b50, field_328, 0x328);

// 0x71014b75e0
u32 Unk_2442b50::vf0() {
    return 1;
}

// 0x71014b6e70
u32 Unk_2442b50::vf2() {
    return field_328->field_58 & 1;
}

class Unk_2442b78 {
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
    virtual u32 vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
};

// 0x71014b78c0
void Unk_2442b78::vf8() {}

// 0x71014b74a0
u32 Unk_2442b78::vf22() {
    return 6;
}

class Unk_2442cf0 {
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
    virtual u32 vf22();
    u8 _8[0xb8];
    u64 field_c0;
};
PKMN_OFFSET_ASSERT(Unk_2442cf0, field_c0, 0xc0);

// 0x71014b87d0
void Unk_2442cf0::vf8() {
    Unk_14b8030(this);
}

// 0x71014b81e0
void Unk_2442cf0::vf13() {
    Unk_685c60(field_c0, 1);
}

// 0x71014b8370
void Unk_2442cf0::vf21() {
    Unk_14a9520(this, 0);
}

// 0x71014b81f0
u32 Unk_2442cf0::vf22() {
    return 6;
}

class Unk_24430f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual u32 vf5();
    virtual bool vf6();
    virtual void* vf7();
    virtual void* vf8();
    virtual void* vf9();
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24430f0, field_8, 0x8);

// 0x71014bcf80
void Unk_24430f0::vf1() {}

// 0x71014bcf00
void Unk_24430f0::vf2() {
    ::operator delete(this);
}

// 0x71014bcf10
void Unk_24430f0::vf3() {}

// 0x71014bcf40
u32 Unk_24430f0::vf5() {
    return 0;
}

// 0x71014bacc0
bool Unk_24430f0::vf6() {
    return field_8 != 0xffffffffffffffff;
}

// 0x71014bcf50
void* Unk_24430f0::vf7() {
    return nullptr;
}

// 0x71014bcf60
void* Unk_24430f0::vf8() {
    return nullptr;
}

// 0x71014bcf70
void* Unk_24430f0::vf9() {
    return nullptr;
}
