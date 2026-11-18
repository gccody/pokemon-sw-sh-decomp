// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710126ec40
void Unk_126ec40_update() {}

struct Unk_126ec50_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec50_arg1, field_0, 0x0);

struct Unk_126ec50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec50, field_0, 0x0);

// 0x710126ec50
void Unk_126ec50_set(const Unk_126ec50* self, Unk_126ec50_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_126ec60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec60_arg1, field_0, 0x0);

struct Unk_126ec60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_126ec60, field_0, 0x0);

// 0x710126ec60
void Unk_126ec60_set(const Unk_126ec60* self, Unk_126ec60_arg1* value) {
    value->field_0 = self->field_0;
}
