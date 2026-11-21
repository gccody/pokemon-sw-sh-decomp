#pragma once
// A singly linked list of values found by their keys, whose removed items go
// to a free list (unlike Unk_List2, which frees the ones it allocated one at
// a time). Same layout as Unk_List2. Placeholder names.
#include "containers.h"

template <class K, class V>
struct Unk_KeyList {
    struct Pair {
        K key;
        V item;
    };

    struct Item {
        Item* next;
        Pair item;
    };

    Item* field_0;  // first
    Item* field_8;  // last
    Item* field_10;  // free items
    Item* field_18;  // preallocated items
    u32 field_20;  // number of preallocated items
    u32 field_24;  // number of items

    // Preallocates `count` items.
    u32 Init(u32 count) {
        if (count != 0) {
            field_18 = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item) * count));
            if (field_18 != nullptr) {
                field_20 = count;
                field_10 = field_18;
                Item* p = field_10;
                for (u32 i = 0; i < field_20; i++) {
                    new (&p->item, Unk_Placement()) Pair;
                    p->next = p + 1;
                    p++;
                }
                (p - 1)->next = nullptr;
            } else {
                return 0x34;
            }
        }
        return 1;
    }

    struct Iterator {
        Item* item;

        Iterator& operator++() {
            item = item->next;
            return *this;
        }
        Pair& operator*() { return item->item; }
        bool operator==(const Iterator& other) const { return item == other.item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }
    };

    Iterator Begin() {
        Iterator it;
        it.item = field_0;
        return it;
    }

    Iterator End() {
        Iterator it;
        it.item = nullptr;
        return it;
    }

    V* Exists(K key) {
        for (Iterator it = Begin(); it != End(); ++it) {
            if ((*it).key == key)
                return &(*it).item;
        }
        return nullptr;
    }

    Pair* AddLast() {
        if (field_10 == nullptr) {
            Item* p = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item)));
            if (p == nullptr)
                return nullptr;
            new (&p->item, Unk_Placement()) Pair;
            p->next = field_10;
            field_10 = p;
        }
        if (field_8 != nullptr)
            field_8->next = field_10;
        else
            field_0 = field_10;
        field_8 = field_10;
        field_10 = field_10->next;
        field_8->next = nullptr;
        field_24++;
        return &field_8->item;
    }

    // The item of `key`, added when the list doesn't have it.
    V* Set(K key) {
        V* item = Exists(key);
        if (item != nullptr)
            return item;
        Pair* pair = AddLast();
        if (pair != nullptr) {
            pair->key = key;
            return &pair->item;
        }
        return nullptr;
    }

    void RemoveFirst() {
        Item* p = field_0;
        field_0 = p->next;
        if (field_8 == p)
            field_8 = nullptr;
        p->next = field_10;
        field_10 = p;
        field_24--;
    }

    void RemoveAll() {
        while (field_0 != nullptr)
            RemoveFirst();
    }

    bool IsPreallocated(Item* p) const { return field_18 <= p && field_18 + field_20 > p; }

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
