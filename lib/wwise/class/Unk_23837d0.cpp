// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3baa60 {
    u8 _0[0x9f];
    u8 field_9f;
};
PKMN_OFFSET_ASSERT(Unk_3baa60, field_9f, 0x9f);

class Unk_23837d0 {
public:
    u32 vf17();
    u32 vf76();
};

// 0x71003baa60
u32 Unk_23837d0::vf76() {
    const Unk_3baa60* self = reinterpret_cast<const Unk_3baa60*>(this);
    return (self->field_9f >> 5) & 1;
}

// 0x71003baa70
u32 Unk_23837d0::vf17() {
    return 4;
}
