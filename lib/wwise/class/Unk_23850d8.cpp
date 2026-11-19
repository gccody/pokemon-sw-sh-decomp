// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

extern u32 Unk_2381488;
struct Unk_3deae0 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_3deae0, field_68, 0x68);

void Unk_304740(u32, u64);

class Unk_23850d8 {
public:
    void vf3();
    u32 vf21();
};

// 0x71003dea80
u32 Unk_23850d8::vf21() {
    return 1;
}

// 0x71003deae0
void Unk_23850d8::vf3() {
    Unk_3deae0* self = reinterpret_cast<Unk_3deae0*>(this);
    if (self->field_68 != 0) {
        Unk_304740(Unk_2381488, self->field_68);
        self->field_68 = 0;
    }
}
