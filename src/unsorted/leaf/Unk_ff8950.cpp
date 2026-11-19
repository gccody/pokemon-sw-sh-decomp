// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_ff8950 {
    u8 _0[0x30];
    u32 field_30;
    u8 _34[0x4c];
    u8 field_80;
};
PKMN_OFFSET_ASSERT(Unk_ff8950, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_ff8950, field_80, 0x80);
void Unk_ff8820(void*, u32, u32, u32, u64, u64, u64, u64);

// 0x7100ff8950
void Unk_ff8950_update(Unk_ff8950* self, u64 value, u64 arg2, u64 arg3, u64 arg4) {
    if (self->field_80 != 0) {
        return;
    }
    self->field_30 = 0;
    Unk_ff8820(self, 1, 1, 0, value, arg2, arg3, arg4);
}

// 0x7100ff8ce0
void Unk_ff8ce0_update() {}

struct Unk_ff8cf0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0_arg1, field_0, 0x0);

struct Unk_ff8cf0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8cf0, field_0, 0x0);

// 0x7100ff8cf0
void Unk_ff8cf0_set(const Unk_ff8cf0* self, Unk_ff8cf0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_ff8d00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00_arg1, field_0, 0x0);

struct Unk_ff8d00 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_ff8d00, field_0, 0x0);

// 0x7100ff8d00
void Unk_ff8d00_set(const Unk_ff8d00* self, Unk_ff8d00_arg1* value) {
    value->field_0 = self->field_0;
}
