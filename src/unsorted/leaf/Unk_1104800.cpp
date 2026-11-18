// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7101104800
void Unk_1104800_update() {}

struct Unk_1104810_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104810_arg1, field_0, 0x0);

struct Unk_1104810 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104810, field_0, 0x0);

// 0x7101104810
void Unk_1104810_set(const Unk_1104810* self, Unk_1104810_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1104820_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104820_arg1, field_0, 0x0);

struct Unk_1104820 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1104820, field_0, 0x0);

// 0x7101104820
void Unk_1104820_set(const Unk_1104820* self, Unk_1104820_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x71011048b0
void Unk_11048b0_update() {}

struct Unk_11048c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048c0_arg1, field_0, 0x0);

struct Unk_11048c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048c0, field_0, 0x0);

// 0x71011048c0
void Unk_11048c0_set(const Unk_11048c0* self, Unk_11048c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_11048d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048d0_arg1, field_0, 0x0);

struct Unk_11048d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_11048d0, field_0, 0x0);

// 0x71011048d0
void Unk_11048d0_set(const Unk_11048d0* self, Unk_11048d0_arg1* value) {
    value->field_0 = self->field_0;
}
