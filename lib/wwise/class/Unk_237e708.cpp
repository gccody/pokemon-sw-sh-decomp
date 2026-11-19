// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_32b850_arg1 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
};
PKMN_OFFSET_ASSERT(Unk_32b850_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_32b850_arg1, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_32b850_arg1, field_8, 0x8);

struct Unk_32b850 {
    u8 _0[0x8];
    u32 field_8;
    u32 field_c;
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_32b850, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_32b850, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_32b850, field_10, 0x10);

class Unk_237e708 {
public:
    u32 vf6(const Unk_32b850_arg1* value);
};

// 0x710032b850
u32 Unk_237e708::vf6(const Unk_32b850_arg1* value) {
    Unk_32b850* self = reinterpret_cast<Unk_32b850*>(this);
    self->field_8 = value->field_0;
    self->field_c = value->field_4;
    self->field_10 = value->field_8;
    return 1;
}
