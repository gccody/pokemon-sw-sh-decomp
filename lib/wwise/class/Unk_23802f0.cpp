// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_357950 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_357950, field_a8, 0xa8);

class Unk_23802f0 {
public:
    u32 vf71();
};

// 0x7100357950
u32 Unk_23802f0::vf71() {
    const Unk_357950* self = reinterpret_cast<const Unk_357950*>(this);
    return self->field_a8;
}
