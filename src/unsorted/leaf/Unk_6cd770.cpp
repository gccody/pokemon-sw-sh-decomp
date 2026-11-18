// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71006cd770
void Unk_6cd770_update() {}

struct Unk_6cd780_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6cd780_arg1, field_0, 0x0);

struct Unk_6cd780 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6cd780, field_0, 0x0);

// 0x71006cd780
void Unk_6cd780_set(const Unk_6cd780* self, Unk_6cd780_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6cd790_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6cd790_arg1, field_0, 0x0);

struct Unk_6cd790 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6cd790, field_0, 0x0);

// 0x71006cd790
void Unk_6cd790_set(const Unk_6cd790* self, Unk_6cd790_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71006cd7c0
void Unk_6cd7c0_update() {}

// 0x71006cd7d0
void Unk_6cd7d0_update() {}

// 0x71006cd7e0
void Unk_6cd7e0_update() {}
