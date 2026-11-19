// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_3044e0(void* self);
void Unk_3044f0(void* self);
void Unk_305c10(void* self);
void Unk_32efa0(void* self);
void Unk_32f750(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_305410(u64);
void Unk_305720(u64);
void Unk_305c00(u64);
void Unk_32eec0(u64);
void Unk_32efb0(u64, u64);
void Unk_32f6f0(u64);
void Unk_32fdc0(u64);
void Unk_32fdd0(u32);
void Unk_32fe00(u64, u64);
void Unk_32ff90(u64, u64, u32);
void Unk_330070(u64, u32);
void Unk_330140(u32, u64, u32, u32, u32);
void Unk_330230(u64, u64, u32, u32, u32);
void Unk_3303e0(u32, u32, u64);
void Unk_330450(u64, u64, u64);
void Unk_330630(u32, u64);
void Unk_3306a0(u64, u64);
void Unk_3307c0(u32, u32);
void Unk_3308e0(u64, u64);
void Unk_330ac0(u64, u64, u32);
void Unk_330b50(u64, u64);
void Unk_331550(u64);
void Unk_3315d0(u64, u64);
void Unk_331650(u64);
void Unk_3316d0(u64, u32, u64);
void Unk_3318d0(u32, u32);
void Unk_331990(u64, u32, u64);
void Unk_331a90(u64, u32, u32, u64);
void Unk_331b60(u64, u64, u64, u32, u64);
void Unk_331d30(u32, u64, u64, u32);
void Unk_331d90(u64, u32, u64, u64, u64);
void Unk_331e50(u64, u32, u64, u64, u32, u64);
void Unk_331ef0(u32, u64, u64);
void Unk_331fd0(u64, u64, u64);
void Unk_3321b0(u64, u64, u64, u64);
void Unk_332360(u32, u64, u64, u64);
void Unk_3328c0(u32, u32, u32);
void Unk_3e3fb0(u64);
void Unk_3e5810(u64, u64);
void Unk_3e5940(u64);
void Unk_3e5b00(u64);
void Unk_3e5b70(u64);
void Unk_3e60e0(u64, u64, u32);
void Unk_3e6190(u64, u64);
void Unk_3f7e40(u64);
void Unk_3f7f40(u64);
void Unk_3f7f50(u64);
void Unk_3f8280(u64);

class Unk_239f8e8 {
public:
    virtual u32 vf0();
    virtual void vf1();
    virtual void* vf2();
};

// 0x710065dbb0
u32 Unk_239f8e8::vf0() {
    return 0xffffffff;
}

// 0x710065dbc0
void Unk_239f8e8::vf1() {}

// 0x710065dbd0
void* Unk_239f8e8::vf2() {
    return nullptr;
}

class Unk_236d0b8 {
public:
    virtual ~Unk_236d0b8();
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
    virtual void vf14(bool value);
    virtual void vf15();
    virtual void* vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    u8 _8[0x10];
    bool field_18;
    u8 _19[0x77];
    bool field_90;
};
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_236d0b8, field_90, 0x90);

// 0x710065fb10
void* Unk_236d0b8::vf16() {
    return nullptr;
}

class Unk_239fac0 {
public:
    virtual ~Unk_239fac0();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100663d20, 0x7100663d30
Unk_239fac0::~Unk_239fac0() {}

class Unk_23a08f0 {
public:
    virtual ~Unk_23a08f0();
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
};

// 0x71006791a0
void Unk_23a08f0::vf15() {}

class Unk_23a0a18 {
public:
    virtual ~Unk_23a0a18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64 value);
};

// 0x7100679cd0, 0x7100679c90
Unk_23a0a18::~Unk_23a0a18() {}

// 0x7100679ca0
void Unk_23a0a18::vf2() {
    Unk_3044e0(this);
}

// 0x7100679cb0
void Unk_23a0a18::vf3() {
    Unk_3044f0(this);
}

// 0x7100679cc0
void Unk_23a0a18::vf4(u64 value) {
    Unk_305410(value);
}

class Unk_23a0a50 {
public:
    virtual ~Unk_23a0a50();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value);
    virtual void vf4();
};

// 0x7100679ce0, 0x7100679cf0
Unk_23a0a50::~Unk_23a0a50() {}

// 0x7100679d00
void Unk_23a0a50::vf2(u64 value) {
    Unk_305720(value);
}

// 0x7100679d10
void Unk_23a0a50::vf3(u64 value) {
    Unk_305c00(value);
}

// 0x7100679d20
void Unk_23a0a50::vf4() {
    Unk_305c10(this);
}

