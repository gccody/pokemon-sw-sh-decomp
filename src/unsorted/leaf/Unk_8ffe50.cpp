// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_8ffe50 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8ffe50, field_0, 0x0);

void Unk_8ff9a0(u64);

// 0x71008ffe50
u32 Unk_8ffe50_call(const Unk_8ffe50* self) {
    Unk_8ff9a0(self->field_0);
    return 1;
}

// 0x71008ffe70
void Unk_8ffe70_update() {}

struct Unk_8ffe80_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8ffe80_arg1, field_0, 0x0);

struct Unk_8ffe80 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8ffe80, field_0, 0x0);

// 0x71008ffe80
void Unk_8ffe80_set(const Unk_8ffe80* self, Unk_8ffe80_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_8ffe90_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8ffe90_arg1, field_0, 0x0);

struct Unk_8ffe90 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_8ffe90, field_0, 0x0);

// 0x71008ffe90
void Unk_8ffe90_set(const Unk_8ffe90* self, Unk_8ffe90_arg1* value) {
    value->field_0 = self->field_0;
}
