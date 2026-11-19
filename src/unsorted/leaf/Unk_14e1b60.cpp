// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_14e1b60 {
    u8 _0[0x81];
    bool field_81;
};
PKMN_OFFSET_ASSERT(Unk_14e1b60, field_81, 0x81);

// 0x71014e1b60
void Unk_14e1b60_set(Unk_14e1b60* self, bool value) {
    self->field_81 = value;
}

struct Unk_14e4110 {
    u8 _0[0x47f];
    u8 field_47f;
};
PKMN_OFFSET_ASSERT(Unk_14e4110, field_47f, 0x47f);

// 0x71014e4110
void Unk_14e4110_set(Unk_14e4110* self) {
    self->field_47f = 1;
}

struct Unk_14e4120 {
    u8 _0[0x280];
    u32 field_280;
};
PKMN_OFFSET_ASSERT(Unk_14e4120, field_280, 0x280);

// 0x71014e4120
bool Unk_14e4120_check(const Unk_14e4120* self) {
    return self->field_280 >= 2 && self->field_280 <= 5;
}

struct Unk_14e4140 {
    u8 _0[0x82];
    u8 field_82;
    u8 field_83;
    u8 _84[0x1fc];
    u32 field_280;
};
PKMN_OFFSET_ASSERT(Unk_14e4140, field_82, 0x82);
PKMN_OFFSET_ASSERT(Unk_14e4140, field_83, 0x83);
PKMN_OFFSET_ASSERT(Unk_14e4140, field_280, 0x280);

// 0x71014e4140
bool Unk_14e4140_check(const Unk_14e4140* self) {
    if (self->field_280 == 5) {
        if (self->field_82 != 0) {
            return self->field_83 != 0;
        }
        return 0;
    }
    return 0;
}

struct Unk_14e4180 {
    u8 _0[0x280];
    u32 field_280;
};
PKMN_OFFSET_ASSERT(Unk_14e4180, field_280, 0x280);

// 0x71014e4180
bool Unk_14e4180_check(const Unk_14e4180* self) {
    return self->field_280 == 0;
}

struct Unk_14e4190 {
    u8 _0[0x480];
    bool field_480;
};
PKMN_OFFSET_ASSERT(Unk_14e4190, field_480, 0x480);

// 0x71014e4190
void Unk_14e4190_set(Unk_14e4190* self, bool value) {
    self->field_480 = value;
}

struct Unk_14e62b0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_14e62b0_arg1, field_0, 0x0);

struct Unk_14e62b0 {
    u8 _0[0x408];
    u64 field_408;
};
PKMN_OFFSET_ASSERT(Unk_14e62b0, field_408, 0x408);

void Unk_14f4530(u64, u64);

// 0x71014e62b0
void Unk_14e62b0_call(const Unk_14e62b0* self, const Unk_14e62b0_arg1* value) {
    Unk_14f4530(self->field_408, value->field_0);
}
