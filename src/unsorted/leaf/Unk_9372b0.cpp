// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_9372b0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9372b0, field_0, 0x0);

void Unk_936de0(u64);

// 0x71009372b0
void Unk_9372b0_call(const Unk_9372b0* self) {
    Unk_936de0(self->field_0);
}

// 0x71009372c0
void Unk_9372c0_update() {}

struct Unk_9372d0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9372d0_arg1, field_0, 0x0);

struct Unk_9372d0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9372d0, field_0, 0x0);

// 0x71009372d0
void Unk_9372d0_set(const Unk_9372d0* self, Unk_9372d0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_9372e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9372e0_arg1, field_0, 0x0);

struct Unk_9372e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_9372e0, field_0, 0x0);

// 0x71009372e0
void Unk_9372e0_set(const Unk_9372e0* self, Unk_9372e0_arg1* value) {
    value->field_0 = self->field_0;
}
