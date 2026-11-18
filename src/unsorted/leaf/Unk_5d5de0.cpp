// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

void Unk_5d5df0();

// 0x71005d5de0
void Unk_5d5de0_call() {
    Unk_5d5df0();
}

// 0x71005d9e70
void Unk_5d9e70_update() {}

struct Unk_5d9e80 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5d9e80, field_10, 0x10);

// 0x71005d9e80
void Unk_5d9e80_set(const Unk_5d9e80* self, Unk_5d9e80* value) {
    *value = *self;
}

struct Unk_5d9ea0 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_5d9ea0, field_10, 0x10);

// 0x71005d9ea0
void Unk_5d9ea0_set(const Unk_5d9ea0* self, Unk_5d9ea0* value) {
    *value = *self;
}
