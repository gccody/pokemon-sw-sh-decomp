// Scope: common
// An array of lists of values by a key (0x18 bytes an entry, 0x10 bytes a
// value): setting a key's list from one array of pairs or from two arrays,
// the list's resize (its new values take the last one's), and the entries'
// array growing. Placeholder names.
#include "Unk_KeyArray.h"

// A number of either kind.
union Unk_396ba0_Number {
    f32 f;
    u32 i;
};

struct Unk_396ba0_Pair {
    Unk_396ba0_Number field_0;
    Unk_396ba0_Number field_4;
};

// A value of a list: two pairs.
struct Unk_396ba0_Value {
    Unk_396ba0_Value() {
        field_0.i = 0;
        field_4.i = 0;
        field_8.i = 0;
        field_c.i = 0;
    }

    Unk_396ba0_Number field_0;
    Unk_396ba0_Number field_4;
    Unk_396ba0_Number field_8;
    Unk_396ba0_Number field_c;
};
PKMN_SIZE_ASSERT(Unk_396ba0_Value, 0x10);

struct Unk_396ba0_Values : Unk_GrowArray<Unk_396ba0_Value> {
    Unk_396ba0_Values() {
        field_0 = nullptr;
        field_8 = 0;
        field_c = 0;
    }

    // The list with `size` values, the new ones constructed (the array's
    // Resize, with the length kept as 32 bits).
    bool Resize(u32 size) {
        u32 length = Length();
        if (size < length) {
            field_8 = size;
            return true;
        }
        if (size > field_c) {
            if (!GrowArray(size - length))
                return false;
        }
        for (size_t i = length; i < size; i++)
            Unk_PlacementNew(field_0 + i) Unk_396ba0_Value;
        field_8 = size;
        return true;
    }

    bool Unk_396f70(u32 size);
};

// 0x7100396f70: the list with `size` values, the new ones as the last one
// was. False without memory.
// NON_MATCHING: the same instructions in another layout, 8 bytes less. The
// original keeps a block of its own for "fewer values than before" (the
// store of the length and the return, right after the first compare) and
// tests `length < size` again before the fill; here that path is threaded
// past the test and shares the block that stores the length.
bool Unk_396ba0_Values::Unk_396f70(u32 size) {
    u32 length = Length();
    if (size < length) {
        field_8 = size;
        return true;
    }
    if (size > field_c) {
        if (!GrowArray(size - length))
            return false;
    }
    for (size_t i = length; i < size; i++)
        Unk_PlacementNew(field_0 + i) Unk_396ba0_Value;
    field_8 = size;
    if (length != 0) {
        for (size_t i = length; i < size; i++)
            field_0[i] = field_0[length - 1];
    }
    return true;
}

struct Unk_396ba0_Entry {
    Unk_396ba0_Entry() {}

    void Transfer(Unk_396ba0_Entry& other) {
        key = other.key;
        item.Transfer(other.item);
    }

    u64 key;
    Unk_396ba0_Values item;
};
PKMN_SIZE_ASSERT(Unk_396ba0_Entry, 0x18);

struct Unk_396ba0_Entries
    : Unk_GrowArray<Unk_396ba0_Entry, Unk_PoolDefault, 1, const Unk_396ba0_Entry&,
                    Unk_TransferMove<Unk_396ba0_Entry>> {
    Iterator FindEx(u64 key) const {
        Iterator it = Begin();
        for (Iterator end = End(); it != end; ++it) {
            if (it.item->key == key)
                break;
        }
        return it;
    }

    Unk_396ba0_Values* Exists(u64 key) const {
        Iterator it = FindEx(key);
        return it != End() ? &it.item->item : nullptr;
    }

    // The list of a key, added when it has none: null without memory.
    Unk_396ba0_Values* Set(u64 key) {
        Unk_396ba0_Values* found = Exists(key);
        if (found != nullptr)
            return found;
        Unk_396ba0_Entry* added = AddLast();
        if (added != nullptr) {
            added->key = key;
            return &added->item;
        }
        return nullptr;
    }
};

// 0x7100397220
template bool Unk_GrowArray<Unk_396ba0_Entry, Unk_PoolDefault, 1, const Unk_396ba0_Entry&,
                            Unk_TransferMove<Unk_396ba0_Entry>>::GrowArray(u32);

struct Unk_396ba0_T {
    u64 field_0;
    Unk_396ba0_Entries field_8;
};

// 0x7100396ba0: the first pairs of a key's values, from an array of pairs.
// NON_MATCHING (and 0x7100396d90): the original has two calls of the resize,
// one with the count and one with the list's length (the call split by the
// argument's two sources), and the path with the count doesn't test the count
// for 0 after it; here the two are merged again (`csel` and one call), 28
// bytes less.
u32 Unk_396ba0(Unk_396ba0_T* self, u64 key, const Unk_396ba0_Pair* pairs, u32 count) {
    Unk_396ba0_Values* values = self->field_8.Set(key);
    if (values != nullptr) {
        bool ok = values->Unk_396f70(values->Length() < count ? count : values->Length());
        if (count != 0 && ok) {
            for (u32 i = 0; i < count; i++) {
                values->field_0[i].field_4 = pairs[i].field_4;
                values->field_0[i].field_0 = pairs[i].field_0;
            }
            for (u32 i = count; i < values->Length(); i++) {
                values->field_0[i].field_4 = pairs[count - 1].field_4;
                values->field_0[i].field_0 = pairs[count - 1].field_0;
            }
        }
    }
    return 1;
}

// 0x7100396d90: the second pairs of a key's values, from two arrays.
u32 Unk_396d90(Unk_396ba0_T* self, u64 key, const Unk_396ba0_Number* a2,
               const Unk_396ba0_Number* a3, u32 count) {
    Unk_396ba0_Values* values = self->field_8.Set(key);
    if (values != nullptr) {
        bool ok = values->Unk_396f70(values->Length() < count ? count : values->Length());
        if (count != 0 && ok) {
            for (u32 i = 0; i < count; i++) {
                values->field_0[i].field_8 = a2[i];
                values->field_0[i].field_c = a3[i];
            }
            for (u32 i = count; i < values->Length(); i++) {
                values->field_0[i].field_8 = a2[count - 1];
                values->field_0[i].field_c = a3[count - 1];
            }
        }
    }
    return 1;
}

// What has the lists (the array is at 0x20) and a flag for "changed".
struct Unk_396b60_T {
    u8 _0[0x20];
    Unk_396ba0_T field_20;
    u8 _38[0x20];
    u8 field_58_0 : 1;
};
PKMN_SIZE_ASSERT(Unk_396ba0_T, 0x18);

// 0x7100396b60
void Unk_396b60(Unk_396b60_T* self, u64 key, f32 a2, f32 a3) {
    Unk_396ba0_Pair pair;
    pair.field_0.f = a3;
    pair.field_4.f = a2;
    Unk_396ba0(&self->field_20, key, &pair, 1);
    self->field_58_0 = true;
}

// 0x7100396d50
void Unk_396d50(Unk_396b60_T* self, u64 key, const Unk_396ba0_Pair* pairs, u32 count) {
    self->field_58_0 = true;
    Unk_396ba0(&self->field_20, key, pairs, count);
}

// 0x7100396d70
void Unk_396d70(Unk_396b60_T* self, u64 key, const Unk_396ba0_Number* a2,
                const Unk_396ba0_Number* a3, u32 count) {
    self->field_58_0 = true;
    Unk_396d90(&self->field_20, key, a2, a3, count);
}
