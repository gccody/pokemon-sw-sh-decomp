#pragma once
// The pooled list (Unk_List2 of containers.h) in the flavour that keeps its
// items: a removed item always goes back to the free list, and only Term
// frees the ones that aren't in the preallocated block. Placeholder names.
#include "containers.h"

template <class T>
struct Unk_List2Keep {
    struct Item {
        Item* next;
        T item;
    };

    Item* field_0;  // first
    Item* field_8;  // last
    Item* field_10;  // free items
    Item* field_18;  // preallocated items
    u32 field_20;  // number of preallocated items
    u32 field_24;  // number of items

    // 1, or 0x34 when the block couldn't be allocated.
    u32 Init(u32 count) {
        field_18 = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item) * count));
        if (field_18 == nullptr)
            return 0x34;
        field_10 = field_18;
        field_20 = count;
        Item* p = field_18;
        for (u32 i = 0; i < field_20; i++) {
            p->next = p + 1;
            p++;
        }
        (p - 1)->next = nullptr;
        return 1;
    }

    // An item and the one before it.
    struct IteratorEx {
        Item* item;
        Item* prev;
    };

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_0;
        it.prev = nullptr;
        return it;
    }

    void RemoveItem(Item* p, Item* prev) {
        if (p == field_0)
            field_0 = p->next;
        else
            prev->next = p->next;
        if (field_8 == p)
            field_8 = prev;
        p->next = field_10;
        field_10 = p;
        field_24--;
    }

    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx next;
        next.item = it.item->next;
        next.prev = it.prev;
        RemoveItem(it.item, it.prev);
        return next;
    }

    bool IsPreallocated(Item* p) const { return field_18 <= p && field_18 + field_20 > p; }

    void RemoveFirst() {
        Item* p = field_0;
        field_0 = p->next;
        if (field_8 == p)
            field_8 = nullptr;
        p->next = field_10;
        field_24--;
        field_10 = p;
    }

    void RemoveAll() {
        while (field_0 != nullptr)
            RemoveFirst();
    }

    void Term() {
        RemoveAll();
        for (Item* p = field_10; p != nullptr;) {
            Item* next = p->next;
            if (!IsPreallocated(p))
                Unk_3047c0(Unk_237e820, p);
            p = next;
        }
        if (field_18 != nullptr) {
            Unk_3047c0(Unk_237e820, field_18);
            field_18 = nullptr;
        }
        field_20 = 0;
        field_0 = nullptr;
        field_8 = nullptr;
        field_10 = nullptr;
    }
};
