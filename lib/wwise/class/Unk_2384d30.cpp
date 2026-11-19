// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dd7a0 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_3dd7a0, field_98, 0x98);

struct Unk_3dd740 {
    u8 _0[0xe8];
    u32 field_e8;
};
PKMN_OFFSET_ASSERT(Unk_3dd740, field_e8, 0xe8);

class Unk_2384d30 {
public:
    u64 vf16();
    u32 vf17();
};

// 0x71003dd740
u32 Unk_2384d30::vf17() {
    const Unk_3dd740* self = reinterpret_cast<const Unk_3dd740*>(this);
    return self->field_e8;
}

// 0x71003dd7a0
u64 Unk_2384d30::vf16() {
    const Unk_3dd7a0* self = reinterpret_cast<const Unk_3dd7a0*>(this);
    return self->field_98;
}
