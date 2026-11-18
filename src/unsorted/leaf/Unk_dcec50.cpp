// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100dcec50
void Unk_dcec50_update() {}

struct Unk_dcec60_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec60_arg1, field_0, 0x0);

struct Unk_dcec60 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec60, field_0, 0x0);

// 0x7100dcec60
void Unk_dcec60_set(const Unk_dcec60* self, Unk_dcec60_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_dcec70_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec70_arg1, field_0, 0x0);

struct Unk_dcec70 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcec70, field_0, 0x0);

// 0x7100dcec70
void Unk_dcec70_set(const Unk_dcec70* self, Unk_dcec70_arg1* value) {
    value->field_0 = self->field_0;
}

// 0x7100dcf530
void Unk_dcf530_update() {}

struct Unk_dcf540_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf540_arg1, field_0, 0x0);

struct Unk_dcf540 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf540, field_0, 0x0);

// 0x7100dcf540
void Unk_dcf540_set(const Unk_dcf540* self, Unk_dcf540_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_dcf550_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf550_arg1, field_0, 0x0);

struct Unk_dcf550 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_dcf550, field_0, 0x0);

// 0x7100dcf550
void Unk_dcf550_set(const Unk_dcf550* self, Unk_dcf550_arg1* value) {
    value->field_0 = self->field_0;
}
