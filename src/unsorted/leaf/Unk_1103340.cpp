// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1103340_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340_arg1, field_0, 0x0);

struct Unk_1103340 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103340, field_0, 0x0);

// 0x7101103340
void Unk_1103340_set(Unk_1103340* self, Unk_1103340_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}

struct Unk_1103420_arg1 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420_arg1, field_8, 0x8);

struct Unk_1103420 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1103420, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1103420, field_8, 0x8);

// 0x7101103420
void Unk_1103420_set(Unk_1103420* self, Unk_1103420_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
    u64 v1 = self->field_8;
    self->field_8 = 0;
    value->field_8 = v1;
}

struct Unk_1103500_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500_arg1, field_0, 0x0);

struct Unk_1103500 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1103500, field_0, 0x0);

// 0x7101103500
void Unk_1103500_set(Unk_1103500* self, Unk_1103500_arg1* value) {
    u64 v0 = self->field_0;
    self->field_0 = 0;
    value->field_0 = v0;
}
