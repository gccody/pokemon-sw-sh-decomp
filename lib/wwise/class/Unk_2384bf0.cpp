// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dccd0 {
    u8 _0[0x98];
    u64 field_98;
};
PKMN_OFFSET_ASSERT(Unk_3dccd0, field_98, 0x98);

struct Unk_3dcc30 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_3dcc30, field_a8, 0xa8);

class Unk_2384bf0 {
public:
    void vf2();
    u32 vf13();
    u64 vf16();
    u32 vf17();
};

// 0x71003dcc30
u32 Unk_2384bf0::vf17() {
    const Unk_3dcc30* self = reinterpret_cast<const Unk_3dcc30*>(this);
    return self->field_a8;
}

// 0x71003dccc0
u32 Unk_2384bf0::vf13() {
    return 0;
}

// 0x71003dccd0
u64 Unk_2384bf0::vf16() {
    const Unk_3dccd0* self = reinterpret_cast<const Unk_3dccd0*>(this);
    return self->field_98;
}

// 0x7100404530
void Unk_2384bf0::vf2() {
}