class Unk_23a0a88 {
public:
    virtual ~Unk_23a0a88();
    virtual void vf2(u64 value);
    virtual void vf3();
    virtual void vf4(u64 value, u64 arg2);
    virtual void vf5(u64 value);
    virtual void vf6(u64 value);
    virtual void vf7();
    virtual void vf8(bool value);
    virtual void vf9(u64 value);
    virtual void vf10(u64 value, u64 arg2);
    virtual void vf11(u64 value);
    virtual void vf12(u64 value, u64 arg2);
    virtual void vf13(u64 value, u64 arg2, u32 arg3);
    virtual void vf14(u64 value, u32 arg2);
    virtual void vf15(u32 value, u64 arg2, u32 arg3, u32 arg4, bool arg5);
    virtual void vf16(u64 value, u64 arg2, u32 arg3, u32 arg4, bool arg5);
    virtual void vf17(u32 value, u32 arg2, u64 arg3);
    virtual void vf18(u64 value, u64 arg2, u64 arg3);
    virtual void vf19(u32 value, u64 arg2);
    virtual void vf20(u64 value, u64 arg2);
    virtual void vf21(u32 value, u32 arg2);
    virtual void vf22(u64 value, u64 arg2);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26(u32 value, u32 arg2, u32 arg3);
    virtual void vf27(u64 value, u32 arg2, u64 arg3);
    virtual void vf28(u32 value, u32 arg2);
    virtual void vf29(u64 value, u32 arg2, u64 arg3);
    virtual void vf30(u64 value, u32 arg2, u32 arg3, u64 arg4);
    virtual void vf31(u64 value, u64 arg2, u64 arg3, u32 arg4, u64 arg5);
    virtual void vf32(u32 value, u64 arg2, u64 arg3, u32 arg4);
    virtual void vf33(u64 value, u32 arg2, u64 arg3, u64 arg4, u64 arg5);
    virtual void vf34(u64 value, u32 arg2, u64 arg3, u64 arg4, u32 arg5, u64 arg6);
    virtual void vf35(u64 value, u64 arg2, u64 arg3);
    virtual void vf36(u32 value, u64 arg2, u64 arg3);
    virtual void vf37(u64 value, u64 arg2, u64 arg3, u64 arg4);
    virtual void vf38(u32 value, u64 arg2, u64 arg3, u64 arg4);
    virtual void vf39(u64 value, u64 arg2, u32 arg3);
    virtual void vf40(u64 value, u64 arg2);
};

// 0x7100679d30, 0x7100679d40
Unk_23a0a88::~Unk_23a0a88() {}

// 0x7100679d50
void Unk_23a0a88::vf2(u64 value) {
    Unk_32eec0(value);
}

// 0x7100679d60
void Unk_23a0a88::vf3() {
    Unk_32efa0(this);
}

// 0x7100679d70
void Unk_23a0a88::vf4(u64 value, u64 arg2) {
    Unk_32efb0(value, arg2);
}

// 0x7100679d80
void Unk_23a0a88::vf5(u64 value) {
    Unk_32f6f0(value);
}

// 0x7100679d90
void Unk_23a0a88::vf6(u64 value) {
    Unk_32fdc0(value);
}

// 0x7100679da0
void Unk_23a0a88::vf7() {
    Unk_32f750(this);
}

// 0x7100679db0
void Unk_23a0a88::vf8(bool value) {
    Unk_32fdd0(value);
}

// 0x7100679dc0
void Unk_23a0a88::vf9(u64 value) {
    Unk_331550(value);
}

// 0x7100679dd0
void Unk_23a0a88::vf10(u64 value, u64 arg2) {
    Unk_3315d0(value, arg2);
}

// 0x7100679de0
void Unk_23a0a88::vf11(u64 value) {
    Unk_331650(value);
}

// 0x7100679df0
void Unk_23a0a88::vf12(u64 value, u64 arg2) {
    Unk_32fe00(value, arg2);
}

// 0x7100679e00
void Unk_23a0a88::vf13(u64 value, u64 arg2, u32 arg3) {
    Unk_32ff90(value, arg2, arg3);
}

// 0x7100679e10
void Unk_23a0a88::vf14(u64 value, u32 arg2) {
    Unk_330070(value, arg2);
}

// 0x7100679e20
void Unk_23a0a88::vf15(u32 value, u64 arg2, u32 arg3, u32 arg4, bool arg5) {
    Unk_330140(value, arg2, arg3, arg4, arg5);
}

// 0x7100679e40
void Unk_23a0a88::vf16(u64 value, u64 arg2, u32 arg3, u32 arg4, bool arg5) {
    Unk_330230(value, arg2, arg3, arg4, arg5);
}

// 0x7100679e60
void Unk_23a0a88::vf17(u32 value, u32 arg2, u64 arg3) {
    Unk_3303e0(value, arg2, arg3);
}

// 0x7100679e70
void Unk_23a0a88::vf18(u64 value, u64 arg2, u64 arg3) {
    Unk_330450(value, arg2, arg3);
}

// 0x7100679e80
void Unk_23a0a88::vf19(u32 value, u64 arg2) {
    Unk_330630(value, arg2);
}

// 0x7100679e90
void Unk_23a0a88::vf20(u64 value, u64 arg2) {
    Unk_3306a0(value, arg2);
}

// 0x7100679ea0
void Unk_23a0a88::vf21(u32 value, u32 arg2) {
    Unk_3307c0(value, arg2);
}

// 0x7100679eb0
void Unk_23a0a88::vf22(u64 value, u64 arg2) {
    Unk_3308e0(value, arg2);
}

// 0x7100679f50
void Unk_23a0a88::vf26(u32 value, u32 arg2, u32 arg3) {
    Unk_3328c0(value, arg2, arg3);
}

