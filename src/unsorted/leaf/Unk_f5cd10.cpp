// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_f5cd10 {
    u8 _0[0x90];
    u64 field_90;
};
PKMN_OFFSET_ASSERT(Unk_f5cd10, field_90, 0x90);

void Unk_67bfa0(u64);

// 0x7100f5cd10
void Unk_f5cd10_call(const Unk_f5cd10* self) {
    Unk_67bfa0(self->field_90);
}

struct Unk_f5cd20 {
    u8 _0[0x70];
    u8 field_70;
    u8 _71[0x3];
    u32 field_74;
    u8 field_78;
};
PKMN_OFFSET_ASSERT(Unk_f5cd20, field_70, 0x70);
PKMN_OFFSET_ASSERT(Unk_f5cd20, field_74, 0x74);
PKMN_OFFSET_ASSERT(Unk_f5cd20, field_78, 0x78);

// 0x7100f5cd20
void Unk_f5cd20_update(Unk_f5cd20* self) {
    if (self->field_70 != 0) {
        return;
    }
    if (self->field_78 != 0) {
        self->field_78 = 0;
        self->field_74 = 0;
        self->field_70 = 1;
        return;
    }
    self->field_74 = 0;
    self->field_70 = 1;
}
