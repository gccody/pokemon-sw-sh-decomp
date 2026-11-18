// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1183860 {
    u8 _0[0x68];
    u64 field_68;
};
PKMN_OFFSET_ASSERT(Unk_1183860, field_68, 0x68);

// 0x7101183860
bool Unk_1183860_check(const Unk_1183860* self) {
    return self->field_68 != 0;
}

struct Unk_1185b20 {
    u8 _0[0x60];
    bool field_60;
};
PKMN_OFFSET_ASSERT(Unk_1185b20, field_60, 0x60);

// 0x7101185b20
void Unk_1185b20_set(Unk_1185b20* self, bool value) {
    self->field_60 = value;
}

struct Unk_1186150_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_1186150_arg1, field_0, 0x0);

struct Unk_1186150 {
    u8 _0[0x60];
    u64 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1186150, field_60, 0x60);

// 0x7101186150
void Unk_1186150_set(Unk_1186150* self, const Unk_1186150_arg1* value) {
    self->field_60 = value->field_0;
}

// 0x710118aed0
void Unk_118aed0_update() {}

struct Unk_118aee0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_118aee0_arg1, field_0, 0x0);

struct Unk_118aee0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_118aee0, field_0, 0x0);

// 0x710118aee0
void Unk_118aee0_set(const Unk_118aee0* self, Unk_118aee0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_118aef0_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_118aef0_arg1, field_0, 0x0);

struct Unk_118aef0 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_118aef0, field_0, 0x0);

// 0x710118aef0
void Unk_118aef0_set(const Unk_118aef0* self, Unk_118aef0_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_118af00_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_118af00_arg1, field_0, 0x0);

void Unk_11877b0(void*, u64);

// 0x710118af00
void Unk_118af00_call(void* self, const Unk_118af00_arg1* value) {
    Unk_11877b0(self, value->field_0);
}

// 0x710118af10
void Unk_118af10_update() {}

struct Unk_118af20 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_118af20, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_118af20, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_118af20, field_10, 0x10);

// 0x710118af20
void Unk_118af20_set(const Unk_118af20* self, Unk_118af20* value) {
    *value = *self;
}

struct Unk_118af40 {
    u64 field_0;
    u64 field_8;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_118af40, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_118af40, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_118af40, field_10, 0x10);

// 0x710118af40
void Unk_118af40_set(const Unk_118af40* self, Unk_118af40* value) {
    *value = *self;
}
