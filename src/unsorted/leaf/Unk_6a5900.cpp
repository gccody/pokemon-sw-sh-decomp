// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6a5900_8 {
    virtual void vf0();
    virtual void vf1();
};

struct Unk_6a5900 {
    u8 _0[0x8];
    Unk_6a5900_8* field_8;
};
PKMN_OFFSET_ASSERT(Unk_6a5900, field_8, 0x8);

// 0x71006a5900
void Unk_6a5900_call(Unk_6a5900* self) {
    if (self->field_8 != nullptr) {
        self->field_8->vf1();
        self->field_8 = nullptr;
    }
}
