// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1046490_20 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(u64, u64, u32);
};
struct Unk_1046490 {
    u8 field_0;
    u8 _1[0x7];
    u64 field_8;
    u64 field_10;
    u64 field_18;
    Unk_1046490_20* field_20;
};
PKMN_OFFSET_ASSERT(Unk_1046490, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1046490, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_1046490, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_1046490, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_1046490, field_20, 0x20);

// 0x7101046490
void Unk_1046490_call(Unk_1046490* self) {
    if (self->field_0 != 0) {
        if (self->field_8 != 0) {
            self->field_10 = self->field_8;
            self->field_20->vf3(self->field_8, self->field_18 - self->field_8, 8);
            self->field_0 = 0;
            return;
        }
        self->field_0 = 0;
        return;
    }
}

void Unk_10466d0();

// 0x71010466c0
void Unk_10466c0_call(void* /*unused*/) {
    Unk_10466d0();
}
