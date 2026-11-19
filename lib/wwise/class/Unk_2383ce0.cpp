// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3c4240 {
    u8 _0[0x58];
    u64 field_58;
};
PKMN_OFFSET_ASSERT(Unk_3c4240, field_58, 0x58);

class Unk_2383ce0 {
public:
    u64 vf6();
};

// 0x71003c4240
u64 Unk_2383ce0::vf6() {
    const Unk_3c4240* self = reinterpret_cast<const Unk_3c4240*>(this);
    return self->field_58;
}
