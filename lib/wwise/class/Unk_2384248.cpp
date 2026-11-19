// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3d6140 {
    u8 _0[0x8];
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3d6140, field_8, 0x8);

class Unk_2384248 {
public:
    void vf2();
    void vf9(u64 value);
};

// 0x71003d1370
void Unk_2384248::vf2() {
}

// 0x71003d6140
void Unk_2384248::vf9(u64 value) {
    Unk_3d6140* self = reinterpret_cast<Unk_3d6140*>(this);
    self->field_8 = value;
}
