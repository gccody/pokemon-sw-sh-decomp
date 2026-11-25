// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101243370
void Unk_1243370_update() {}

struct Unk_1243380 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1243380, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1243380, field_8, 0x8);

// 0x7101243380
void Unk_1243380_set(const Unk_1243380* self, Unk_1243380* value) {
    *value = *self;
}

struct Unk_1243390 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_1243390, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_1243390, field_8, 0x8);

// 0x7101243390
void Unk_1243390_set(const Unk_1243390* self, Unk_1243390* value) {
    *value = *self;
}
