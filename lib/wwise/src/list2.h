#pragma once
// Unk_List2 with its preallocation and the adding of an item at the end (the
// items are constructed when they are allocated). Placeholder names.
#include "containers.h"

template <class T>
struct Unk_List2Ex : Unk_List2<T> {
    typedef typename Unk_List2<T>::Item Item;

    // Preallocates `count` items.
    u32 Init(u32 count) {
        if (count != 0) {
            this->field_18 = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item) * count));
            if (this->field_18 != nullptr) {
                this->field_20 = count;
                this->field_10 = this->field_18;
                Item* p = this->field_10;
                for (u32 i = 0; i < this->field_20; i++) {
                    new (&p->item, Unk_Placement()) T;
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

    T& First() { return this->field_0->item; }

    T* AddLast() {
        if (this->field_10 == nullptr) {
            Item* p = static_cast<Item*>(Unk_3045e0(Unk_237e820, sizeof(Item)));
            if (p == nullptr)
                return nullptr;
            new (&p->item, Unk_Placement()) T;
            p->next = this->field_10;
            this->field_10 = p;
        }
        if (this->field_8 != nullptr)
            this->field_8->next = this->field_10;
        else
            this->field_0 = this->field_10;
        this->field_8 = this->field_10;
        this->field_10 = this->field_10->next;
        this->field_8->next = nullptr;
        this->field_24++;
        return &this->field_8->item;
    }

    void Term();
};

// Not inline: the executable has it out of line. Unk_List2's own ends with
// the free items' pointer cleared first; this one clears the three pointers
// in their order.
template <class T>
void Unk_List2Ex<T>::Term() {
    this->RemoveAll();
    for (Item* p = this->field_10; p != nullptr;) {
        Item* next = p->next;
        if (!this->IsPreallocated(p))
            Unk_3047c0(Unk_237e820, p);
        p = next;
    }
    if (this->field_18 != nullptr) {
        Unk_3047c0(Unk_237e820, this->field_18);
        this->field_18 = nullptr;
    }
    this->field_20 = 0;
    this->field_0 = nullptr;
    this->field_8 = nullptr;
    this->field_10 = nullptr;
}
