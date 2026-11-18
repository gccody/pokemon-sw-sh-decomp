// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71011a9820
void Unk_11a9820_update() {}

struct Unk_11a9830 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a9830, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a9830, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a9830, field_10, 0x10);

// 0x71011a9830
void Unk_11a9830_set(const Unk_11a9830* self, Unk_11a9830* value) {
    *value = *self;
}

struct Unk_11a9850 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_11a9850, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_11a9850, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_11a9850, field_10, 0x10);

// 0x71011a9850
void Unk_11a9850_set(const Unk_11a9850* self, Unk_11a9850* value) {
    *value = *self;
}