// 0x7100679f60
void Unk_23a0a88::vf27(u64 value, u32 arg2, u64 arg3) {
    Unk_3316d0(value, arg2, arg3);
}

// 0x7100679f70
void Unk_23a0a88::vf28(u32 value, u32 arg2) {
    Unk_3318d0(value, arg2);
}

// 0x7100679f80
void Unk_23a0a88::vf29(u64 value, u32 arg2, u64 arg3) {
    Unk_331990(value, arg2, arg3);
}

// 0x7100679f90
void Unk_23a0a88::vf30(u64 value, u32 arg2, u32 arg3, u64 arg4) {
    Unk_331a90(value, arg2, arg3, arg4);
}

// 0x7100679fb0
void Unk_23a0a88::vf31(u64 value, u64 arg2, u64 arg3, u32 arg4, u64 arg5) {
    Unk_331b60(value, arg2, arg3, arg4, arg5);
}

// 0x7100679fd0
void Unk_23a0a88::vf32(u32 value, u64 arg2, u64 arg3, u32 arg4) {
    Unk_331d30(value, arg2, arg3, arg4);
}

// 0x7100679ff0
void Unk_23a0a88::vf33(u64 value, u32 arg2, u64 arg3, u64 arg4, u64 arg5) {
    Unk_331d90(value, arg2, arg3, arg4, arg5);
}

// 0x710067a010
void Unk_23a0a88::vf34(u64 value, u32 arg2, u64 arg3, u64 arg4, u32 arg5, u64 arg6) {
    Unk_331e50(value, arg2, arg3, arg4, arg5, arg6);
}

// 0x710067a030
void Unk_23a0a88::vf35(u64 value, u64 arg2, u64 arg3) {
    Unk_331fd0(value, arg2, arg3);
}

// 0x710067a040
void Unk_23a0a88::vf36(u32 value, u64 arg2, u64 arg3) {
    Unk_331ef0(value, arg2, arg3);
}

// 0x710067a050
void Unk_23a0a88::vf37(u64 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_3321b0(value, arg2, arg3, arg4);
}

// 0x710067a070
void Unk_23a0a88::vf38(u32 value, u64 arg2, u64 arg3, u64 arg4) {
    Unk_332360(value, arg2, arg3, arg4);
}

// 0x710067a090
void Unk_23a0a88::vf39(u64 value, u64 arg2, u32 arg3) {
    Unk_330ac0(value, arg2, arg3);
}

// 0x710067a0a0
void Unk_23a0a88::vf40(u64 value, u64 arg2) {
    Unk_330b50(value, arg2);
}

class Unk_23a0be0 {
public:
    virtual ~Unk_23a0be0();
    virtual void vf2(u64 value);
    virtual void vf3(u64 value, u64 arg2);
    virtual void vf4(u64 value);
    virtual void vf5(u64 value);
    virtual void vf6(u64 value);
    virtual void vf7(u64 value, u64 arg2);
    virtual void vf8(u64 value, u64 arg2, u32 arg3);
};

// 0x710067a0b0, 0x710067a0c0
Unk_23a0be0::~Unk_23a0be0() {}

// 0x710067a0d0
void Unk_23a0be0::vf2(u64 value) {
    Unk_3e3fb0(value);
}

// 0x710067a0e0
void Unk_23a0be0::vf3(u64 value, u64 arg2) {
    Unk_3e5810(value, arg2);
}

// 0x710067a0f0
void Unk_23a0be0::vf4(u64 value) {
    Unk_3e5940(value);
}

// 0x710067a100
void Unk_23a0be0::vf5(u64 value) {
    Unk_3e5b00(value);
}

// 0x710067a110
void Unk_23a0be0::vf6(u64 value) {
    Unk_3e5b70(value);
}

// 0x710067a120
void Unk_23a0be0::vf7(u64 value, u64 arg2) {
    Unk_3e6190(value, arg2);
}

// 0x710067a130
void Unk_23a0be0::vf8(u64 value, u64 arg2, u32 arg3) {
    Unk_3e60e0(value, arg2, arg3);
}

class Unk_23a0c38 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64 value);
    virtual void vf4(u64 value);
    virtual void vf5(u64 value);
    virtual void vf6(u64 value);
};

// 0x710067a160
void Unk_23a0c38::vf1() {}

// 0x710067a170
void Unk_23a0c38::vf2() {
    ::operator delete(this);
}

// 0x710067a180
void Unk_23a0c38::vf3(u64 value) {
    Unk_3f7e40(value);
}

// 0x710067a190
void Unk_23a0c38::vf4(u64 value) {
    Unk_3f7f40(value);
}

// 0x710067a1a0
void Unk_23a0c38::vf5(u64 value) {
    Unk_3f7f50(value);
}

// 0x710067a1b0
void Unk_23a0c38::vf6(u64 value) {
    Unk_3f8280(value);
}

class Unk_23a0c80 {
public:
    virtual ~Unk_23a0c80();
};

// 0x710067a1c0, 0x710067a1d0
Unk_23a0c80::~Unk_23a0c80() {}
