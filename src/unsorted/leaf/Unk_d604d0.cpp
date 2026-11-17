// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d604d0 {
    u8 _0[0x50];
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_d604d0, field_50, 0x50);

// 0x7100d604d0
void Unk_d604d0_set(Unk_d604d0* self) {
    self->field_50 = 0xcbf29ce484222645;
}

void Unk_d616e0();

// 0x7100d616d0
void Unk_d616d0_call() {
    Unk_d616e0();
}

struct Unk_d61e70 {
    u8 _0[0x4c0];
    u32 field_4c0;
};
PKMN_OFFSET_ASSERT(Unk_d61e70, field_4c0, 0x4c0);

// 0x7100d61e70
bool Unk_d61e70_check(const Unk_d61e70* self, u32 value) {
    return self->field_4c0 == value;
}
