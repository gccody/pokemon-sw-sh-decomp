// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100923620
void Unk_923620_update() {}

struct Unk_923630_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_923630_arg1, field_0, 0x0);

struct Unk_923630 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_923630, field_0, 0x0);

// 0x7100923630
void Unk_923630_set(const Unk_923630* self, Unk_923630_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_923640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_923640_arg1, field_0, 0x0);

struct Unk_923640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_923640, field_0, 0x0);

// 0x7100923640
void Unk_923640_set(const Unk_923640* self, Unk_923640_arg1* value) {
    value->field_0 = self->field_0;
}
