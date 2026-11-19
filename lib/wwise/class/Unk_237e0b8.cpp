// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_31ff50_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_31ff50_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_31ff50_arg1, field_8, 0x8);

class Unk_237e0b8 {
public:
    u32 vf4(Unk_31ff50_arg1* value);
    u32 vf9();
};

// 0x710031ff50
u32 Unk_237e0b8::vf4(Unk_31ff50_arg1* value) {
    value->field_0 = 0x7e10200000003;
    value->field_8 = 1;
    return 1;
}

// 0x7100321ad0
u32 Unk_237e0b8::vf9() {
    return 0x2d;
}
