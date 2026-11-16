// Scope: common
#include <types.h>

// Placeholder types: a 0x18-byte slot, the begin/end range that holds them and
// an iterator over it. The iterator is inferred from the code: the searches
// have the loop shape of a find_if over a one-pointer iterator class (the first
// iteration peeled), not over raw pointers.
struct Unk_14f76f0 {
    u64 field_0;
    bool field_8;
    s32 field_c;
    u64 field_10;
};
PKMN_OFFSET_ASSERT(Unk_14f76f0, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_14f76f0, field_c, 0xc);
PKMN_SIZE_ASSERT(Unk_14f76f0, 0x18);

struct Unk_14f76f0_Iter {
    Unk_14f76f0* ptr;

    Unk_14f76f0_Iter(Unk_14f76f0* p) : ptr(p) {}
    bool operator==(const Unk_14f76f0_Iter& other) const { return ptr == other.ptr; }
    bool operator!=(const Unk_14f76f0_Iter& other) const { return ptr != other.ptr; }
    Unk_14f76f0& operator*() const { return *ptr; }
    Unk_14f76f0_Iter& operator++() {
        ++ptr;
        return *this;
    }
};
PKMN_SIZE_ASSERT(Unk_14f76f0_Iter, 0x8);

struct Unk_14f76f0_Range {
    Unk_14f76f0* field_0;
    Unk_14f76f0* field_8;

    Unk_14f76f0_Iter begin() { return Unk_14f76f0_Iter(field_0); }
    Unk_14f76f0_Iter end() { return Unk_14f76f0_Iter(field_8); }

    Unk_14f76f0* find(const u64& key);
};
PKMN_SIZE_ASSERT(Unk_14f76f0_Range, 0x10);

template <class Iter, class Pred>
static inline Iter findIf(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first) {
        if (pred(*first))
            break;
    }
    return first;
}

// Inlined into 0x71014f7a50. As a member of the range (rather than written out
// in the caller like findFree below), the debug value of the inlined begin()
// survives as a DBG_VALUE between the two loads, so with -g they stay two ldr
// (one ldp with -g0). The exits' `cmp; csel; ret` tail is duplicated only at -O3.
inline Unk_14f76f0* Unk_14f76f0_Range::find(const u64& key) {
    Unk_14f76f0_Iter it =
        findIf(begin(), end(), [&](const Unk_14f76f0& slot) { return slot.field_0 == key; });
    return it == end() ? nullptr : &*it;
}

struct Unk_14f7960 {
    Unk_14f76f0_Range* field_0;
};
PKMN_SIZE_ASSERT(Unk_14f7960, 0x8);

// 0x71014f76f0
void Unk_14f76f0_set(Unk_14f76f0* self, s32 value) {
    self->field_c = value;
    self->field_8 = false;
}

// 0x71014f7700
void Unk_14f76f0_clear(Unk_14f76f0* self) {
    self->field_c = -1;
    self->field_8 = true;
}

static Unk_14f76f0* findFree(Unk_14f7960* self) {
    Unk_14f76f0_Range* range = self->field_0;
    Unk_14f76f0_Iter it =
        findIf(range->begin(), range->end(), [](const Unk_14f76f0& slot) { return slot.field_8; });
    return it == range->end() ? nullptr : &*it;
}

// 0x71014f7960 - begin/end loaded with ldp here, unlike 0x71014f7a50.
Unk_14f76f0* Unk_14f7960_setFirstFree(Unk_14f7960* self, s32 value) {
    Unk_14f76f0* slot = findFree(self);
    Unk_14f76f0_set(slot, value);
    return slot;
}

// 0x71014f79b0 (Shield 0x71014f7a50)
// The `cmp; csel; ret` tail is duplicated only at -O3 (-O2/-Os share it). Even
// with the -O3 tail-duplication threshold, -O2 still differs (as in 0x71014f7960).
Unk_14f76f0* Unk_14f7960_findUsed(Unk_14f7960* self, s32 value) {
    Unk_14f76f0_Range* range = self->field_0;
    Unk_14f76f0_Iter it = findIf(range->begin(), range->end(), [&](const Unk_14f76f0& slot) {
        return slot.field_c == value && !slot.field_8;
    });
    return it == range->end() ? nullptr : &*it;
}

// 0x71014f7a20
void Unk_14f7960_clearAll(Unk_14f7960* self) {
    for (Unk_14f76f0& slot : *self->field_0)
        Unk_14f76f0_clear(&slot);
}

// 0x71014f7a50 (Shield 0x71014f7af0) - begin/end are two ldr here, one ldp in
// 0x71014f7960.
Unk_14f76f0* Unk_14f7960_find(Unk_14f7960* self, const u64& key) {
    return self->field_0->find(key);
}

// 0x71014f7ab0
s32 Unk_14f7960_count(Unk_14f7960* self) {
    Unk_14f76f0_Range* range = self->field_0;
    return range->field_8 - range->field_0;
}
