// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3b77a0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3b77a0, field_10, 0x10);

class Unk_2383770 {
public:
    u32 vf3();
};

// 0x71003b77a0
u32 Unk_2383770::vf3() {
    Unk_3b77a0* self = reinterpret_cast<Unk_3b77a0*>(this);
    u32 v0 = self->field_10;
    self->field_10 = v0 + 1;
    return v0 + 1;
}
