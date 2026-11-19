// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3f57a0_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3f57a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3f57a0_arg1, field_8, 0x8);

class Unk_2385990 {
public:
    u32 vf4(Unk_3f57a0_arg1* value);
    u32 vf9();
};

// 0x71003f57a0
u32 Unk_2385990::vf4(Unk_3f57a0_arg1* value) {
    value->field_0 = 0x7e10200000003;
    value->field_8 = 1;
    return 1;
}

// 0x71003f5aa0
u32 Unk_2385990::vf9() {
    return 0x2d;
}
