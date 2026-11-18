// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14cc8d0;
struct Unk_14842a0_0 {
    u8 _0[0x708];
    Unk_14cc8d0* field_708;
};
PKMN_OFFSET_ASSERT(Unk_14842a0_0, field_708, 0x708);

struct Unk_14842a0 {
    Unk_14842a0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_14842a0, field_0, 0x0);

void Unk_14cc8d0_call(const Unk_14cc8d0*);

// 0x71014842a0
void Unk_14842a0_call(const Unk_14842a0* self) {
    Unk_14cc8d0_call(self->field_0->field_708);
}

// 0x71014842b0
void Unk_14842b0_update() {}

struct Unk_14842c0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14842c0_arg1, field_0, 0x0);

struct Unk_14842c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14842c0, field_0, 0x0);

// 0x71014842c0
void Unk_14842c0_set(const Unk_14842c0* self, Unk_14842c0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_14842d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14842d0_arg1, field_0, 0x0);

struct Unk_14842d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14842d0, field_0, 0x0);

// 0x71014842d0
void Unk_14842d0_set(const Unk_14842d0* self, Unk_14842d0_arg1* value) {
    value->field_0 = self->field_0;
}
