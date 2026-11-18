// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100c3d630
void Unk_c3d630_update() {}

struct Unk_c3d640_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c3d640_arg1, field_0, 0x0);

struct Unk_c3d640 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c3d640, field_0, 0x0);

// 0x7100c3d640
void Unk_c3d640_set(const Unk_c3d640* self, Unk_c3d640_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_c3d650_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c3d650_arg1, field_0, 0x0);

struct Unk_c3d650 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_c3d650, field_0, 0x0);

// 0x7100c3d650
void Unk_c3d650_set(const Unk_c3d650* self, Unk_c3d650_arg1* value) {
    value->field_0 = self->field_0;
}
