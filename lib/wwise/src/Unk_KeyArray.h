#pragma once
// A growable array that grows by itself, and the array of keyed items built
// on it, reconstructed from the code they inline into. Placeholder names.
#include "Unk_PlacementNew.h"
#include "containers.h"

// How an array moves an item to another place: by assignment, or by handing
// over what the item owns.
template <class T>
struct Unk_AssignMove {
    static void Move(T& dest, T& src) { dest = src; }
};

template <class T>
struct Unk_TransferMove {
    static void Move(T& dest, T& src) { dest.Transfer(src); }
};

// Unk_Array with an AddLast that grows the array by kGrowBy items when it is
// full.
template <class T, class A = Unk_PoolDefault, u32 kGrowBy = 1, class ArgT = const T&,
          class M = Unk_AssignMove<T>>
struct Unk_GrowArray : Unk_Array<T, A> {
    struct Iterator {
        T* item;

        Iterator& operator++() {
            ++item;
            return *this;
        }
        T& operator*() { return *item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    bool IsEmpty() const { return this->field_8 == 0; }

    Iterator Begin() const {
        Iterator it;
        it.item = this->field_0;
        return it;
    }

    Iterator End() const {
        Iterator it;
        it.item = this->field_0 + this->field_8;
        return it;
    }

    static void Move(T& dest, T& src) { M::Move(dest, src); }

    void RemoveAll() {
        for (Iterator it = Begin(), end = End(); it != end; ++it)
            (*it).~T();
        this->field_8 = 0;
    }

    void Term() {
        if (this->field_0 != nullptr) {
            RemoveAll();
            A::Free(this->field_0);
            this->field_0 = nullptr;
            this->field_c = 0;
        }
    }

    // Takes the other array's items, which it loses.
    void Transfer(Unk_GrowArray& other) {
        Term();
        this->field_0 = other.field_0;
        this->field_8 = other.field_8;
        this->field_c = other.field_c;
        other.field_0 = nullptr;
        other.field_8 = 0;
        other.field_c = 0;
    }

    bool GrowArray(u32 growBy = kGrowBy) {
        u32 reserved = this->field_c + growBy;
        T* items = static_cast<T*>(A::Alloc(sizeof(T) * reserved));
        if (items == nullptr)
            return false;
        size_t length = this->Length();
        if (this->field_0 != nullptr && this->field_0 != items) {
            for (size_t i = 0; i < length; i++) {
                Unk_PlacementNew(items + i) T;
                Move(items[i], this->field_0[i]);
                this->field_0[i].~T();
            }
            A::Free(this->field_0);
        }
        this->field_0 = items;
        this->field_c = reserved;
        return true;
    }

    T* AddLast() {
        size_t length = this->Length();
        if (length >= this->field_c && kGrowBy > 0) {
            if (!GrowArray(kGrowBy))
                return nullptr;
        }
        if (length < this->field_c)
            return Unk_PlacementNew(this->field_0 + this->field_8++) T;
        return nullptr;
    }

    // A new item at `index`, the ones from there on moved up.
    T* Insert(u32 index) {
        size_t length = this->Length();
        if (length >= this->field_c && kGrowBy > 0) {
            if (!GrowArray(kGrowBy))
                return nullptr;
        }
        if (length < this->field_c) {
            T* last = this->field_0 + this->field_8++;
            Unk_PlacementNew(last) T;
            for (T* item = last; item > this->field_0 + index; --item)
                Move(item[0], item[-1]);
            (this->field_0 + index)->~T();
            Unk_PlacementNew(this->field_0 + index) T;
            return this->field_0 + index;
        }
        return nullptr;
    }

    // Removes the item, moving the ones after it down.
    Iterator Erase(Iterator& it) {
        T* last = this->field_0 + this->field_8 - 1;
        for (T* item = it.item; item < last; item++)
            Move(item[0], item[1]);
        this->field_8--;
        return it;
    }

    T* AddLast(ArgT item) {
        T* added = AddLast();
        if (added != nullptr)
            *added = item;
        return added;
    }

    // Room for `count` items in an empty array: 1, or 0x34 without memory.
    u32 Reserve(u32 count) {
        if (count != 0) {
            this->field_0 = static_cast<T*>(A::Alloc(sizeof(T) * count));
            if (this->field_0 == nullptr)
                return 0x34;
            this->field_c = count;
        }
        return 1;
    }
};

template <class K, class T>
struct Unk_KeyArrayItem {
    K key;
    T item;
};

// An array of items with a key each.
template <class K, class T, class A = Unk_PoolDefault, u32 kGrowBy = 1>
struct Unk_KeyArray : Unk_GrowArray<Unk_KeyArrayItem<K, T>, A, kGrowBy> {
    typedef Unk_KeyArrayItem<K, T> Item;
    typedef typename Unk_GrowArray<Item, A, kGrowBy>::Iterator Iterator;

    Iterator FindEx(K key) const {
        Iterator it = this->Begin();
        for (Iterator end = this->End(); it != end; ++it) {
            if (it.item->key == key)
                break;
        }
        return it;
    }

    T* Exists(K key) const {
        Iterator it = FindEx(key);
        return it != this->End() ? &it.item->item : nullptr;
    }

    T* Set(K key) {
        T* found = Exists(key);
        if (found != nullptr)
            return found;
        Item* added = this->AddLast();
        if (added != nullptr) {
            added->key = key;
            return &added->item;
        }
        return nullptr;
    }

    void Unset(K key) {
        Iterator it = FindEx(key);
        if (it != this->End())
            this->Erase(it);
    }

    T* Set(K key, const T& item) {
        T* found = Exists(key);
        if (found != nullptr) {
            *found = item;
            return found;
        }
        Item* added = this->AddLast();
        if (added != nullptr) {
            added->key = key;
            added->item = item;
            return &added->item;
        }
        return nullptr;
    }
};
