// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_6ddde0 {
    u32 field_0;
    u8 _4[0x4];
    u64 field_8;
    u32 field_10;
    u8 _14[0x4];
    u64 field_18;
};
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_6ddde0, field_18, 0x18);

// 0x71006ddde0
u32 Unk_6ddde0_update(Unk_6ddde0* self) {
    self->field_0 = self->field_10;
    self->field_8 = self->field_18;
    return 0;
}

struct Unk_6de660 {
    u8 _0[0xb0];
    u8 field_b0;
};
PKMN_OFFSET_ASSERT(Unk_6de660, field_b0, 0xb0);

// 0x71006de660
u8* Unk_6de660_getFieldb0Ptr(Unk_6de660* self) {
    return &self->field_b0;
}

// 0x71006de7d0
void Unk_6de7d0_update() {}

struct Unk_6de7e0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7e0_arg1, field_0, 0x0);

struct Unk_6de7e0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7e0, field_0, 0x0);

// 0x71006de7e0
void Unk_6de7e0_set(const Unk_6de7e0* self, Unk_6de7e0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_6de7f0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7f0_arg1, field_0, 0x0);

struct Unk_6de7f0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_6de7f0, field_0, 0x0);

// 0x71006de7f0
void Unk_6de7f0_set(const Unk_6de7f0* self, Unk_6de7f0_arg1* value) {
    value->field_0 = self->field_0;
}
