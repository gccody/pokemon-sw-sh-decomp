#pragma once
// A pool of objects of one type, allocated in chunks of N: a chunk is freed
// once all its blocks are free again. Placeholder names.
#include "containers.h"

// What a list keeps besides its first item: the number of items or not...
template <class T>
struct Unk_ListCount {
    u32 field_0;  // number of items

    void Increment() { ++field_0; }
    void Decrement() { --field_0; }
    void Reset() { field_0 = 0; }
};

template <class T>
struct Unk_ListNoCount {
    void Increment() {}
    void Decrement() {}
    void Reset() {}
};

// ... and the last item or not.
template <class T>
struct Unk_ListLast {
    T* last;

    T* GetLast() { return last; }
    void SetLast(T* item) { last = item; }
    void RemoveItem(T* item, T* prev) {
        if (item == last)
            last = prev;
    }
};

template <class T>
struct Unk_ListNoLast {
    void SetLast(T*) {}
    void RemoveItem(T*, T*) {}
};

// Where an item's next one is.
template <class T>
struct Unk_ListNext {
    static T*& Get(T* item) { return item->next; }
};

// A list through the items' `next`: what it keeps comes before the first
// item. `RemoveFirst` stores the next item or null in two branches: what
// keeps the stores apart is that the next item is read through a function
// (the load that only feeds a store becomes an integer load before the
// inliner runs) and that a call follows the store of null.
template <class T, template <class> class Count, template <class> class Last>
struct Unk_ListPolicy : Count<T>, Last<T> {
    T* first;

    void AddFirst(T* item) {
        if (first == nullptr) {
            first = item;
            Last<T>::SetLast(item);
            Unk_ListNext<T>::Get(item) = nullptr;
        } else {
            Unk_ListNext<T>::Get(item) = first;
            first = item;
        }
        Count<T>::Increment();
    }

    // For a list that keeps its last item.
    void AddLast(T* item) {
        Unk_ListNext<T>::Get(item) = nullptr;
        if (first == nullptr)
            first = item;
        else
            Unk_ListNext<T>::Get(Last<T>::GetLast()) = item;
        Last<T>::SetLast(item);
        Count<T>::Increment();
    }

    void RemoveFirst() {
        if (Unk_ListNext<T>::Get(first) == nullptr) {
            first = nullptr;
            Last<T>::SetLast(nullptr);
        } else {
            first = Unk_ListNext<T>::Get(first);
        }
        Count<T>::Decrement();
    }

    struct Iterator {
        T* item;

        Iterator& operator++() {
            item = Unk_ListNext<T>::Get(item);
            return *this;
        }
        T* operator*() const { return item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    // An iterator that knows the item before its own, for `Erase`.
    struct IteratorEx : Iterator {
        T* prev;

        IteratorEx& operator++() {
            prev = this->item;
            this->item = Unk_ListNext<T>::Get(this->item);
            return *this;
        }
    };

    Iterator Begin() {
        Iterator it;
        it.item = first;
        return it;
    }

    IteratorEx BeginEx() {
        IteratorEx it;
        it.item = first;
        it.prev = nullptr;
        return it;
    }

    Iterator End() {
        Iterator it;
        it.item = nullptr;
        return it;
    }

    IteratorEx FindEx(T* item) {
        IteratorEx it = BeginEx();
        for (; it != End(); ++it) {
            if (it.item == item)
                break;
        }
        return it;
    }

    void RemoveItem(T* item, T* prev) {
        if (item == first)
            first = Unk_ListNext<T>::Get(item);
        else
            Unk_ListNext<T>::Get(prev) = Unk_ListNext<T>::Get(item);
        Last<T>::RemoveItem(item, prev);
        Count<T>::Decrement();
    }

    // Removes the iterator's item: the result is at the next one.
    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx result;
        result.item = Unk_ListNext<T>::Get(it.item);
        result.prev = it.prev;
        RemoveItem(it.item, it.prev);
        return result;
    }

    void Remove(T* item) {
        IteratorEx it = FindEx(item);
        if (it != End())
            Erase(it);
    }

    bool IsEmpty() const { return first == nullptr; }
    T* First() { return first; }

    // Forgets the items.
    void RemoveAll() {
        Count<T>::Reset();
        first = nullptr;
        Last<T>::SetLast(nullptr);
    }
};

// With the number of items and no last item.
template <class T>
struct Unk_ListLight : Unk_ListPolicy<T, Unk_ListCount, Unk_ListNoLast> {};

// With the last item and no count.
template <class T>
struct Unk_ListWithLast : Unk_ListPolicy<T, Unk_ListNoCount, Unk_ListLast> {};

template <class T, u32 N, class A = Unk_PoolDefault>
struct Unk_BlockPool {
    union Block {
        Block* next;
        char data[sizeof(T)];
    };

    struct Chunk {
        Block field_0[N];
        Chunk* next;
        Unk_ListLight<Block> field_free;

        bool BelongsTo(Block* block) const {
            return reinterpret_cast<u64>(block) >= reinterpret_cast<u64>(field_0) &&
                   reinterpret_cast<u64>(block) < reinterpret_cast<u64>(field_0) + sizeof(field_0);
        }
        bool AllFree() const { return field_free.field_0 == N; }
    };

    Chunk* field_0;  // the chunks

    void Delete(T* item) {
        item->~T();
        Free(item);
    }

    void Free(void* item) {
        Block* block = static_cast<Block*>(item);
        Chunk* chunk = nullptr;
        Chunk* prev = nullptr;
        chunk = field_0;
        while (chunk != nullptr) {
            if (chunk->BelongsTo(block))
                break;
            prev = chunk;
            chunk = chunk->next;
        }
        chunk->field_free.AddFirst(block);
        if (chunk->AllFree()) {
            if (field_0 == chunk)
                field_0 = chunk->next;
            else
                prev->next = chunk->next;
            A::Free(chunk);
        }
    }
};
