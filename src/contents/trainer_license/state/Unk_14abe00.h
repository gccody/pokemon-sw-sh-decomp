#pragma once
// The League Card views' parts (each view's +0x58, Unk_14aae90.h) as the
// functions from 0x71014abe00 see them: the second and third tables, then
// what follows the fourth table's 0x58 bytes. Unk_14aae90.h gives its tables
// 0xa0 bytes, which can't hold these fields (+0x2e0 on, inside the fourth
// table's 0xa0): a table is probably 0x58 bytes, with other members in the
// 0x48 after each. Merge the two once it's known. Placeholder names: rename
// them once the classes are known.
#include <types.h>

#include "contents/trainer_license/state/Unk_14aae90.h"
#include "gflib3/Unk_239a418.h"

// The type 0x71027789a0 (as in src/unsorted/types/Unk_1785210.cpp).
struct Unk_27789a0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(nullptr);
        return &type;
    }
};

// The type 0x71027789b0 (as in src/unsorted/types/Unk_1785210.cpp).
struct Unk_27789b0 {
    static const Unk_239a418_Type* Unk_GetType() {
        static Unk_239a418_Type type(Unk_27789a0::Unk_GetType());
        return &type;
    }
};

// A part (Unk_14aaec0_Part): slot 2 gives its type.
class Unk_14abe00_Part {
public:
    virtual void vf0();
    virtual void vf1();
    virtual const Unk_239a418_Type* vf_type();
};

// The part as a T, or null when it isn't one.
template <class T>
inline Unk_14abe00_Part* Unk_14abe00_As(Unk_14abe00_Part* part) {
    const Unk_239a418_Type* kind = T::Unk_GetType();
    if (part != nullptr) {
        for (const Unk_239a418_Type* type = part->vf_type(); type != nullptr; type = type->field_0)
            if (type == kind)
                return part;
    }
    return nullptr;
}

struct Unk_14abe00_Entry {
    u64 key;
    Unk_14abe00_Part* part;
};
PKMN_SIZE_ASSERT(Unk_14abe00_Entry, 0x10);

// A part's slot: a value kept for it.
struct Unk_14abe00_Slot {
    u64 value;
    Unk_14abe00_Part* part;
};
PKMN_SIZE_ASSERT(Unk_14abe00_Slot, 0x10);

struct Unk_1311c60;

struct Unk_14abe00_Parts {
    u8 _0[0x140];
    Unk_14aaec0_Table<Unk_14abaa0_Entry> field_140;
    Unk_14aaec0_Table<Unk_14abe00_Entry> field_1e0;
    u8 _280[0x2e0 - 0x280];
    Unk_1311c60* field_2e0;
    void* field_2e8;
    void* field_2f0;
    u32 field_2f8;
    bool field_2fc;
    Unk_14abe00_Slot field_300[128];

    Unk_14abe00_Part* Unk_GetPart(const u64& key) const {
        Unk_14aaec0_Iter<Unk_14abe00_Entry> it =
            Unk_FindIf(field_1e0.begin(), field_1e0.end(),
                       [key](const Unk_14abe00_Entry& e) { return e.key == key; });
        return it == field_1e0.end() ? nullptr : it->part;
    }

    // The part's slot value: a new slot when it has none, 0 when they're all
    // taken.
    u64 Unk_GetSlot(Unk_14abe00_Part* part) {
        for (Unk_14abe00_Slot& slot : field_300) {
            if (slot.part == part)
                return slot.value;
        }
        for (Unk_14abe00_Slot& slot : field_300) {
            if (slot.part == nullptr) {
                slot.part = part;
                return slot.value;
            }
        }
        return 0;
    }
};
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_2e0, 0x2e0);
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_2f8, 0x2f8);
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_2fc, 0x2fc);
PKMN_OFFSET_ASSERT(Unk_14abe00_Parts, field_300, 0x300);
PKMN_SIZE_ASSERT(Unk_14abe00_Parts, 0xb00);
