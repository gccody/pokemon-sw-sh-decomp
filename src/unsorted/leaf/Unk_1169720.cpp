// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_1169720 {
    u8 _0[0x60];
    u8 field_60;
};
PKMN_OFFSET_ASSERT(Unk_1169720, field_60, 0x60);

// 0x7101169720
u8* Unk_1169720_getField60Ptr(Unk_1169720* self) {
    return &self->field_60;
}

struct Unk_1169730 {
    u8 _0[0x90];
    u8 field_90;
};
PKMN_OFFSET_ASSERT(Unk_1169730, field_90, 0x90);

// 0x7101169730
u8* Unk_1169730_getField90Ptr(Unk_1169730* self) {
    return &self->field_90;
}

// 0x7101169fe0
void Unk_1169fe0_update() {}

struct Unk_116a210_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a210_arg1, field_0, 0x0);

struct Unk_116a210 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a210, field_0, 0x0);

// 0x710116a210
void Unk_116a210_set(const Unk_116a210* self, Unk_116a210_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_116a220_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a220_arg1, field_0, 0x0);

struct Unk_116a220 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a220, field_0, 0x0);

// 0x710116a220
void Unk_116a220_set(const Unk_116a220* self, Unk_116a220_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x710116a380
void Unk_116a380_update() {}

struct Unk_116a620_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a620_arg1, field_0, 0x0);

struct Unk_116a620 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a620, field_0, 0x0);

// 0x710116a620
void Unk_116a620_set(const Unk_116a620* self, Unk_116a620_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_116a630_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a630_arg1, field_0, 0x0);

struct Unk_116a630 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_116a630, field_0, 0x0);

// 0x710116a630
void Unk_116a630_set(const Unk_116a630* self, Unk_116a630_arg1* value) {
    value->field_0 = self->field_0;
}
