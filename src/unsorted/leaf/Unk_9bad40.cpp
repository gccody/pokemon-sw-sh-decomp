// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9bad40 {
    u8 _0[0x10];
    u32 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9bad40, field_10, 0x10);

// 0x71009bad40
bool Unk_9bad40_check(const Unk_9bad40* self) {
    return self->field_10 == 4;
}

// 0x71009bbb40
void Unk_9bbb40_update() {}

struct Unk_9bbb50 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9bbb50, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9bbb50, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_9bbb50, field_10, 0x10);

// 0x71009bbb50
void Unk_9bbb50_set(const Unk_9bbb50* self, Unk_9bbb50* value) {
    *value = *self;
}

struct Unk_9bbb70 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_9bbb70, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_9bbb70, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_9bbb70, field_10, 0x10);

// 0x71009bbb70
void Unk_9bbb70_set(const Unk_9bbb70* self, Unk_9bbb70* value) {
    *value = *self;
}
