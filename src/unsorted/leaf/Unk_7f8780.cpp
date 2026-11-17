// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71007f8780
u32 Unk_7f8780_get() {
    return 0xf8;
}

struct Unk_7f8790 {
    u8 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f8790, field_0, 0x0);

// 0x71007f8790
bool Unk_7f8790_check(const Unk_7f8790* self) {
    return (self->field_0 & 7) == 0;
}

struct Unk_7f88c0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f88c0, field_0, 0x0);

// 0x71007f88c0
bool Unk_7f88c0_check(const Unk_7f88c0* self) {
    return (self->field_0 & 0x3f07) == 0xf01;
}

struct Unk_7f8b70 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_7f8b70, field_0, 0x0);

// 0x71007f8b70
u32 Unk_7f8b70_get(const Unk_7f8b70* self) {
    return (self->field_0 >> 3) & 0x1f;
}

struct Unk_7f8ce0 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8ce0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8ce0, field_4, 0x4);

// 0x71007f8ce0
void Unk_7f8ce0_set(Unk_7f8ce0* self) {
    self->field_0 = 0;
    self->field_4 = 5;
}

struct Unk_7f8cf0 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8cf0, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8cf0, field_4, 0x4);

// 0x71007f8cf0
void Unk_7f8cf0_set(Unk_7f8cf0* self, u32 value, u8 arg2) {
    self->field_0 = value;
    self->field_4 = arg2;
}

struct Unk_7f8d00_arg1 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8d00_arg1, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8d00_arg1, field_4, 0x4);

struct Unk_7f8d00 {
    u32 field_0;
    u8 field_4;
};
PKMN_OFFSET_ASSERT(Unk_7f8d00, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_7f8d00, field_4, 0x4);

// 0x71007f8d00
void Unk_7f8d00_set(Unk_7f8d00* self, const Unk_7f8d00_arg1* value) {
    self->field_0 = value->field_0;
    self->field_4 = value->field_4;
}

// 0x71007fc160
bool Unk_7fc160_check(void* /*unused*/, u32 value) {
    return (value | 1) == 3;
}

// 0x71007fc180
u32 Unk_7fc180_get() {
    return 1;
}

// 0x71007fc1e0
void Unk_7fc1e0() {}

struct Unk_7fc2e0 {
    u8 _0[0x30];
    u8 field_30;
};
PKMN_OFFSET_ASSERT(Unk_7fc2e0, field_30, 0x30);

// 0x71007fc2e0
u8 Unk_7fc2e0_getField30(const Unk_7fc2e0* self) {
    return self->field_30;
}
