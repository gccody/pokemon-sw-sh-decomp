// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_106db10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106db10_arg1, field_0, 0x0);

struct Unk_106db10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_106db10, field_0, 0x0);

// 0x710106db10
bool Unk_106db10_check(const Unk_106db10* self, const Unk_106db10_arg1* value) {
    return self->field_0 == value->field_0;
}

// 0x710106db80
void Unk_106db80() {}

// 0x710106db90
u32 Unk_106db90_get() {
    return 1;
}

// 0x710106dba0
void Unk_106dba0() {}
