// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_32ba00 {
    u8 _0[0x10];
    u32 field_10;
    u8 _14[0x6];
    u16 field_1a;
};
PKMN_OFFSET_ASSERT(Unk_32ba00, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_32ba00, field_1a, 0x1a);

struct Unk_32ba10_arg1 {
    u64 field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_32ba10_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_32ba10_arg1, field_8, 0x8);

struct Unk_32bb60 {
    u8 _0[0x18];
    u16 field_18;
};
PKMN_OFFSET_ASSERT(Unk_32bb60, field_18, 0x18);

class Unk_237e750 {
public:
    u32 vf3();
    u32 vf4(Unk_32ba10_arg1* value);
    u32 vf10();
};

// 0x710032ba00
u32 Unk_237e750::vf3() {
    Unk_32ba00* self = reinterpret_cast<Unk_32ba00*>(this);
    self->field_10 = 0;
    self->field_1a = 0;
    return 1;
}

// 0x710032ba10
u32 Unk_237e750::vf4(Unk_32ba10_arg1* value) {
    value->field_0 = 0x7e10200000002;
    value->field_8 = 1;
    return 1;
}

// 0x710032bb60
u32 Unk_237e750::vf10() {
    Unk_32bb60* self = reinterpret_cast<Unk_32bb60*>(this);
    self->field_18 = 1;
    return 1;
}
