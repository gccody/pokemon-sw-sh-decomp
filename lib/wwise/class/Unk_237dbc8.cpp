// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_31c000 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_31c000, field_90, 0x90);

class Unk_237dbc8 {
public:
    u64 vf22();
    u32 vf29();
};

// 0x710031c000
u64 Unk_237dbc8::vf22() {
    const Unk_31c000* self = reinterpret_cast<const Unk_31c000*>(this);
    return self->field_90;
}

// 0x710031c010
u32 Unk_237dbc8::vf29() {
    return 1;
}
