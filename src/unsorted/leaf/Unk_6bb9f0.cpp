// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71006bb9f0
void Unk_6bb9f0_update() {}

struct Unk_6bbc00 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bbc00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bbc00, field_8, 0x8);

// 0x71006bbc00
void Unk_6bbc00_set(const Unk_6bbc00* self, Unk_6bbc00* value) {
    *value = *self;
}

struct Unk_6bbc10 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_6bbc10, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6bbc10, field_8, 0x8);

// 0x71006bbc10
void Unk_6bbc10_set(const Unk_6bbc10* self, Unk_6bbc10* value) {
    *value = *self;
}
