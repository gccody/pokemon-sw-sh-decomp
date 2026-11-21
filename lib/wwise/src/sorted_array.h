#pragma once
// A growable array kept sorted by its items' keys. Placeholder names.
#include "containers.h"

// An item that is its own key.
template <class K>
struct Unk_KeyIsItem {
    static K& Get(K& item) { return item; }
};

// An item with a `key` member.
template <class K, class T>
struct Unk_KeyIsMember {
    static K& Get(T& item) { return item.key; }
};

template <class K, class T, class GetKey, class A = Unk_PoolDefault, u32 GrowBy = 1>
struct Unk_SortedKeyArray : Unk_Array<T, A, GrowBy> {
    // The item of `key`, or where it would be (null in an array without items).
    T* BinarySearch(K key, bool& found) const {
        s32 top = 0;
        s32 bottom = this->Length() - 1;
        while (top <= bottom) {
            s32 mid = (bottom - top) / 2 + top;
            if (key < GetKey::Get(this->field_0[mid])) {
                bottom = mid - 1;
            } else if (key > GetKey::Get(this->field_0[mid])) {
                top = mid + 1;
            } else {
                found = true;
                return this->field_0 + mid;
            }
        }
        found = false;
        return this->field_0 != nullptr ? this->field_0 + top : nullptr;
    }

    T* Exists(K key) const {
        bool found;
        T* item = BinarySearch(key, found);
        return found ? item : nullptr;
    }

    void Unset(K key) {
        bool found;
        T* item = BinarySearch(key, found);
        if (found) {
            typename Unk_Array<T, A, GrowBy>::Iterator it;
            it.item = item;
            this->Erase(it);
        }
    }

    // A new item where `key` belongs, whether the array has the key or not.
    // The caller sets its key.
    T* AddNoSetKey(K key) {
        bool found;
        T* item = BinarySearch(key, found);
        if (item != nullptr) {
            u32 index = static_cast<u32>(item - this->field_0);
            item = this->Insert(index);
        } else {
            item = this->AddLastGrow();
        }
        return item;
    }

    // A new item of `key`, whether the array has the key or not.
    T* Add(K key) {
        T* item = AddNoSetKey(key);
        if (item != nullptr)
            GetKey::Get(*item) = key;
        return item;
    }

    // The item of `key`, added when the array doesn't have it.
    T* Set(K key) {
        bool found;
        T* item = BinarySearch(key, found);
        if (found)
            return item;
        if (item != nullptr) {
            u32 index = static_cast<u32>(item - this->field_0);
            item = this->Insert(index);
        } else {
            item = this->AddLastGrow();
        }
        if (item != nullptr)
            GetKey::Get(*item) = key;
        return item;
    }
};
