// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_303770_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_303770_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_303770_arg1, field_8, 0x8);

class Unk_237bbf8 {
public:
    u32 vf3();
    u32 vf4(Unk_303770_arg1* value);
    u32 vf5();
    u32 vf6();
    u32 vf9();
};

// 0x7100303760
u32 Unk_237bbf8::vf3() {
    return 1;
}

// 0x7100303770
u32 Unk_237bbf8::vf4(Unk_303770_arg1* value) {
    value->field_0 = 0x7e10200000003;
    value->field_8 = 1;
    return 1;
}

// 0x71003041f0
u32 Unk_237bbf8::vf9() {
    return 0x2d;
}

// 0x710032bbd0
u32 Unk_237bbf8::vf5() {
    return 0;
}

// 0x710032bbe0
u32 Unk_237bbf8::vf6() {
    return 0;
}
