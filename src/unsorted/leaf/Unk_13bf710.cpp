// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71013bf710
u32 Unk_13bf710_get() {
    return 1;
}

// 0x71013cee80
void Unk_13cee80_update() {}

struct Unk_13cee90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90_arg1, field_0, 0x0);

struct Unk_13cee90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13cee90, field_0, 0x0);

// 0x71013cee90
void Unk_13cee90_set(const Unk_13cee90* self, Unk_13cee90_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_13ceea0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0_arg1, field_0, 0x0);

struct Unk_13ceea0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_13ceea0, field_0, 0x0);

// 0x71013ceea0
void Unk_13ceea0_set(const Unk_13ceea0* self, Unk_13ceea0_arg1* value) {
    value->field_0 = self->field_0;
}
