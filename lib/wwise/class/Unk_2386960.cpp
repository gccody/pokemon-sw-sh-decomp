// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u32 Unk_2381488;
struct Unk_403b80 {
    u8 _0[0x58];
    u32 field_58;
    u8 _5c[0x54];
    u64 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_403b80, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_403b80, field_b0, 0xb0);

void Unk_304740(u32, u64);

class Unk_2386960 {
public:
    void vf3();
    u32 vf21();
};

// 0x7100403b80
void Unk_2386960::vf3() {
    Unk_403b80* self = reinterpret_cast<Unk_403b80*>(this);
    if (self->field_b0 != 0) {
        Unk_304740(Unk_2381488, self->field_b0);
        self->field_58 = 0;
        self->field_b0 = 0;
    }
}

// 0x7100403ff0
u32 Unk_2386960::vf21() {
    return 1;
}
