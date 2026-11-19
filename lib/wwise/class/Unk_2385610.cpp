// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3e0cb0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_3e0cb0 {
    u8 _0[0x8];
    Unk_3e0cb0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_3e0cb0, field_8, 0x8);

struct Unk_3e0cd0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64);
};

struct Unk_3e0cd0 {
    u8 _0[0x8];
    Unk_3e0cd0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_3e0cd0, field_8, 0x8);

struct Unk_3e0ce0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u64);
};

struct Unk_3e0ce0 {
    u8 _0[0x8];
    Unk_3e0ce0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_3e0ce0, field_8, 0x8);

class Unk_2385610 {
public:
    void vf2();
    void vf3();
    void vf4(u64 value);
    void vf5(u64 value);
};

// 0x71003e0ca0
void Unk_2385610::vf2() {
}

// 0x71003e0cb0
void Unk_2385610::vf3() {
    const Unk_3e0cb0* self = reinterpret_cast<const Unk_3e0cb0*>(this);
    if (self->field_8 != nullptr) {
        self->field_8->vf3();
    }
}

// 0x71003e0cd0
void Unk_2385610::vf4(u64 value) {
    const Unk_3e0cd0* self = reinterpret_cast<const Unk_3e0cd0*>(this);
    self->field_8->vf4(value);
}

// 0x71003e0ce0
void Unk_2385610::vf5(u64 value) {
    const Unk_3e0ce0* self = reinterpret_cast<const Unk_3e0ce0*>(this);
    if (self->field_8 != nullptr) {
        self->field_8->vf5(value);
    }
}
