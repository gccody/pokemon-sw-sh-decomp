// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_596680_0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
};

struct Unk_596680 {
    Unk_596680_0* field_0;
    u8 field_8;
};
PKMN_OFFSET_ASSERT(Unk_596680, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_596680, field_8, 0x8);

// 0x7100596680
void Unk_596680_call(Unk_596680* self) {
    if (self->field_8 != 0) {
        self->field_0->vf3();
        self->field_8 = 0;
    }
}
