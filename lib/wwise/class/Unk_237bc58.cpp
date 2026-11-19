// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_304330_arg1 {
    u32 field_0;
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_304330_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_304330_arg1, field_4, 0x4);

struct Unk_304330 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_304330, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_304330, field_c, 0xc);

class Unk_237bc58 {
public:
    u32 vf6(const Unk_304330_arg1* value);
};

// 0x7100304330
u32 Unk_237bc58::vf6(const Unk_304330_arg1* value) {
    Unk_304330* self = reinterpret_cast<Unk_304330*>(this);
    self->field_8 = value->field_0;
    self->field_c = value->field_4;
    return 1;
}
