// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011a8ca0
void Unk_11a8ca0_update() {}

struct Unk_11a8cb0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a8cb0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a8cb0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a8cb0, field_10, 0x10);

// 0x71011a8cb0
void Unk_11a8cb0_set(const Unk_11a8cb0* self, Unk_11a8cb0* value) {
    *value = *self;
}

struct Unk_11a8cd0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a8cd0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a8cd0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a8cd0, field_10, 0x10);

// 0x71011a8cd0
void Unk_11a8cd0_set(const Unk_11a8cd0* self, Unk_11a8cd0* value) {
    *value = *self;
}

// 0x71011a8d50
void Unk_11a8d50_update() {}

struct Unk_11a8d60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a8d60_arg1, field_0, 0x0);

struct Unk_11a8d60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a8d60, field_0, 0x0);

// 0x71011a8d60
void Unk_11a8d60_set(const Unk_11a8d60* self, Unk_11a8d60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11a8d70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a8d70_arg1, field_0, 0x0);

struct Unk_11a8d70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11a8d70, field_0, 0x0);

// 0x71011a8d70
void Unk_11a8d70_set(const Unk_11a8d70* self, Unk_11a8d70_arg1* value) {
    value->field_0 = self->field_0;
}
