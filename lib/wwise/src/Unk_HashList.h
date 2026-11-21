#pragma once
// The hash table of intrusive items: an array of buckets (the first item of
// each chain) and the number of items. Reconstructed from the code it inlines
// into; P says where an item has its key and its link. Placeholder names.
#include "Unk_KeyArray.h"

// An array that doesn't grow by itself.
template <class T, class A = Unk_PoolDefault>
struct Unk_FixedArray : Unk_GrowArray<T, A, 0> {

    // Takes the other array's items, which it loses.
    void Transfer(Unk_FixedArray& other) {
        this->Term();
        this->field_0 = other.field_0;
        this->field_8 = other.field_8;
        this->field_c = other.field_c;
        other.field_0 = nullptr;
        other.field_8 = 0;
        other.field_c = 0;
    }
};

template <class T, class P>
struct Unk_HashListBare {
    Unk_FixedArray<T*> field_0;  // buckets
    u32 field_10;  // number of items

    u32 HashSize() const { return field_0.Length(); }

    // 1 when the table has at least `size` buckets (a prime), 2 when it
    // couldn't be allocated.
    u32 Reserve(u32 size) {
        u32 newSize = 0;
        for (u32 i = 0; i < sizeof(Unk_HashPrimes) / sizeof(Unk_HashPrimes[0]); i++) {
            if (Unk_HashPrimes[i] > size) {
                newSize = Unk_HashPrimes[i];
                break;
            }
        }
        if (newSize == 0)
            return 2;
        Unk_FixedArray<T*> old;
        old.field_0 = nullptr;
        old.field_8 = 0;
        old.field_c = 0;
        old.Transfer(field_0);
        if (field_0.GrowArray(newSize)) {
            for (u32 i = 0; i < newSize; i++)
                field_0.AddLast(nullptr);
            for (u32 i = 0; i < old.Length(); i++) {
                T* item = old.field_0[i];
                while (item != nullptr) {
                    T* next = P::Next(item);
                    u32 bucket = P::Key(item) % newSize;
                    P::Next(item) = field_0.field_0[bucket];
                    field_0.field_0[bucket] = item;
                    item = next;
                }
            }
            old.Term();
            return 1;
        }
        field_0.Transfer(old);
        return 2;
    }
};

// The hash table that owns its items: a word before the buckets, and the
// bucket of an item computed from the table's length.
template <class T, class P>
struct Unk_HashList {
    u64 field_0;
    Unk_FixedArray<T*> field_8;  // buckets
    u32 field_18;  // number of items

    u32 HashSize() const { return field_8.Length(); }

    u32 Reserve(u32 size) {
        u32 newSize = 0;
        for (u32 i = 0; i < sizeof(Unk_HashPrimes) / sizeof(Unk_HashPrimes[0]); i++) {
            if (Unk_HashPrimes[i] > size) {
                newSize = Unk_HashPrimes[i];
                break;
            }
        }
        if (newSize == 0)
            return 2;
        Unk_FixedArray<T*> old;
        old.field_0 = nullptr;
        old.field_8 = 0;
        old.field_c = 0;
        old.Transfer(field_8);
        if (field_8.GrowArray(newSize)) {
            for (u32 i = 0; i < newSize; i++)
                field_8.AddLast(nullptr);
            for (u32 i = 0; i < old.Length(); i++) {
                T* item = old.field_0[i];
                while (item != nullptr) {
                    T* next = P::Next(item);
                    u32 bucket = P::Key(item) % HashSize();
                    P::Next(item) = field_8.field_0[bucket];
                    field_8.field_0[bucket] = item;
                    item = next;
                }
            }
            old.Term();
            return 1;
        }
        field_8.Transfer(old);
        return 2;
    }
};
