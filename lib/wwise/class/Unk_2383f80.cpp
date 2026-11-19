// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3cbce0 {
    u8 _0[0x54];
    u16 field_54;
};
PKMN_OFFSET_ASSERT(Unk_3cbce0, field_54, 0x54);

struct Unk_3cbe50_18 {
    u8 _0[0x208];
    u32 field_208;
};
PKMN_OFFSET_ASSERT(Unk_3cbe50_18, field_208, 0x208);

struct Unk_3cbe50 {
    u8 _0[0x18];
    Unk_3cbe50_18* field_18;
};
PKMN_OFFSET_ASSERT(Unk_3cbe50, field_18, 0x18);

class Unk_2383f80 {
public:
    u32 vf14();
    u32 vf28();
};

// 0x71003cbce0
u32 Unk_2383f80::vf14() {
    Unk_3cbce0* self = reinterpret_cast<Unk_3cbce0*>(this);
    self->field_54 = 1;
    return 1;
}

// 0x71003cbe50
u32 Unk_2383f80::vf28() {
    const Unk_3cbe50* self = reinterpret_cast<const Unk_3cbe50*>(this);
    return self->field_18->field_208;
}
