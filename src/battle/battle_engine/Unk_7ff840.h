#pragma once
// What a battle Pokemon holds at +0x460 (Unk_7ee6b0_Field, a field effect's
// state): a counter, and ten effect slots, each with its packed 64-bit value
// (Unk_7f8780_get() for none), its turn counter and a list of up to five ids
// (0x1f: none). Placeholder names: rename once the class is known.
#include <types.h>

struct Unk_7ee6b0_Field {
    static constexpr u32 kSlots = 10;
    static constexpr u32 kIds = 5;

    // A counter (src/unsorted/leaf/Unk_7ff860.cpp reads and sets it through
    // placeholder types of its own).
    u8 field_0;   // active
    u32 field_4;  // its turns (0xff: no end)
    u32 field_8;
    u32 field_c;  // turns gone
    u8 field_10;
    u8 field_11;
    u64 field_18[kSlots];
    u32 field_68[kSlots];  // turns gone
    u32 field_90[kSlots][kIds];
    u32 field_158[kSlots];  // number of ids
    u32 field_180[kSlots];  // active
    u16 field_1a8[kSlots];
};
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_4, 0x4);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_c, 0xc);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_11, 0x11);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_68, 0x68);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_90, 0x90);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_158, 0x158);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_180, 0x180);
PKMN_OFFSET_ASSERT(Unk_7ee6b0_Field, field_1a8, 0x1a8);
PKMN_SIZE_ASSERT(Unk_7ee6b0_Field, 0x1c0);

u64 Unk_7f8780_get();

// Clears slot `slot` (no range check).
inline void Unk_7ee6b0_Field_clearSlot(Unk_7ee6b0_Field* self, u32 slot) {
    self->field_18[slot] = Unk_7f8780_get();
    self->field_68[slot] = 0;
    self->field_158[slot] = 0;
    self->field_180[slot] = 0;
    for (u32 i = 0; i < Unk_7ee6b0_Field::kIds; i++)
        self->field_90[slot][i] = 0x1f;
}
