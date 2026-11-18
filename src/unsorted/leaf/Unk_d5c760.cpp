// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x7100d5c760
void Unk_d5c760_update() {}

struct Unk_d5c770 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d5c770, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d5c770, field_8, 0x8);

// 0x7100d5c770
void Unk_d5c770_set(const Unk_d5c770* self, Unk_d5c770* value) {
    *value = *self;
}

struct Unk_d5c780 {
    u64 field_0;
    u64 field_8;
};
PKMN_OFFSET_ASSERT(Unk_d5c780, field_0, 0x0);
PKMN_OFFSET_ASSERT(Unk_d5c780, field_8, 0x8);

// 0x7100d5c780
void Unk_d5c780_set(const Unk_d5c780* self, Unk_d5c780* value) {
    *value = *self;
}

// 0x7100d5cb00
void Unk_d5cb00_update() {}

struct Unk_d5cb10_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d5cb10_arg1, field_0, 0x0);

struct Unk_d5cb10 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d5cb10, field_0, 0x0);

// 0x7100d5cb10
void Unk_d5cb10_set(const Unk_d5cb10* self, Unk_d5cb10_arg1* value) {
    value->field_0 = self->field_0;
}

struct Unk_d5cb20_arg1 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d5cb20_arg1, field_0, 0x0);

struct Unk_d5cb20 {
    u64 field_0;
};
PKMN_OFFSET_ASSERT(Unk_d5cb20, field_0, 0x0);

// 0x7100d5cb20
void Unk_d5cb20_set(const Unk_d5cb20* self, Unk_d5cb20_arg1* value) {
    value->field_0 = self->field_0;
}
