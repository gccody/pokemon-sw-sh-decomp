// Scope: common
// Small virtual functions of a library class (tools/leafgen.py members): placeholder
// member names vf<slot>, placeholder structs. The class's name is its RTTI's.
#include <types.h>

struct Unk_3dcce0_8 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(u32);
};
struct Unk_3dcce0 {
    u8 _0[0x8];
    Unk_3dcce0_8* field_8;
    u8 _10[0x78];
    u8 field_88;
};
PKMN_OFFSET_ASSERT(Unk_3dcce0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3dcce0, field_88, 0x88);

class Unk_2384c90 {
public:
    void vf5(u32 value);
};

// 0x71003dcce0
void Unk_2384c90::vf5(u32 value) {
    Unk_3dcce0* self = reinterpret_cast<Unk_3dcce0*>(this);
    if (value != 0) {
        if (self->field_88 != 0) {
            return;
        }
        self->field_8->vf5(value);
        return;
    }
    self->field_88 = 0;
    self->field_8->vf5(value);
}
