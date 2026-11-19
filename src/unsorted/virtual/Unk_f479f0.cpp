// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_f48700(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_6d7ac0(u64, u64, u32);

// Lifted through their own placeholder structs (cast_member).
struct Unk_f479f0 {
    u8 _0[0xd4];
    u32 field_d4;
    u8 field_d8;
    u8 _d9[0x7];
    u32 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_f479f0, field_d4, 0xd4);
PKMN_OFFSET_ASSERT(Unk_f479f0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_f479f0, field_e0, 0xe0);

struct Unk_f47a20 {
    u8 _0[0x5c];
    u32 field_5c;
    u8 field_60;
    u8 _61[0x7];
    u32 field_68;
};
PKMN_OFFSET_ASSERT(Unk_f47a20, field_5c, 0x5c);
PKMN_OFFSET_ASSERT(Unk_f47a20, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_f47a20, field_68, 0x68);

struct Unk_23fda38_e8 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23fda38_e8, field_2a0, 0x2a0);

class Unk_23fda38 {
public:
    virtual ~Unk_23fda38();
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
    u8 _8[0xe0];
    Unk_23fda38_e8* field_e8;
    u8 _f0[0x8];
    u8 field_f8;
};
PKMN_OFFSET_ASSERT(Unk_23fda38, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_23fda38, field_f8, 0xf8);

// 0x7100f480e0
void Unk_23fda38::vf6() {
    Unk_f48700(this);
}

// 0x7100f479f0
void Unk_23fda38::vf11() {
    Unk_f479f0* self = reinterpret_cast<Unk_f479f0*>(this);
    if (self->field_e0 == 8) {
        self->field_e0 = 9;
        self->field_d8 = 0;
        return;
    }
    self->field_d4 = 0x14;
    self->field_d8 = 0;
}

// 0x7100f47ab0
void Unk_23fda38::vf13() {}

// 0x7100f47ad0
void Unk_23fda38::vf14() {
    field_f8 = 1;
}

// 0x7100f47af0
void Unk_23fda38::vf15(u64 /*unused*/, u64 arg2) {
    if (field_e8 != nullptr) {
        Unk_6d7ac0(field_e8->field_2a0, arg2, 1);
    }
}

class Unk_23fdb40 {
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
};

// 0x7100f47a20
void Unk_23fdb40::vf4() {
    Unk_f47a20* self = reinterpret_cast<Unk_f47a20*>(this);
    if (self->field_68 == 8) {
        self->field_68 = 9;
        self->field_60 = 0;
        return;
    }
    self->field_5c = 0x14;
    self->field_60 = 0;
}

class Unk_23fdba0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    u8 _8[0x70];
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_23fdba0, field_78, 0x78);

// 0x7100f47ac0
void Unk_23fdba0::vf0() {}

// 0x7100f47ae0
void Unk_23fdba0::vf1() {
    field_78 = 1;
}

struct Unk_23fdbf0_60 {
    u8 _0[0x2a0];
    u64 field_2a0;
};
PKMN_OFFSET_ASSERT(Unk_23fdbf0_60, field_2a0, 0x2a0);

class Unk_23fdbf0 {
public:
    virtual void vf0(u64 /*unused*/, u64 arg2);
    virtual void vf1();
    u8 _8[0x58];
    Unk_23fdbf0_60* field_60;
};
PKMN_OFFSET_ASSERT(Unk_23fdbf0, field_60, 0x60);

// 0x7100f47b10
void Unk_23fdbf0::vf0(u64 /*unused*/, u64 arg2) {
    if (field_60 != nullptr) {
        Unk_6d7ac0(field_60->field_2a0, arg2, 1);
    }
}

class Unk_23fdad8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7100f48110
void Unk_23fdad8::vf5() {
    Unk_f48700(this);
}

class Unk_23fdb18 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7100f48120
void Unk_23fdb18::vf0() {
    Unk_f48700(this);
}
