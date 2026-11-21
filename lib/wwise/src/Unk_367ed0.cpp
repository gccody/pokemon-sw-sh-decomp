// Scope: common
// Pooled lists of the range 0x710035ead0-0x71003b6ee0: the Term of three of
// them. Placeholder names.
#include "list2.h"

// The pooled list with its pool as a parameter (Unk_List2Ex has the default
// pool's): the same Term.
template <class T, class A>
struct Unk_367ed0_List {
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

    // An item and the one before it.
    struct IteratorEx {
        Item* item;
        Item* prev;

        void operator++() {
            prev = item;
            item = item->next;
        }
    };

    IteratorEx BeginEx() const {
        IteratorEx it;
        it.item = field_0;
        it.prev = nullptr;
        return it;
    }

    // Preallocates `count` items: 1, or 0x34 without memory.
    u32 Init(u32 count) {
        field_18 = static_cast<Item*>(A::Alloc(sizeof(Item) * count));
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

    T* AddLast() {
        if (field_10 == nullptr) {
            Item* p = static_cast<Item*>(A::Alloc(sizeof(Item)));
            if (p == nullptr)
                return nullptr;
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

    void RemoveItem(Item* p, Item* prev) {
        if (p == field_0)
            field_0 = p->next;
        else
            prev->next = p->next;
        if (field_8 == p)
            field_8 = prev;
        FreeItem(p);
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

    void FreeItem(Item* p) {
        if (IsPreallocated(p)) {
            p->next = field_10;
            field_10 = p;
        } else {
            A::Free(p);
        }
    }

    void RemoveFirst() {
        Item* p = field_0;
        field_0 = p->next;
        if (field_8 == p)
            field_8 = nullptr;
        FreeItem(p);
        field_24--;
    }

    void RemoveAll() {
        while (field_0 != nullptr)
            RemoveFirst();
    }

    void Term();
};

template <class T, class A>
void Unk_367ed0_List<T, A>::Term() {
    RemoveAll();
    for (Item* p = field_10; p != nullptr;) {
        Item* next = p->next;
        if (!IsPreallocated(p))
            A::Free(p);
        p = next;
    }
    if (field_18 != nullptr) {
        A::Free(field_18);
        field_18 = nullptr;
    }
    field_20 = 0;
    field_0 = nullptr;
    field_8 = nullptr;
    field_10 = nullptr;
}

// What the list of 0x71024bcb50 holds: something a context asked for, and
// when.
struct Unk_3be850_Ctx;
struct Unk_367ed0_Item {
    Unk_3be850_Ctx* field_0;
    u32 field_8;
    u16 field_c_0 : 8;
    u16 field_c_8 : 1;
};
PKMN_SIZE_ASSERT(Unk_367ed0_Item, 0x10);
struct Unk_3b4190_Item {
    u64 field_0;
    u64 field_8;
};
struct Unk_395cb0_Item {
    u64 field_0;
};

// 0x7100367ed0
template void Unk_367ed0_List<Unk_367ed0_Item, Unk_Pool2381488>::Term();
// 0x71003b4190
template void Unk_List2Ex<Unk_3b4190_Item>::Term();
// 0x7100395cb0
template void Unk_List2Ex<Unk_395cb0_Item>::Term();

typedef Unk_367ed0_List<Unk_367ed0_Item, Unk_Pool2381488> Unk_367ed0_Requests;
Unk_367ed0_Requests Unk_24bcb50;
u32 Unk_24bcb48;
u64 Unk_24bcb38[2];
u8 Unk_24bcb78;

// 0x7100367e30
u32 Unk_367e30() {
    Unk_24bcb48 = 0;
    return Unk_24bcb50.Init(0x200);
}

// 0x7100367eb0
void Unk_367eb0() {
    Unk_24bcb38[0] = 0;
    Unk_24bcb38[1] = 0;
    Unk_24bcb50.Term();
}

// 0x7100367fe0: forgets what a context asked for.
void Unk_367fe0(Unk_3be850_Ctx* ctx) {
    for (auto it = Unk_24bcb50.BeginEx(); it.item != nullptr;) {
        if (it.item->item.field_0 == ctx)
            it = Unk_24bcb50.Erase(it);
        else
            ++it;
    }
}

// 0x71003680c0: 1, or 2 without memory.
u32 Unk_3680c0(u32 type, Unk_3be850_Ctx* ctx) {
    Unk_367ed0_Item* item = Unk_24bcb50.AddLast();
    if (item == nullptr)
        return 2;
    item->field_0 = ctx;
    item->field_8 = Unk_24bcb48;
    item->field_c_0 = type;
    item->field_c_8 = 0;
    if (type <= 1)
        Unk_24bcb78 = 1;
    return 1;
}
