#pragma once
// What the League Card's views keep their parts in (each view's +0x58): tables
// of parts, animations and gflib3 objects, looked up by 8-byte keys.
// Placeholder names: rename them once the classes are known.
#include <types.h>

#include "gflib3/Unk_239a418.h"
#include "unsorted/Unk_2771620.h"

struct Unk_14aae90_Vec2 {
    f32 x;
    f32 y;
};

// Copies `from` into `to` field by field.
inline void Unk_14aae90_Copy(Unk_14aae90_Vec2* to, const Unk_14aae90_Vec2& from) {
    to->x = from.x;
    to->y = from.y;
}

// What a part's slot 11 returns: +0x18 holds where a part's object goes.
struct Unk_14ab9a0_Slot {
    u8 _0[0x8];
    void* field_8;
};
PKMN_OFFSET_ASSERT(Unk_14ab9a0_Slot, field_8, 0x8);

struct Unk_14ab9a0_Holder {
    u8 _0[0x18];
    Unk_14ab9a0_Slot* field_18;
};
PKMN_OFFSET_ASSERT(Unk_14ab9a0_Holder, field_18, 0x18);

// A part: +0x18 the part it's attached to, +0x48 and +0x50 two positions and
// +0x58 its flags (bit 0 set or cleared by 0x71014ab040, bit 4 set when a
// position changes).
class Unk_14aaec0_Part {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual Unk_14ab9a0_Holder* vf11(u32 arg);

    u8 _8[0x18 - 0x8];
    Unk_14aaec0_Part* field_18;
    u8 _20[0x48 - 0x20];
    Unk_14aae90_Vec2 field_48;
    Unk_14aae90_Vec2 field_50;
    u8 field_58;
};
PKMN_OFFSET_ASSERT(Unk_14aaec0_Part, field_18, 0x18);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Part, field_48, 0x48);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Part, field_50, 0x50);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Part, field_58, 0x58);

// An iterator over a table's entries. The lookups have the loop shape of a
// find_if over a one-pointer iterator class (the first iteration peeled), as in
// src/unsorted/Unk_14f76f0.cpp. Not trivially copyable: 0x71014ad670 returns
// one through x8.
template <class T>
struct Unk_14aaec0_Iter {
    T* ptr;

    Unk_14aaec0_Iter(T* p) : ptr(p) {}
    Unk_14aaec0_Iter(const Unk_14aaec0_Iter& other) : ptr(other.ptr) {}
    bool operator==(const Unk_14aaec0_Iter& other) const { return ptr == other.ptr; }
    bool operator!=(const Unk_14aaec0_Iter& other) const { return ptr != other.ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    Unk_14aaec0_Iter& operator++() {
        ++ptr;
        return *this;
    }
};

template <class Iter, class Pred>
inline Iter Unk_FindIf(Iter first, Iter last, Pred pred) {
    for (; first != last; ++first) {
        if (pred(*first))
            break;
    }
    return first;
}

// A table, 0xa0 bytes: its allocator, then (+0x40) its entries, their count
// and its capacity.
template <class T>
struct Unk_14aaec0_Table {
    Unk_2771620_Allocator<T> field_0;
    u8 _18[0x40 - 0x18];
    T* data;
    u64 size;
    u64 capacity;
    u8 _58[0xa0 - 0x58];

    Unk_14aaec0_Iter<T> begin() const { return Unk_14aaec0_Iter<T>(data); }
    Unk_14aaec0_Iter<T> end() const { return Unk_14aaec0_Iter<T>(data + size); }

    // Adds `value` at the end (0x71014ad670 when it's full). The full case is
    // the unlikely one, laid out after the return (as boost::container's
    // vector marks it).
    void Unk_PushBack(const T& value) {
        if (__builtin_expect(size < capacity, 1)) {
            field_0.construct(data + size, value);
            ++size;
        } else {
            Unk_14ad670(this, end(), 1, value);
        }
    }
};

// The parts' table.
struct Unk_14aaec0_Entry {
    u64 key;
    Unk_14aaec0_Part* part;
};
PKMN_SIZE_ASSERT(Unk_14aaec0_Entry, 0x10);

// Adds `count` copies of `value` at `pos`.
Unk_14aaec0_Iter<Unk_14aaec0_Entry> Unk_14ad670(Unk_14aaec0_Table<Unk_14aaec0_Entry>* table,
                                                const Unk_14aaec0_Iter<Unk_14aaec0_Entry>& pos,
                                                u64 count,
                                                const Unk_14aaec0_Entry& value);

// An animation: a layout (gflib3, 0x7100685xxx) and the animation's index in it.
struct Unk_14ab180_Anim {
    Unk_239a418_Ref2<Unk_239a418> layout;
    u32 index;
};
PKMN_SIZE_ASSERT(Unk_14ab180_Anim, 0x10);

struct Unk_14ab180_Entry {
    u64 key;
    Unk_14ab180_Anim anim;
};
PKMN_SIZE_ASSERT(Unk_14ab180_Entry, 0x18);

// The first table's entries: an object and a flag.
struct Unk_14abaf0_Entry {
    u64 key;
    Unk_239a418_Ref2<Unk_239a418> object;
    bool flag;
};
PKMN_SIZE_ASSERT(Unk_14abaf0_Entry, 0x18);

// The second table's entries: an object.
struct Unk_14abaa0_Entry {
    u64 key;
    Unk_239a418_Ref2<Unk_239a418> object;
};
PKMN_SIZE_ASSERT(Unk_14abaa0_Entry, 0x10);

// Add an entry to their tables.
void Unk_14acbd0(Unk_14aaec0_Table<Unk_14abaa0_Entry>* table, Unk_14abaa0_Entry&& entry);
void Unk_14acf30(Unk_14aaec0_Table<Unk_14abaf0_Entry>* table, Unk_14abaf0_Entry&& entry);
void Unk_14ad2d0(Unk_14aaec0_Table<Unk_14ab180_Entry>* table, Unk_14ab180_Entry&& entry);

struct Unk_14aaec0_Parts {
    u8 _0[0xa0];
    Unk_14aaec0_Table<Unk_14abaf0_Entry> field_a0;
    Unk_14aaec0_Table<Unk_14abaa0_Entry> field_140;
    Unk_14aaec0_Table<Unk_14aaec0_Entry> field_1e0;
    Unk_14aaec0_Table<Unk_14ab180_Entry> field_280;

    Unk_14ab180_Anim* Unk_14ab180(const u64& key);

    Unk_14aaec0_Part* Unk_GetPart(const u64& key) const {
        Unk_14aaec0_Iter<Unk_14aaec0_Entry> it =
            Unk_FindIf(field_1e0.begin(), field_1e0.end(),
                       [key](const Unk_14aaec0_Entry& e) { return e.key == key; });
        return it == field_1e0.end() ? nullptr : it->part;
    }
};
PKMN_OFFSET_ASSERT(Unk_14aaec0_Parts, field_a0, 0xa0);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Parts, field_140, 0x140);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Parts, field_1e0, 0x1e0);
PKMN_OFFSET_ASSERT(Unk_14aaec0_Parts, field_280, 0x280);
