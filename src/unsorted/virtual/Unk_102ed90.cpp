// Scope: common
// Simple virtual functions between two static initialisers (one or more TUs).
// Placeholder classes, named after their vtables (Unk_<_ZTV address>): rename
// them, and give the functions real signatures, once the classes are known.
#include <types.h>

// Called by forwarders. Placeholders: their real signatures aren't known.
void Unk_102f5b0(void* self);

// Lifted through their own placeholder structs (cast_member).
struct Unk_102ed90_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u64);
};

struct Unk_102ed90 {
    virtual void vf0();
    Unk_102ed90_8* field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_102ed90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_102ed90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_102ed90, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_102ed90, field_20, 0x20);

class Unk_2409608 {
public:
    virtual ~Unk_2409608();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
};

// 0x710102ed90
void Unk_2409608::vf3() {
    Unk_102ed90* self = reinterpret_cast<Unk_102ed90*>(this);
    Unk_102ed90_8* v0 = self->field_8;
    u64 v1 = self->field_10;
    u64 v2 = self->field_18;
    u64 v3 = self->field_20;
    self->vf0();
    v0->vf3(v1, v2, v3);
}

class Unk_2409648 {
public:
    virtual ~Unk_2409648();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
};

// 0x710102f530
void Unk_2409648::vf5() {
    Unk_102f5b0(this);
}

class Unk_24096a0 {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
};

// 0x710102f540
void Unk_24096a0::vf0() {
    Unk_102f5b0(this);
}
