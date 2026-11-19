// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_395460 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_395460, field_10, 0x10);

struct Unk_3956a0 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_3956a0, field_10, 0x10);

class Unk_2382ac0 {
public:
    u32 vf2();
    u32 vf4();
    void vf8();
    u32 vf11();
    void vf12();
};

// 0x71003953e0
u32 Unk_2382ac0::vf2() {
    return 1;
}

// 0x7100395460
u32 Unk_2382ac0::vf4() {
    const Unk_395460* self = reinterpret_cast<const Unk_395460*>(this);
    return self->field_10;
}

// 0x71003956a0
void Unk_2382ac0::vf8() {
    Unk_3956a0* self = reinterpret_cast<Unk_3956a0*>(this);
    self->field_10 = 0;
}

// 0x71003956b0
void Unk_2382ac0::vf12() {
}

// 0x7100395780
u32 Unk_2382ac0::vf11() {
    return 0xc350;
}
