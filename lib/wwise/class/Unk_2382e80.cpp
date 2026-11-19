// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3a5bb0_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_3a5bb0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_3a5bb0_arg1, field_8, 0x8);

class Unk_2382e80 {
public:
    u32 vf3();
    u32 vf4(Unk_3a5bb0_arg1* value);
    u32 vf7();
};

// 0x71003a5b40
u32 Unk_2382e80::vf7() {
    return 0;
}

// 0x71003a5ba0
u32 Unk_2382e80::vf3() {
    return 1;
}

// 0x71003a5bb0
u32 Unk_2382e80::vf4(Unk_3a5bb0_arg1* value) {
    value->field_8 = 0;
    value->field_0 = 0x7e10200000007;
    return 1;
}
