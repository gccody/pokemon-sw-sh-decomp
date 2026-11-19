// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_34c210 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_34c210, field_10, 0x10);

class Unk_237bca0 {
public:
    u32 vf4();
    u32 vf17();
    u64 vf16();
};

// 0x7100307ed0
u32 Unk_237bca0::vf17() {
    return 8;
}

// 0x710030a910
u32 Unk_237bca0::vf4() {
    return 9;
}

// 0x710034c210
u64 Unk_237bca0::vf16() {
    const Unk_34c210* self = reinterpret_cast<const Unk_34c210*>(this);
    return self->field_10;
}
