// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3fe070 {
    u8 _0[0x20];
    u64 field_20;
};
PKMN_OFFSET_ASSERT(Unk_3fe070, field_20, 0x20);

struct Unk_3fb700 {
    u8 _0[0x60];
    u32 field_60;
};
PKMN_OFFSET_ASSERT(Unk_3fb700, field_60, 0x60);

struct Unk_3fbcd0 {
    u8 _0[0xa8];
    u32 field_a8;
};
PKMN_OFFSET_ASSERT(Unk_3fbcd0, field_a8, 0xa8);

struct Unk_3fbce0 {
    u8 _0[0x38];
    u32 field_38;
};
PKMN_OFFSET_ASSERT(Unk_3fbce0, field_38, 0x38);

class Unk_2385ba8 {
public:
    u64 vf15();
    u32 vf17();
    u32 vf23();
    u32 vf13();
};

// 0x71003fb700
u32 Unk_2385ba8::vf17() {
    const Unk_3fb700* self = reinterpret_cast<const Unk_3fb700*>(this);
    return self->field_60;
}

// 0x71003fbcd0
u32 Unk_2385ba8::vf23() {
    const Unk_3fbcd0* self = reinterpret_cast<const Unk_3fbcd0*>(this);
    return self->field_a8;
}

// 0x71003fbce0
u32 Unk_2385ba8::vf13() {
    const Unk_3fbce0* self = reinterpret_cast<const Unk_3fbce0*>(this);
    return self->field_38;
}

// 0x71003fe070
u64 Unk_2385ba8::vf15() {
    const Unk_3fe070* self = reinterpret_cast<const Unk_3fe070*>(this);
    return self->field_20;
}
