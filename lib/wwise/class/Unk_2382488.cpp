// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_35d3f0 {
    u8 _0[0x2b8];
    u32 field_2b8;
};
PKMN_OFFSET_ASSERT(Unk_35d3f0, field_2b8, 0x2b8);

class Unk_2382488 {
public:
    void vf6();
    void vf14();
    void vf15();
    void vf21();
    u32 vf16();
    u32 vf23();
};

// 0x710035d3f0
u32 Unk_2382488::vf23() {
    Unk_35d3f0* self = reinterpret_cast<Unk_35d3f0*>(this);
    u32 v0 = self->field_2b8;
    self->field_2b8 = 0xffffffff;
    return v0;
}

// 0x710038d240
void Unk_2382488::vf21() {
}

// 0x710038d250
void Unk_2382488::vf14() {
}

// 0x710038d260
void Unk_2382488::vf6() {
}

// 0x710038d270
void Unk_2382488::vf15() {
}

// 0x710038e010
u32 Unk_2382488::vf16() {
    return 0;
}
