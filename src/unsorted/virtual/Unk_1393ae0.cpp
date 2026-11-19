// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Lifted through their own placeholder structs (cast_member).
struct Unk_1393ae0 {
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
    u8 _8[0x58];
    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    u64 field_80;
    u64 field_88;
    u64 field_90;
    u64 field_98;
    u64 field_a0;
    u64 field_a8;
    u64 field_b0;
    u64 field_b8;
    u64 field_c0;
    u64 field_c8;
    u64 field_d0;
    u64 field_d8;
    u64 field_e0;
    u64 field_e8;
    u64 field_f0;
    u64 field_f8;
    u64 field_100;
    u64 field_108;
    u64 field_110;
    u64 field_118;
    u16 field_120;
};
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_60, 0x60);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_78, 0x78);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_80, 0x80);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_88, 0x88);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_a8, 0xa8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_b0, 0xb0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_b8, 0xb8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_c0, 0xc0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_c8, 0xc8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_d0, 0xd0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_d8, 0xd8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_e0, 0xe0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_e8, 0xe8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_f0, 0xf0);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_f8, 0xf8);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_100, 0x100);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_108, 0x108);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_110, 0x110);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_118, 0x118);
PKMN_OFFSET_ASSERT(Unk_1393ae0, field_120, 0x120);

class Unk_2433278 {
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

// 0x7101393ae0
void Unk_2433278::vf7() {
    Unk_1393ae0* self = reinterpret_cast<Unk_1393ae0*>(this);
    self->field_120 = 0x101;
    self->field_110 = 0x101010101010101;
    self->field_118 = 0x101010101010101;
    self->field_100 = 0x101010101010101;
    self->field_108 = 0x101010101010101;
    self->field_f0 = 0x101010101010101;
    self->field_f8 = 0x101010101010101;
    self->field_e0 = 0x101010101010101;
    self->field_e8 = 0x101010101010101;
    self->field_d0 = 0x101010101010101;
    self->field_d8 = 0x101010101010101;
    self->field_c0 = 0x101010101010101;
    self->field_c8 = 0x101010101010101;
    self->field_b0 = 0x101010101010101;
    self->field_b8 = 0x101010101010101;
    self->field_a0 = 0x101010101010101;
    self->field_a8 = 0x101010101010101;
    self->field_90 = 0x101010101010101;
    self->field_98 = 0x101010101010101;
    self->field_80 = 0x101010101010101;
    self->field_88 = 0x101010101010101;
    self->field_70 = 0x101010101010101;
    self->field_78 = 0x101010101010101;
    self->field_60 = 0x101010101010101;
    self->field_68 = 0x101010101010101;
    self->vf9();
}

class Unk_2433448 {
public:
    virtual ~Unk_2433448();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2433448, field_8, 0x8);

// 0x7101399690, 0x710139a8f0
Unk_2433448::~Unk_2433448() {}

// 0x710139a900
u8* Unk_2433448::vf2() {
    return &field_8;
}

// 0x710139a910
u8* Unk_2433448::vf3() {
    return &field_8;
}

class Unk_2433528 {
public:
    virtual ~Unk_2433528();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_2433528, field_8, 0x8);

// 0x7101399d20, 0x710139cf50
Unk_2433528::~Unk_2433528() {}

// 0x710139cf60
u8* Unk_2433528::vf2() {
    return &field_8;
}

// 0x710139cf70
u8* Unk_2433528::vf3() {
    return &field_8;
}

class Unk_24334b8 {
public:
    virtual ~Unk_24334b8();
    virtual u8* vf2();
    virtual u8* vf3();
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_24334b8, field_8, 0x8);

// 0x710139ad30, 0x710139c7f0
Unk_24334b8::~Unk_24334b8() {}

// 0x710139c800
u8* Unk_24334b8::vf2() {
    return &field_8;
}

// 0x710139c810
u8* Unk_24334b8::vf3() {
    return &field_8;
}
