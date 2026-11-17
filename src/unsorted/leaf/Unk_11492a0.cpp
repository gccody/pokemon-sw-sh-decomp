// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_11492a0 {
    u8 _0[0x70];
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_11492a0, field_70, 0x70);

// 0x71011492a0
void Unk_11492a0_setField70(Unk_11492a0* self, u64 value) {
    self->field_70 = value;
}

struct Unk_11492b0 {
    u8 _0[0x68];
    u64 field_68;
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_11492b0, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_11492b0, field_70, 0x70);

void Unk_11492d0(u64);

// 0x71011492b0
void Unk_11492b0_call(const Unk_11492b0* self) {
    if (self->field_70 != 0) {
        Unk_11492d0(self->field_68);
    }
}

struct Unk_1149550 {
    u8 _0[0x68];
    u64 field_68;
    u64 field_70;
};
PKMN_OFFSET_ASSERT(Unk_1149550, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_1149550, field_70, 0x70);

void Unk_1149570(u64);

// 0x7101149550
void Unk_1149550_call(const Unk_1149550* self) {
    if (self->field_70 != 0) {
        Unk_1149570(self->field_68);
    }
}
