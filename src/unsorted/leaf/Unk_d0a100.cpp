// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_d0a100 {
    u8 _0[0x4dc];
    f32 field_4dc;
};
PKMN_OFFSET_ASSERT(Unk_d0a100, field_4dc, 0x4dc);

// 0x7100d0a100
f32 Unk_d0a100_getField4dc(const Unk_d0a100* self) {
    return self->field_4dc;
}

struct Unk_d0a110 {
    u8 _0[0x514];
    f32 field_514;
};
PKMN_OFFSET_ASSERT(Unk_d0a110, field_514, 0x514);

// 0x7100d0a110
f32 Unk_d0a110_getField514(const Unk_d0a110* self) {
    return self->field_514;
}

struct Unk_d0b1a0_arg1 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
    u64 field_18;
    u64 field_20;
    u64 field_28;
    u64 field_30;
    u64 field_38;
    u64 field_40;
    u64 field_48;
    u64 field_50;
};
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_28, 0x28);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_30, 0x30);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_38, 0x38);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_40, 0x40);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_d0b1a0_arg1, field_50, 0x50);

struct Unk_d0b1a0 {
    u8 _0[0x898];
    u64 field_898;
    u64 field_8a0;
    u64 field_8a8;
    u64 field_8b0;
    u64 field_8b8;
    u64 field_8c0;
    u64 field_8c8;
    u64 field_8d0;
    u64 field_8d8;
    u64 field_8e0;
    u64 field_8e8;
};
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_898, 0x898);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8a0, 0x8a0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8a8, 0x8a8);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8b0, 0x8b0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8b8, 0x8b8);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8c0, 0x8c0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8c8, 0x8c8);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8d0, 0x8d0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8d8, 0x8d8);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8e0, 0x8e0);
PKMN_OFFSET_ASSERT(Unk_d0b1a0, field_8e8, 0x8e8);

// 0x7100d0b1a0
void Unk_d0b1a0_set(Unk_d0b1a0* self, const Unk_d0b1a0_arg1* value) {
    u64 v0 = value->field_0;
    u64 v1 = value->field_8;
    self->field_8a8 = value->field_10;
    self->field_8a0 = v1;
    self->field_898 = v0;
    u64 v2 = value->field_18;
    u64 v3 = value->field_20;
    u64 v4 = value->field_28;
    self->field_8c8 = value->field_30;
    self->field_8c0 = v4;
    self->field_8b8 = v3;
    self->field_8b0 = v2;
    u64 v5 = value->field_38;
    u64 v6 = value->field_40;
    u64 v7 = value->field_48;
    self->field_8e8 = value->field_50;
    self->field_8e0 = v7;
    self->field_8d8 = v6;
    self->field_8d0 = v5;
}

struct Unk_d0b220 {
    u8 _0[0xb30];
    u8 field_b30;
};
PKMN_OFFSET_ASSERT(Unk_d0b220, field_b30, 0xb30);

void Unk_d09bb0(void*, void*, f32);

// 0x7100d0b220
void Unk_d0b220_call(Unk_d0b220* self, f32 radius) {
    Unk_d09bb0(self, &self->field_b30, radius);
}

struct Unk_d0b570 {
    u8 _0[0x2a8];
    void* field_2a8;
};
PKMN_OFFSET_ASSERT(Unk_d0b570, field_2a8, 0x2a8);

void Unk_5c89c0(void*, void*, void*, u32);

// 0x7100d0b570
void Unk_d0b570_call(const Unk_d0b570* self, void* value, void* arg2, u32 arg3) {
    Unk_5c89c0(self->field_2a8, value, arg2, arg3);
}
