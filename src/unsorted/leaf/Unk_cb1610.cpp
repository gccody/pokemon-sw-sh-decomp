// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

struct Unk_cb1610 {
    u8 _0[0x54];
    u32 field_54;
    u16 field_58;
    bool field_5a;
    u8 _5b[0x1];
    u16 field_5c;
};
PKMN_OFFSET_ASSERT(Unk_cb1610, field_54, 0x54);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_58, 0x58);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_5a, 0x5a);
PKMN_OFFSET_ASSERT(Unk_cb1610, field_5c, 0x5c);

// 0x7100cb1610
void Unk_cb1610_set(Unk_cb1610* self, bool value) {
    self->field_54 = 0;
    self->field_58 = 0;
    self->field_5c = 0;
    self->field_5a = value;
}

struct Unk_cb3460 {
    u8 _0[0x98];
    u32 field_98;
    u16 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_cb3460, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_cb3460, field_9c, 0x9c);

// 0x7100cb3460
void Unk_cb3460_set(Unk_cb3460* self) {
    self->field_98 = 0;
    self->field_9c = 0;
}

struct Unk_cb3470_arg1 {
    u32 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cb3470_arg1, field_0, 0x0);

struct Unk_cb3470_arg2 {
    u16 field_0;
};
PKMN_OFFSET_ASSERT(Unk_cb3470_arg2, field_0, 0x0);

struct Unk_cb3470 {
    u8 _0[0x98];
    u32 field_98;
    u16 field_9c;
};
PKMN_OFFSET_ASSERT(Unk_cb3470, field_98, 0x98);
PKMN_OFFSET_ASSERT(Unk_cb3470, field_9c, 0x9c);

// 0x7100cb3470
void Unk_cb3470_set(Unk_cb3470* self, const Unk_cb3470_arg1* value, const Unk_cb3470_arg2* arg2) {
    self->field_98 = value->field_0;
    self->field_9c = arg2->field_0;
}
