// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_cee6b0 {
    void* field_0;
};
PKMN_OFFSET_ASSERT(Unk_cee6b0, field_0, 0x0);

void Unk_cec7f0(void*);

// 0x7100cee6b0
void Unk_cee6b0_call(const Unk_cee6b0* self) {
    Unk_cec7f0(self->field_0);
}

// 0x7100cee6c0
void Unk_cee6c0_update() {}

struct Unk_cee6d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cee6d0_arg1, field_0, 0x0);

struct Unk_cee6d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cee6d0, field_0, 0x0);

// 0x7100cee6d0
void Unk_cee6d0_set(const Unk_cee6d0* self, Unk_cee6d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_cee6e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cee6e0_arg1, field_0, 0x0);

struct Unk_cee6e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cee6e0, field_0, 0x0);

// 0x7100cee6e0
void Unk_cee6e0_set(const Unk_cee6e0* self, Unk_cee6e0_arg1* value) {
    value->field_0 = self->field_0;
}
