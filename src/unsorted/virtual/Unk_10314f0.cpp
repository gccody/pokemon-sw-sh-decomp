// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_1034d10(void* self);

// Tail-called by lifted functions. Placeholders, like the forwarders' callees.
void Unk_104bf60(u64);

// Globals other TUs define, named after their addresses.
extern u64 Unk_24ba150;

// Lifted through their own placeholder structs (cast_member).
struct Unk_1031650 {
    u8 _0[0x4c];
    u8 field_4c;
};
PKMN_OFFSET_ASSERT(Unk_1031650, field_4c, 0x4c);

struct Unk_1031670 {
    u8 _0[0x44];
    u8 field_44;
};
PKMN_OFFSET_ASSERT(Unk_1031670, field_44, 0x44);

struct Unk_1034520_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_1034520 {
    virtual void vf0();
    Unk_1034520_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_1034520, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1034520, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1034520, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1034520, field_20, 0x20);

class Unk_24096c8 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(u32 value);
};

// 0x71010314f0
void Unk_24096c8::vf4() {
    Unk_104bf60(Unk_24ba150);
}

// 0x7101031510
void Unk_24096c8::vf5() {}

// 0x7101031650
void Unk_24096c8::vf6(u32 value) {
    Unk_1031650* self = reinterpret_cast<Unk_1031650*>(this);
    if ((value & 0xffff) != 0) {
        return;
    }
    self->field_4c = 1;
}

class Unk_2409710 {
public:
    virtual void vf0(u32 value);
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

// 0x7101031670
void Unk_2409710::vf0(u32 value) {
    Unk_1031670* self = reinterpret_cast<Unk_1031670*>(this);
    if ((value & 0xffff) != 0) {
        return;
    }
    self->field_44 = 1;
}

// 0x7101031ab0
void Unk_2409710::vf1() {}

// 0x7101031ac0
void Unk_2409710::vf2() {}

// 0x7101031ad0
void Unk_2409710::vf3() {}

// 0x7101031500
void Unk_2409710::vf4() {
    Unk_104bf60(Unk_24ba150);
}

// 0x7101031520
void Unk_2409710::vf5() {}

// 0x7101031ae0
void Unk_2409710::vf6() {}

// 0x7101031af0
void Unk_2409710::vf7() {}

class Unk_2409be8 {
public:
    virtual ~Unk_2409be8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x7101034520
void Unk_2409be8::vf3() {
    Unk_1034520* self = reinterpret_cast<Unk_1034520*>(this);
    Unk_1034520_8* v0 = self->field_8;
    u64 v1 = self->field_10;
    u64 v2 = self->field_18;
    u64 v3 = self->field_20;
    self->vf0();
    v0->vf3(v1, v2, v3);
}

class Unk_2409c28 {
public:
    virtual ~Unk_2409c28();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x7101034c90
void Unk_2409c28::vf5() {
    Unk_1034d10(this);
}

class Unk_2409c80 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x7101034ca0
void Unk_2409c80::vf0() {
    Unk_1034d10(this);
}
