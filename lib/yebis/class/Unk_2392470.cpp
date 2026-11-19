// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_510cf0 {
    u8 _0[0xe0];
    u8 field_e0;
};
PKMN_OFFSET_ASSERT(Unk_510cf0, field_e0, 0xe0);

class Unk_2392470 {
public:
    const u8* vf2();
};

// 0x7100510cf0
const u8* Unk_2392470::vf2() {
    const Unk_510cf0* self = reinterpret_cast<const Unk_510cf0*>(this);
    return &self->field_e0;
}
