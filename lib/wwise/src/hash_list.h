#pragma once
// A hash table of items chained through a `next` member, by a `key` member.
// The table's size is one of Unk_HashPrimes. Placeholder names.
#include "containers.h"

template <class T, class A = Unk_PoolDefault>
struct Unk_HashListBare {
    Unk_Array<T*, A> field_0;  // buckets
    u32 field_10;  // number of items

    // Rebuilds the table with the first prime size above `size`: 1, or 2
    // when out of memory (the table is then left as it was).
    u32 Reserve(u32 size);
};

template <class T, class A>
u32 Unk_HashListBare<T, A>::Reserve(u32 size) {
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
                T* next = item->next;
                u32 bucket = item->key % prime;
                item->next = field_0.field_0[bucket];
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
