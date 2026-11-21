#pragma once
// The growable array whose allocator is part of the object: room for N items
// comes first, and the array only allocates when it needs more. The array's
// own code is that of containers.h and sorted_array.h, with the allocator's
// functions called on the object. Placeholder names.
#include "containers.h"

void* Unk_3046a0(int poolId, size_t size, u32 align);
u32 Unk_304740(int poolId, void* ptr);

// Room for N items of T, then the default pool's aligned allocations.
template <class T, u32 N>
struct Unk_HybridAlloc {
    u8 field_0[N * sizeof(T)];

    void* Alloc(size_t size) {
        if (size <= sizeof(field_0))
            return field_0;
        return Unk_3046a0(Unk_237e820, size, alignof(T));
    }

    void Free(void* items) {
        if (field_0 != items)
            Unk_304740(Unk_237e820, items);
    }
};

template <class T, class A, u32 GrowBy = 1>
struct Unk_AllocArray : A {
    T* field_0;  // items
    u32 field_8;  // length
    u32 field_c;  // reserved

    Unk_AllocArray() : field_0(nullptr), field_8(0), field_c(0) {}
    ~Unk_AllocArray() { Term(); }

    u32 Length() const { return field_8; }

    bool GrowArray(u32 growBy) {
        u32 reserved = field_c + growBy;
        T* items = static_cast<T*>(this->Alloc(sizeof(T) * reserved));
        if (items == nullptr)
            return false;
        u32 length = Length();
        if (field_0 != nullptr && field_0 != items) {
            for (u32 i = 0; i < length; i++) {
                new (items + i, Unk_Placement()) T;
                items[i] = field_0[i];
            }
            this->Free(field_0);
        }
        field_0 = items;
        field_c = reserved;
        return true;
    }

    inline T* AddLastGrow() {
        size_t length = Length();
        if (length >= field_c) {
            if (!GrowArray(GrowBy))
                return nullptr;
        }
        if (length < field_c) {
            T* end = field_0 + field_8++;
            new (end, Unk_Placement()) T;
            return end;
        }
        return nullptr;
    }

    // A new item at `index`, the ones from there on moved up.
    inline T* Insert(u32 index) {
        size_t length = Length();
        if (length >= field_c) {
            if (!GrowArray(GrowBy))
                return nullptr;
        }
        if (length < field_c) {
            T* end = field_0 + field_8++;
            new (end, Unk_Placement()) T;
            for (T* p = end; p > field_0 + index; --p)
                p[0] = p[-1];
            new (field_0 + index, Unk_Placement()) T;
            return field_0 + index;
        }
        return nullptr;
    }

    void RemoveAll() { field_8 = 0; }

    void Term() {
        if (field_0 != nullptr) {
            RemoveAll();
            this->Free(field_0);
            field_0 = nullptr;
            field_c = 0;
        }
    }
};

// The array kept sorted, its items their own keys.
template <class K, class A, u32 GrowBy = 1>
struct Unk_AllocSortedSet : Unk_AllocArray<K, A, GrowBy> {
    // The item of `key`, or where it would be (null in an array without items).
    K* BinarySearch(K key, bool& found) const {
        s32 top = 0;
        s32 bottom = this->Length() - 1;
        while (top <= bottom) {
            s32 mid = (bottom - top) / 2 + top;
            if (key < this->field_0[mid]) {
                bottom = mid - 1;
            } else if (key > this->field_0[mid]) {
                top = mid + 1;
            } else {
                found = true;
                return this->field_0 + mid;
            }
        }
        found = false;
        return this->field_0 != nullptr ? this->field_0 + top : nullptr;
    }

    // A new item where `key` belongs, whether the array has the key or not.
    // The caller sets it.
    K* AddNoSetKey(K key);

    K* Add(K key) {
        K* item = AddNoSetKey(key);
        if (item != nullptr)
            *item = key;
        return item;
    }
};

// Not inline: the executable has it out of line.
template <class K, class A, u32 GrowBy>
K* Unk_AllocSortedSet<K, A, GrowBy>::AddNoSetKey(K key) {
    bool found;
    K* item = BinarySearch(key, found);
    if (item != nullptr) {
        u32 index = static_cast<u32>(item - this->field_0);
        item = this->Insert(index);
    } else {
        item = this->AddLastGrow();
    }
    return item;
}
