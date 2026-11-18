// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_7b5d90_0_5d8 {
    u8 _0[0x18];
    u32 field_18;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_0_5d8, field_18, 0x18);

struct Unk_7b5d90_0 {
    u8 _0[0x5d8];
    Unk_7b5d90_0_5d8* field_5d8;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_0, field_5d8, 0x5d8);

struct Unk_7b5d90_arg1 {
    u8 _0[0x4];
    u32 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90_arg1, field_4, 0x4);

struct Unk_7b5d90 {
    Unk_7b5d90_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5d90, field_0, 0x0);

// 0x71007b5d90
void Unk_7b5d90_set(const Unk_7b5d90* self, const Unk_7b5d90_arg1* value) {
    self->field_0->field_5d8->field_18 = value->field_4;
}

// 0x71007b5db0
void Unk_7b5db0_update() {}

struct Unk_7b5dc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dc0_arg1, field_0, 0x0);

struct Unk_7b5dc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dc0, field_0, 0x0);

// 0x71007b5dc0
void Unk_7b5dc0_set(const Unk_7b5dc0* self, Unk_7b5dc0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7b5dd0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dd0_arg1, field_0, 0x0);

struct Unk_7b5dd0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7b5dd0, field_0, 0x0);

// 0x71007b5dd0
void Unk_7b5dd0_set(const Unk_7b5dd0* self, Unk_7b5dd0_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71007bada0
void Unk_7bada0_update() {}

struct Unk_7badb0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badb0_arg1, field_0, 0x0);

struct Unk_7badb0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badb0, field_0, 0x0);

// 0x71007badb0
void Unk_7badb0_set(const Unk_7badb0* self, Unk_7badb0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_7badc0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badc0_arg1, field_0, 0x0);

struct Unk_7badc0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7badc0, field_0, 0x0);

// 0x71007badc0
void Unk_7badc0_set(const Unk_7badc0* self, Unk_7badc0_arg1* value) {
    value->field_0 = self->field_0;
}
