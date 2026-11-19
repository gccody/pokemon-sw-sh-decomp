// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3235f0_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3235f0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3235f0_arg1, field_8, 0x8);

class Unk_237e160 {
public:
    u32 vf4(Unk_3235f0_arg1* value);
    u32 vf9();
};

// 0x71003235f0
u32 Unk_237e160::vf4(Unk_3235f0_arg1* value) {
    value->field_0 = 0x7e10200000003;
    value->field_8 = 1;
    return 1;
}

// 0x7100328380
u32 Unk_237e160::vf9() {
    return 0x2d;
}
