// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3de820 {
    u8 _0[0x82];
    u8 field_82;
};
PKMN_OFFSET_ASSERT(Unk_3de820, field_82, 0x82);

class Unk_2384fc0 {
public:
    u32 vf23();
};

// 0x71003de820
u32 Unk_2384fc0::vf23() {
    const Unk_3de820* self = reinterpret_cast<const Unk_3de820*>(this);
    return (self->field_82 >> 3) & 1;
}
