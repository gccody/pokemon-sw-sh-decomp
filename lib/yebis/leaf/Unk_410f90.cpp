// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_410f90 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_410f90, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_410f90, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_410f90, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_410f90, field_18, 0x18);
void Unk_410960();

// 0x7100410f90
void Unk_410f90_set(Unk_410f90* self, u32 value) {
    if (value != 0x19) {
        if (value == 0xffffffff) {
            self->field_10 = 0;
            self->field_18 = 0;
            self->field_0 = 0;
            self->field_8 = 0;
            return;
        }
        Unk_410960();
        return;
    }
    self->field_10 = 0;
    self->field_18 = 0;
    self->field_0 = 0;
    self->field_8 = 0;
}

void Unk_412d20();
void Unk_412ed0();

// 0x7100413160
void Unk_413160_call(void* /*unused*/, u64 /*unused*/, u64 /*unused*/, u64 /*unused*/, u64 /*unused*/, u32 arg5) {
    if (arg5 != 0) {
        Unk_412ed0();
        return;
    }
    Unk_412d20();
}
