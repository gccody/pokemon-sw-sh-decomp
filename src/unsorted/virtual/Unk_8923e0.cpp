// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6b9d40(u64);

// Lifted through their own placeholder structs (cast_member).
struct Unk_897d20_148 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_897d20_148, field_2a0, 0x2a0);

struct Unk_897d20 {
    u8 _0[0x148];
    Unk_897d20_148* field_148;
};
PKMN_OFFSET_ASSERT(Unk_897d20, field_148, 0x148);

void Unk_6ae9d0(u64);
void Unk_6d7ac0(u64, u64, u32);

struct Unk_897d70_d8 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_897d70_d8, field_2a0, 0x2a0);

struct Unk_897d70 {
    u8 _0[0xd8];
    Unk_897d70_d8* field_d8;
};
PKMN_OFFSET_ASSERT(Unk_897d70, field_d8, 0xd8);

void Unk_6ae9d0(u64);
void Unk_6d7ac0(u64, u64, u32);

class Unk_23b7ea8 {
public:
    virtual ~Unk_23b7ea8();
};

// 0x71008923e0, 0x71008923f0
Unk_23b7ea8::~Unk_23b7ea8() {}

class Unk_23b7ec8 {
public:
    virtual ~Unk_23b7ec8();
};

// 0x7100892af0, 0x7100892b00
Unk_23b7ec8::~Unk_23b7ec8() {}

class Unk_23b7ee8 {
public:
    virtual ~Unk_23b7ee8();
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
    virtual void vf16(u32 /*unused*/, u64 arg2);
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    u8 _8[0x139];
    u8 field_141;
    u8 _142[0x27e];
    u64 field_3c0;
};
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_141, 0x141);
PKMN_OFFSET_ASSERT(Unk_23b7ee8, field_3c0, 0x3c0);

// 0x71008972c0
void Unk_23b7ee8::vf9() {
    if (field_3c0 != 0) {
        Unk_6b9d40(field_3c0);
    }
}

// 0x7100897d20
void Unk_23b7ee8::vf16(u32 /*unused*/, u64 arg2) {
    const Unk_897d20* self = reinterpret_cast<const Unk_897d20*>(this);
    if (self->field_148 != nullptr) {
        Unk_6ae9d0(arg2);
        Unk_6d7ac0(self->field_148->field_2a0, arg2, 1);
    }
}

// 0x7100898320
void Unk_23b7ee8::vf22() {
    field_141 = 1;
}

// 0x7100898340
void Unk_23b7ee8::vf23() {
    field_141 = 0;
}

// 0x7100898360
void Unk_23b7ee8::vf24() {
    field_141 = 1;
}

class Unk_23b8028 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x358];
    u64 field_360;
};
PKMN_OFFSET_ASSERT(Unk_23b8028, field_360, 0x360);

// 0x71008972d0
void Unk_23b8028::vf1() {
    if (field_360 != 0) {
        Unk_6b9d40(field_360);
    }
}

class Unk_23b80c8 {
public:
    virtual void vf0(u32 /*unused*/, u64 arg2);
    virtual void vf1();
    virtual void vf2();
};

// 0x7100897d70
void Unk_23b80c8::vf0(u32 /*unused*/, u64 arg2) {
    const Unk_897d70* self = reinterpret_cast<const Unk_897d70*>(this);
    if (self->field_d8 != nullptr) {
        Unk_6ae9d0(arg2);
        Unk_6d7ac0(self->field_d8->field_2a0, arg2, 1);
    }
}

// 0x7100898d60
void Unk_23b80c8::vf1() {}

class Unk_23b8078 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0xd1];
    u8 field_d9;
};
PKMN_OFFSET_ASSERT(Unk_23b8078, field_d9, 0xd9);

// 0x7100898330
void Unk_23b8078::vf1() {
    field_d9 = 1;
}

// 0x7100898d20
void Unk_23b8078::vf2() {}

// 0x7100898d30
void Unk_23b8078::vf3() {}

// 0x7100898350
void Unk_23b8078::vf4() {
    field_d9 = 0;
}

// 0x7100898370
void Unk_23b8078::vf5() {
    field_d9 = 1;
}

// 0x7100898d40
void Unk_23b8078::vf6() {}

// 0x7100898d50
void Unk_23b8078::vf7() {}

class Unk_23b80f0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

// 0x7100898d70
void Unk_23b80f0::vf1() {}
