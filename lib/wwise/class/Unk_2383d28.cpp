// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3c9080_148 {
    u8 _0[0x164];
    u8 field_164;
};
PKMN_OFFSET_ASSERT(Unk_3c9080_148, field_164, 0x164);

struct Unk_3c9080 {
    u8 _0[0x148];
    Unk_3c9080_148* field_148;
    u8 _150[0x4];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_3c9080, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_3c9080, field_154, 0x154);

struct Unk_3c90a0_148 {
    u8 _0[0x164];
    u8 field_164;
};
PKMN_OFFSET_ASSERT(Unk_3c90a0_148, field_164, 0x164);

struct Unk_3c90a0 {
    u8 _0[0x148];
    Unk_3c90a0_148* field_148;
    u8 _150[0x4];
    u16 field_154;
};
PKMN_OFFSET_ASSERT(Unk_3c90a0, field_148, 0x148);
PKMN_OFFSET_ASSERT(Unk_3c90a0, field_154, 0x154);

class Unk_2383d28 {
public:
    void vf3();
    void vf4();
    u64 vf5();
};

// 0x71003c9070
u64 Unk_2383d28::vf5() {
    return 0x7fbf8ffffc4020;
}

// 0x71003c9080
void Unk_2383d28::vf3() {
    Unk_3c9080* self = reinterpret_cast<Unk_3c9080*>(this);
    self->field_154 = self->field_154 & 0xffffffdf;
    self->field_148->field_164 = self->field_148->field_164 | 0x30;
}

// 0x71003c90a0
void Unk_2383d28::vf4() {
    Unk_3c90a0* self = reinterpret_cast<Unk_3c90a0*>(this);
    self->field_154 = self->field_154 & 0xffffffdf;
    self->field_148->field_164 = self->field_148->field_164 | 0x30;
}
