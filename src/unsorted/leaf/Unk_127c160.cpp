// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x710127c160
void Unk_127c160_update() {}

struct Unk_127c170 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_127c170, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_127c170, field_8, 0x8);

// 0x710127c170
void Unk_127c170_set(const Unk_127c170* self, Unk_127c170* value) {
    *value = *self;
}

struct Unk_127c180 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_127c180, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_127c180, field_8, 0x8);

// 0x710127c180
void Unk_127c180_set(const Unk_127c180* self, Unk_127c180* value) {
    *value = *self;
}
