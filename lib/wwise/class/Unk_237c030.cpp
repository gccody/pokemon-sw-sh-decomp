// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_309070 {
    u8 _0[0x48];
    u32 field_48;
};
PKMN_OFFSET_ASSERT(Unk_309070, field_48, 0x48);

struct Unk_308d10 {
    u8 _0[0x5a];
    u8 field_5a;
};
PKMN_OFFSET_ASSERT(Unk_308d10, field_5a, 0x5a);

struct Unk_308e90 {
    u8 _0[0x5a];
    u8 field_5a;
};
PKMN_OFFSET_ASSERT(Unk_308e90, field_5a, 0x5a);

class Unk_237c030 {
public:
    void vf8();
    void vf13();
    void vf14();
    void vf15();
};

// 0x7100308d10
void Unk_237c030::vf13() {
    Unk_308d10* self = reinterpret_cast<Unk_308d10*>(this);
    self->field_5a = (self->field_5a & 0xf0) | 1;
}

// 0x7100308e90
void Unk_237c030::vf14() {
    Unk_308e90* self = reinterpret_cast<Unk_308e90*>(this);
    self->field_5a = (self->field_5a & 0xf0) | 4;
}

// 0x7100309070
void Unk_237c030::vf8() {
    Unk_309070* self = reinterpret_cast<Unk_309070*>(this);
    self->field_48 = self->field_48 + 1;
}

// 0x71003095d0
void Unk_237c030::vf15() {
}
