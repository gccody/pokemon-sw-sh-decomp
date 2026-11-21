#pragma once
// An array kept sorted by the key of its items, found by binary search.
// Reconstructed from the code it inlines into. Placeholder names.
#include "Unk_KeyArray.h"

template <class K, class T, class A = Unk_PoolDefault, u32 kGrowBy = 1,
          class M = Unk_AssignMove<T>>
struct Unk_SortedKeyArray : Unk_GrowArray<T, A, kGrowBy, const T&, M> {
    // The item with the key, or where one would go (null in an array
    // without items).
    T* BinarySearch(K key, bool& found) const {
        s32 top = 0;
        s32 bottom = this->Length() - 1;
        while (top <= bottom) {
            s32 middle = (bottom - top) / 2 + top;
            if (key < this->field_0[middle].key) {
                bottom = middle - 1;
            } else if (this->field_0[middle].key < key) {
                top = middle + 1;
            } else {
                found = true;
                return this->field_0 + middle;
            }
        }
        found = false;
        return this->field_0 != nullptr ? this->field_0 + top : nullptr;
    }

    // The item with the key, added when there is none.
    T* Set(K key) {
        bool found;
        T* item = BinarySearch(key, found);
        if (found)
            return item;
        if (item != nullptr) {
            u32 index = static_cast<u32>(item - this->field_0);
            item = this->Insert(index);
        } else {
            item = this->AddLast();
        }
        if (item != nullptr)
            item->key = key;
        return item;
    }
};
