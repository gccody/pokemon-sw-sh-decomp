// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_10a5580 {
    u8 _0[0xc];
    u32 field_c;
};
PKMN_OFFSET_ASSERT(Unk_10a5580, field_c, 0xc);

struct Unk_10a5590 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_10a5590, field_10, 0x10);

class Unk_2410b88 {
public:
    u32 vf2();
    u32 vf3();
};

// 0x71010a5580
u32 Unk_2410b88::vf2() {
    const Unk_10a5580* self = reinterpret_cast<const Unk_10a5580*>(this);
    return self->field_c;
}

// 0x71010a5590
u32 Unk_2410b88::vf3() {
    const Unk_10a5590* self = reinterpret_cast<const Unk_10a5590*>(this);
    return self->field_10;
}
