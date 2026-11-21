#pragma once
// Unk_HashListBare (Unk_HashList.h) for the tables that allocate from another
// pool than the default one: A is the pool, P says where an item has its key
// and its link. Placeholder names.
#include "Unk_HashList.h"
#include "containers.h"

// Unk_HashListBare with the functions that find, add and remove items. K is
// the key's type; P also gives an item's whole key (Id) and a key's hash.
template <class K, class T, class P>
struct Unk_HashListBareEx : Unk_HashListBare<T, P> {
    T* ExistsInList(K key, u32 bucket) const {
        T* item = this->field_0.field_0[bucket];
        while (item != nullptr) {
            if (P::Id(item) != key)
                item = P::Next(item);
            else
                return item;
        }
        return nullptr;
    }

    T* Exists(K key) const {
        if (this->HashSize() > 0) {
            u32 bucket = P::Hash(key) % this->HashSize();
            return ExistsInList(key, bucket);
        }
        return nullptr;
    }

    // Grows a table that is more than 90% full.
    bool CheckSize() {
        if (this->HashSize() == 0 ||
            static_cast<f32>(this->field_10) / static_cast<f32>(this->HashSize()) > 0.9f)
            this->Reserve(this->HashSize());
        return this->HashSize() > 0;
    }

    bool Set(T* item) {
        if (CheckSize()) {
            u32 bucket = P::Hash(P::Id(item)) % this->HashSize();
            P::Next(item) = this->field_0.field_0[bucket];
            this->field_0.field_0[bucket] = item;
            ++this->field_10;
            return true;
        }
        return false;
    }

    struct Iterator {
        const Unk_FixedArray<T*>* table;
        u32 bucket;
        T* item;

        Iterator& operator++() {
            item = P::Next(item);
            while (item == nullptr && ++bucket < table->Length())
                item = table->field_0[bucket];
            return *this;
        }
        T* operator*() { return item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    // An iterator that also knows the item before it in its chain, for Erase.
    struct IteratorEx : Iterator {
        T* prev;

        IteratorEx& operator++() {
            prev = this->item;
            this->item = P::Next(this->item);
            if (this->item == nullptr) {
                prev = nullptr;
                while (++this->bucket < this->table->Length() &&
                       (this->item = this->table->field_0[this->bucket]) == nullptr) {
                }
            }
            return *this;
        }
    };

    Iterator Begin() const {
        Iterator it;
        if (this->HashSize() > 0) {
            it.table = &this->field_0;
            it.bucket = 0;
            it.item = this->field_0.field_0[0];
            while (it.item == nullptr && ++it.bucket < this->HashSize())
                it.item = this->field_0.field_0[it.bucket];
        } else {
            it.table = nullptr;
            it.bucket = 0;
            it.item = nullptr;
        }
        return it;
    }

    IteratorEx BeginEx() {
        IteratorEx it;
        if (this->HashSize() > 0) {
            it.table = &this->field_0;
            it.bucket = 0;
            it.item = this->field_0.field_0[0];
            it.prev = nullptr;
            while (it.item == nullptr && ++it.bucket < this->HashSize())
                it.item = this->field_0.field_0[it.bucket];
        } else {
            it.table = nullptr;
            it.bucket = 0;
            it.item = nullptr;
            it.prev = nullptr;
        }
        return it;
    }

    Iterator End() const {
        Iterator it;
        it.table = &this->field_0;
        it.bucket = this->HashSize();
        it.item = nullptr;
        return it;
    }

    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx next;
        next.table = it.table;
        next.bucket = it.bucket;
        next.item = P::Next(it.item);
        next.prev = it.prev;
        while (next.item == nullptr && ++next.bucket < next.table->Length()) {
            next.prev = nullptr;
            next.item = next.table->field_0[next.bucket];
        }
        RemoveItem(it.bucket, it.item, it.prev);
        return next;
    }

    void RemoveItem(u32 bucket, T* item, T* prev) {
        if (prev != nullptr)
            P::Next(prev) = P::Next(item);
        else
            this->field_0.field_0[bucket] = P::Next(item);
        --this->field_10;
    }

    void Unset(K key) {
        if (this->HashSize() > 0) {
            u32 bucket = P::Hash(key) % this->HashSize();
            T* item = this->field_0.field_0[bucket];
            T* prev = nullptr;
            while (item != nullptr) {
                if (P::Id(item) != key) {
                    prev = item;
                    item = P::Next(item);
                } else {
                    RemoveItem(bucket, item, prev);
                    break;
                }
            }
        }
    }
};

template <class T, class P, class A>
struct Unk_PoolHashListBare {
    Unk_Array<T*, A> field_0;  // buckets
    u32 field_10;  // number of items

    // Rebuilds the table with the first prime size above `size`: 1, or 2
    // when out of memory (the table is then left as it was).
    u32 Reserve(u32 size);
};

template <class T, class P, class A>
u32 Unk_PoolHashListBare<T, P, A>::Reserve(u32 size) {
    u32 prime = 0;
    for (u32 i = 0; i < sizeof(Unk_HashPrimes) / sizeof(Unk_HashPrimes[0]); i++) {
        if (size < Unk_HashPrimes[i]) {
            prime = Unk_HashPrimes[i];
            break;
        }
    }
    if (prime == 0)
        return 2;
    Unk_Array<T*, A> old;
    old.Transfer(field_0);
    if (field_0.GrowArray(prime)) {
        for (u32 i = 0; i < prime; i++)
            field_0.AddLast(nullptr);
        for (u32 i = 0; i < old.Length(); i++) {
            T* item = old.field_0[i];
            while (item != nullptr) {
                T* next = P::Next(item);
                u32 bucket = P::Key(item) % prime;
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
