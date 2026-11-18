// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_117a610_68 {
    u8 _0[0x170];
    u8 field_170;
};
PKMN_OFFSET_ASSERT(Unk_117a610_68, field_170, 0x170);

struct Unk_117a610 {
    u8 _0[0x68];
    Unk_117a610_68* field_68;
};
PKMN_OFFSET_ASSERT(Unk_117a610, field_68, 0x68);

// 0x710117a610
bool Unk_117a610_check(const Unk_117a610* self) {
    if (self->field_68 == nullptr) {
        return false;
    }
    return self->field_68->field_170 != 0;
}

struct Unk_117b380 {
    u8 _0[0x154];
    u32 field_154;
};
PKMN_OFFSET_ASSERT(Unk_117b380, field_154, 0x154);

// 0x710117b380
void Unk_117b380_setField154(Unk_117b380* self, u32 value) {
    self->field_154 = value;
}

// 0x710117b850
void Unk_117b850_update() {}

// 0x710117b910
void Unk_117b910_update() {}

struct Unk_117b920_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_117b920_arg1, field_0, 0x0);

struct Unk_117b920 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_117b920, field_0, 0x0);

// 0x710117b920
void Unk_117b920_set(const Unk_117b920* self, Unk_117b920_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_117b930_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_117b930_arg1, field_0, 0x0);

struct Unk_117b930 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_117b930, field_0, 0x0);

// 0x710117b930
void Unk_117b930_set(const Unk_117b930* self, Unk_117b930_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_117b940 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_117b940, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_117b940, field_8, 0x8);

// 0x710117b940
void Unk_117b940_set(const Unk_117b940* self, Unk_117b940* value) {
    *value = *self;
}

struct Unk_117b950 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_117b950, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_117b950, field_8, 0x8);

// 0x710117b950
void Unk_117b950_set(const Unk_117b950* self, Unk_117b950* value) {
    *value = *self;
}
