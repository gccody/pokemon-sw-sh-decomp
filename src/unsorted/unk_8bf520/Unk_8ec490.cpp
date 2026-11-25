// Scope: common
// Two checks of the same shape, in the TU of 0x71008ec490-0x71008ec680: true
// when the object has no 0x180 entry or the entry's counter at 0x54 is 0.
// Placeholder types: rename and move once the owning classes are known.
#include <types.h>

#include <atomic>

struct Unk_8ec4e0_180 {
    u8 _0[0x54];
    std::atomic<s32> field_54;
};
PKMN_OFFSET_ASSERT(Unk_8ec4e0_180, field_54, 0x54);

struct Unk_8ec4e0_10 {
    u8 _0[0x180];
    Unk_8ec4e0_180* field_180;
};
PKMN_OFFSET_ASSERT(Unk_8ec4e0_10, field_180, 0x180);

struct Unk_8ec4e0 {
    u8 _0[0x10];
    Unk_8ec4e0_10* field_10;
};
PKMN_OFFSET_ASSERT(Unk_8ec4e0, field_10, 0x10);

// 0x71008ec4e0
bool Unk_8ec4e0_check(const Unk_8ec4e0* self) {
    Unk_8ec4e0_180* entry = self->field_10->field_180;
    if (entry == nullptr) {
        return true;
    }
    return entry->field_54.load() == 0;
}

// 0x71008ec560
bool Unk_8ec560_check(const Unk_8ec4e0* self) {
    Unk_8ec4e0_180* entry = self->field_10->field_180;
    if (entry == nullptr) {
        return true;
    }
    return entry->field_54.load() == 0;
}
