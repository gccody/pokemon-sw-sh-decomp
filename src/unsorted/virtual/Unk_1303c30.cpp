// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_13041c0(void* self);
void Unk_1305570(void* self);
void Unk_1305840(void* self);

class Unk_242efc8 {
public:
    virtual ~Unk_242efc8();
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
    virtual u32 vf25();
};

// 0x7101303c30
void Unk_242efc8::vf21() {}

// 0x7101303c40
void Unk_242efc8::vf22() {}

// 0x7101303d30
u32 Unk_242efc8::vf25() {
    return 1;
}

class Unk_242ef18 {
public:
    virtual ~Unk_242ef18();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

// 0x7101304150
void Unk_242ef18::vf6() {
    Unk_13041c0(this);
}

class Unk_242ef60 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101304180
void Unk_242ef60::vf5() {
    Unk_13041c0(this);
}

class Unk_242efa0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101304190
void Unk_242efa0::vf0() {
    Unk_13041c0(this);
}

class Unk_242f1e0 {
public:
    virtual ~Unk_242f1e0();
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
};

// 0x7101305500
void Unk_242f1e0::vf6() {
    Unk_1305570(this);
}

class Unk_242f278 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101305530
void Unk_242f278::vf5() {
    Unk_1305570(this);
}

class Unk_242f2b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101305540
void Unk_242f2b8::vf0() {
    Unk_1305570(this);
}

class Unk_242f2e0 {
public:
    virtual ~Unk_242f2e0();
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
};

// 0x71013057d0
void Unk_242f2e0::vf6() {
    Unk_1305840(this);
}

// 0x71013056a0
void Unk_242f2e0::vf8() {}

class Unk_242f378 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101305800
void Unk_242f378::vf5() {
    Unk_1305840(this);
}

class Unk_242f3b8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101305810
void Unk_242f3b8::vf0() {
    Unk_1305840(this);
}

class Unk_242f448 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

// 0x71013079a0
void Unk_242f448::vf2() {}

class Unk_242f478 {
public:
    virtual void vf0();
    virtual void vf1();
};

// 0x7101307a20
void Unk_242f478::vf0() {}

class Unk_242f550 {
public:
    virtual ~Unk_242f550();
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
    u8 _8[0x138];
    u8 field_140;
    u8 _141[0xf];
    u64 field_150;
};
PKMN_OFFSET_ASSERT(Unk_242f550, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_242f550, field_150, 0x150);

// 0x7101309aa0
void Unk_242f550::vf16() {
    field_150 = 0;
    field_140 = 0;
}
