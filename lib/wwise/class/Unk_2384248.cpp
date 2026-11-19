// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3d1380_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_3d1380 {
    u8 _0[0x8];
    Unk_3d1380_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_3d1380, field_8, 0x8);

struct Unk_3d13a0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(u64);
};

struct Unk_3d13a0 {
    u8 _0[0x8];
    Unk_3d13a0_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_3d13a0, field_8, 0x8);

struct Unk_3d6140 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3d6140, field_8, 0x8);

class Unk_2384248 {
public:
    void vf2();
    void vf3();
    void vf4(u64 value);
    void vf9(u64 value);
};

// 0x71003d1370
void Unk_2384248::vf2() {
}

// 0x71003d1380
void Unk_2384248::vf3() {
    const Unk_3d1380* self = reinterpret_cast<const Unk_3d1380*>(this);
    if (self->field_8 != nullptr) {
        self->field_8->vf3();
    }
}

// 0x71003d13a0
void Unk_2384248::vf4(u64 value) {
    const Unk_3d13a0* self = reinterpret_cast<const Unk_3d13a0*>(this);
    self->field_8->vf4(value);
}

// 0x71003d6140
void Unk_2384248::vf9(u64 value) {
    Unk_3d6140* self = reinterpret_cast<Unk_3d6140*>(this);
    self->field_8 = value;
}
