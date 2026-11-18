// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101205500
void Unk_1205500_update() {}

struct Unk_1205510_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1205510_arg1, field_0, 0x0);

struct Unk_1205510 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1205510, field_0, 0x0);

// 0x7101205510
void Unk_1205510_set(const Unk_1205510* self, Unk_1205510_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1205520_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1205520_arg1, field_0, 0x0);

struct Unk_1205520 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1205520, field_0, 0x0);

// 0x7101205520
void Unk_1205520_set(const Unk_1205520* self, Unk_1205520_arg1* value) {
    value->field_0 = self->field_0;
}
