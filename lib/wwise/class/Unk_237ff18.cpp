// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3517f0 {
    u8 _0[0x154];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_3517f0, field_154, 0x154);

struct Unk_351800 {
    u8 _0[0x154];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_351800, field_154, 0x154);

struct Unk_34fa30 {
    u8 _0[0x154];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_34fa30, field_154, 0x154);

class Unk_237ff18 {
public:
    void vf3();
    void vf4();
    u64 vf5();
    void vf10();
    void vf11();
    void vf13();
};

// 0x710034fa20
void Unk_237ff18::vf10() {
}

// 0x710034fa30
void Unk_237ff18::vf11() {
    Unk_34fa30* self = reinterpret_cast<Unk_34fa30*>(this);
    self->field_154 = self->field_154 & 0xfffffdff;
}

// 0x71003517f0
void Unk_237ff18::vf3() {
    Unk_3517f0* self = reinterpret_cast<Unk_3517f0*>(this);
    self->field_154 = self->field_154 & 0xffffffdf;
}

// 0x7100351800
void Unk_237ff18::vf4() {
    Unk_351800* self = reinterpret_cast<Unk_351800*>(this);
    self->field_154 = self->field_154 & 0xffffffdf;
}

// 0x7100351810
u64 Unk_237ff18::vf5() {
    return 0x1ffbfe3fffe60bd;
}

// 0x7100351830
void Unk_237ff18::vf13() {
}
