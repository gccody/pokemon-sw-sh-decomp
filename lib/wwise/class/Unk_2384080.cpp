// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3cc950 {
    u8 _0[0x10];
    u64 field_10;
    u8 _18[0x6a];
    u8 field_82;
};
PKMN_OFFSET_ASSERT(Unk_3cc950, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3cc950, field_82, 0x82);

class Unk_2384080 {
public:
    u32 vf21();
    u32 vf24();
};

// 0x71003cc920
u32 Unk_2384080::vf21() {
    return 1;
}

// 0x71003cc950
u32 Unk_2384080::vf24() {
    const Unk_3cc950* self = reinterpret_cast<const Unk_3cc950*>(this);
    if (self->field_10 == 0) {
        return 0;
    }
    return (self->field_82 >> 4) & 1;
}
