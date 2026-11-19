// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_362730 {
    u8 _0[0x10];
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_362730, field_10, 0x10);

class Unk_2380888 {
public:
    u32 vf2();
    void vf3();
    u64 vf16();
};

// 0x71003626f0
u32 Unk_2380888::vf2() {
    return 1;
}

// 0x7100362700
void Unk_2380888::vf3() {
}

// 0x7100362730
u64 Unk_2380888::vf16() {
    const Unk_362730* self = reinterpret_cast<const Unk_362730*>(this);
    return self->field_10;
}
