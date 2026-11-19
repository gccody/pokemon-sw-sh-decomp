// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_102b0b0(void* self);
void Unk_102bda0(void* self);

// Lifted through their own placeholder structs (cast_member).
struct Unk_102a890_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_102a890 {
    virtual void vf0();
    Unk_102a890_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_102a890, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_102a890, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_102a890, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_102a890, field_20, 0x20);

struct Unk_102b5c0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_102b5c0 {
    virtual void vf0();
    Unk_102b5c0_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_102b5c0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_102b5c0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_102b5c0, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_102b5c0, field_20, 0x20);

class Unk_24091f8 {
public:
    virtual ~Unk_24091f8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710102a890
void Unk_24091f8::vf3() {
    Unk_102a890* self = reinterpret_cast<Unk_102a890*>(this);
    Unk_102a890_8* v0 = self->field_8;
    u64 v1 = self->field_10;
    u64 v2 = self->field_18;
    u64 v3 = self->field_20;
    self->vf0();
    v0->vf3(v1, v2, v3);
}

class Unk_2409238 {
public:
    virtual ~Unk_2409238();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102b030
void Unk_2409238::vf5() {
    Unk_102b0b0(this);
}

class Unk_2409290 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102b040
void Unk_2409290::vf0() {
    Unk_102b0b0(this);
}

class Unk_2409398 {
public:
    virtual ~Unk_2409398();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710102b5c0
void Unk_2409398::vf3() {
    Unk_102b5c0* self = reinterpret_cast<Unk_102b5c0*>(this);
    Unk_102b5c0_8* v0 = self->field_8;
    u64 v1 = self->field_10;
    u64 v2 = self->field_18;
    u64 v3 = self->field_20;
    self->vf0();
    v0->vf3(v1, v2, v3);
}

class Unk_24093d8 {
public:
    virtual ~Unk_24093d8();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102bd20
void Unk_24093d8::vf5() {
    Unk_102bda0(this);
}

class Unk_2409430 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102bd30
void Unk_2409430::vf0() {
    Unk_102bda0(this);
}
