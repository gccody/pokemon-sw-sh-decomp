// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_394f90 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_394f90, field_10, 0x10);

struct Unk_395210 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_395210, field_10, 0x10);

class Unk_2382a40 {
public:
    u32 vf2();
    u32 vf4();
    void vf8();
};

// 0x7100394f10
u32 Unk_2382a40::vf2() {
    return 1;
}

// 0x7100394f90
u32 Unk_2382a40::vf4() {
    const Unk_394f90* self = reinterpret_cast<const Unk_394f90*>(this);
    return self->field_10;
}

// 0x7100395210
void Unk_2382a40::vf8() {
    Unk_395210* self = reinterpret_cast<Unk_395210*>(this);
    self->field_10 = 0;
}
