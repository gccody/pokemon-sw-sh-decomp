// Scope: common
// Directly called leaf functions between two static initialisers (one or more
// TUs). Placeholder types: rename and move once the owning classes are known.
#include <types.h>

// 0x71004f7190
void Unk_4f7190_update() {
}

struct Unk_4fb320 {
    u8 _0[0x2c9];
    u8 field_2c9;
    u8 _2ca[0x47e];
    void* field_748;
    void* field_750;
};
PKMN_OFFSET_ASSERT(Unk_4fb320, field_2c9, 0x2c9);
PKMN_OFFSET_ASSERT(Unk_4fb320, field_748, 0x748);
PKMN_OFFSET_ASSERT(Unk_4fb320, field_750, 0x750);
void Unk_552090(void*, u64);
void Unk_552850(void*, u64);

// 0x71004fb320
void Unk_4fb320_update(const Unk_4fb320* self, u64 value) {
    if (self->field_2c9 != 0) {
        return;
    }
    Unk_552090(self->field_748, value);
    Unk_552850(self->field_750, value);
}

struct Unk_4fb360 {
    u8 _0[0x2c9];
    u8 field_2c9;
    u8 _2ca[0x48e];
    void* field_758;
};
PKMN_OFFSET_ASSERT(Unk_4fb360, field_2c9, 0x2c9);
PKMN_OFFSET_ASSERT(Unk_4fb360, field_758, 0x758);
void Unk_552090(void*, u64);

// 0x71004fb360
void Unk_4fb360_update(const Unk_4fb360* self, u64 value) {
    if (self->field_2c9 != 0) {
        return;
    }
    Unk_552090(self->field_758, value);
}
