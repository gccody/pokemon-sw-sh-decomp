// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14cc8d0;
struct Unk_1456cc0_0 {
    u8 _0[0x708];
    Unk_14cc8d0* field_708;
};
PKMN_OFFSET_ASSERT(Unk_1456cc0_0, field_708, 0x708);

struct Unk_1456cc0 {
    Unk_1456cc0_0* field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cc0, field_0, 0x0);

void Unk_14cc8d0_call(const Unk_14cc8d0*);

// 0x7101456cc0
void Unk_1456cc0_call(const Unk_1456cc0* self) {
    Unk_14cc8d0_call(self->field_0->field_708);
}

// 0x7101456cd0
void Unk_1456cd0_update() {}

struct Unk_1456ce0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456ce0_arg1, field_0, 0x0);

struct Unk_1456ce0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456ce0, field_0, 0x0);

// 0x7101456ce0
void Unk_1456ce0_set(const Unk_1456ce0* self, Unk_1456ce0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_1456cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cf0_arg1, field_0, 0x0);

struct Unk_1456cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1456cf0, field_0, 0x0);

// 0x7101456cf0
void Unk_1456cf0_set(const Unk_1456cf0* self, Unk_1456cf0_arg1* value) {
    value->field_0 = self->field_0;
}
