// Scope: common
// Two functions that go through an object's items (0x60 bytes each) and
// look each item's key up in a sorted set. Placeholder names.
#include "sorted_array.h"

struct Unk_3d08c0_Key;

struct Unk_3d08c0_Item {
    u8 _0[0x50];
    Unk_3d08c0_Key* field_50;
    u8 _58[8];
};
PKMN_SIZE_ASSERT(Unk_3d08c0_Item, 0x60);

struct Unk_3d08c0_Self {
    u8 _0[0x28];
    Unk_Array<Unk_3d08c0_Item> field_28;
};

typedef Unk_SortedKeyArray<Unk_3d08c0_Key*, Unk_3d08c0_Key*, Unk_KeyIsItem<Unk_3d08c0_Key*>>
    Unk_3d08c0_Keys;

struct Unk_3d08c0_Set {
    u8 _0[8];
    Unk_3d08c0_Keys field_8;

    bool Contains(Unk_3d08c0_Key* key) const { return field_8.Exists(key) != nullptr; }
};

// 0x71003d08c0: the number of items whose key is in the set (mode 0) or
// isn't (mode 1)
// NON_MATCHING: register allocation only. The original computes the end of
// the items after it loads the set's length and pointer (the set's pointer
// gets x9, the end x10); here the end comes first.
u32 Unk_3d08c0(Unk_3d08c0_Self* self, const Unk_3d08c0_Set& set, u32 mode) {
    u32 count = 0;
    for (auto it = self->field_28.Begin(); it != self->field_28.End(); ++it) {
        switch (mode) {
        case 0:
            if (set.Contains((*it).field_50))
                count++;
            break;
        case 1:
            if (!set.Contains((*it).field_50))
                count++;
            break;
        }
    }
    return count;
}

// 0x71003d0a00: the item of that kind at `index`
// NON_MATCHING: register allocation only, as Unk_3d08c0.
Unk_3d08c0_Item* Unk_3d0a00(Unk_3d08c0_Self* self, const Unk_3d08c0_Set& set, u32 mode, u32 index) {
    for (auto it = self->field_28.Begin(); it != self->field_28.End(); ++it) {
        switch (mode) {
        case 0:
            if (set.Contains((*it).field_50)) {
                if (index == 0)
                    return it.item;
                index--;
            }
            break;
        case 1:
            if (!set.Contains((*it).field_50)) {
                if (index == 0)
                    return it.item;
                index--;
            }
            break;
        }
    }
    return nullptr;
}
