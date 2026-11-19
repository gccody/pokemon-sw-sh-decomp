// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_374470 {
    u8 _0[0x80];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_374470, field_80, 0x80);

class Unk_2381968 {
public:
    const u8* vf3();
};

// 0x7100374470
const u8* Unk_2381968::vf3() {
    const Unk_374470* self = reinterpret_cast<const Unk_374470*>(this);
    return &self->field_80;
}
