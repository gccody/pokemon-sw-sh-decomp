// Scope: common
// Small functions of the range 0x710035ead0-0x71003b6ee0 that come in pairs
// of the same shape. Placeholder names.
#include "Unk_KeyArray.h"

u32 Unk_304740(int poolId, void* ptr);

// The pool's aligned allocations are freed with 0x7100304740.
struct Unk_PoolAligned {
    static void Free(void* ptr) { Unk_304740(Unk_237e820, ptr); }
};

// An array that only its Term is known of here.
template <class T, class A>
struct Unk_374dd0_Array {
    T* field_0;
    u32 field_8;
    u32 field_c;

    void Term() {
        if (field_0 != nullptr) {
            field_8 = 0;
            A::Free(field_0);
            field_0 = nullptr;
            field_c = 0;
        }
    }
};

// An item of the list of 0x7100374dd0: two arrays and a buffer.
struct Unk_374dd0_Item {
    Unk_374dd0_Item* field_0;  // next
    Unk_374dd0_Array<u8, Unk_PoolAligned> field_8;
    Unk_374dd0_Array<u8, Unk_PoolAligned> field_18;
    u32 field_28;
    u32 field_2c;
    void* field_30;

    void Term() {
        if (field_30 != nullptr)
            Unk_304740(Unk_237e820, field_30);
        field_2c = 0;
        field_30 = nullptr;
        field_8.Term();
        field_18.Term();
    }
};
PKMN_SIZE_ASSERT(Unk_374dd0_Item, 0x38);

// The list: a count, the last and the first item.
struct Unk_374dd0_List {
    u32 field_0;
    Unk_374dd0_Item* field_8;
    Unk_374dd0_Item* field_10;

    // Removes the item after `prev` (the first one when it is the first).
    void RemoveAfter(Unk_374dd0_Item* prev, Unk_374dd0_Item* item) {
        if (field_10 == item)
            field_10 = item->field_0;
        else
            prev->field_0 = item->field_0;
        if (field_8 == item)
            field_8 = prev;
        field_0--;
    }
};

// Frees the items after the one given, when that one uses less than half of
// what its first array has room for.
template <class Tag>
void Unk_374dd0(Tag* self, Unk_374dd0_List* list, Unk_374dd0_Item** from) {
    Unk_374dd0_Item* prev = *from;
    if (prev == nullptr || prev->field_8.field_8 >= prev->field_8.field_c / 2)
        return;
    Unk_374dd0_Item* item = prev->field_0;
    while (item != nullptr) {
        item->field_8.field_8 = 0;
        item->field_18.field_8 = 0;
        list->RemoveAfter(prev, item);
        Unk_374dd0_Item* next = prev->field_0;
        int pool = Unk_237e820;
        item->Term();
        Unk_3047c0(pool, item);
        item = next;
    }
}

struct Unk_374dd0_A;
struct Unk_374ed0_A;
// 0x7100374dd0
template void Unk_374dd0<Unk_374dd0_A>(Unk_374dd0_A*, Unk_374dd0_List*, Unk_374dd0_Item**);
// 0x7100374ed0
template void Unk_374dd0<Unk_374ed0_A>(Unk_374ed0_A*, Unk_374dd0_List*, Unk_374dd0_Item**);

// The object of 0x7100379b60: a list of entries that point back at it, and a
// reference count.
struct Unk_379440_T;
void Unk_379440(Unk_379440_T* self);

struct Unk_379b60_Entry {
    Unk_379b60_Entry* field_0;  // next
    struct Target {
        u8 _0[0x18];
        Unk_379440_T* field_18;
    }* field_8;
};

struct Unk_379440_T {
    Unk_379b60_Entry* field_0;
    u8 _8[0x20];
    u32 field_28;  // reference count

    void Release() {
        if (--field_28 == 0) {
            int pool = Unk_237e820;
            Unk_379440(this);
            Unk_3047c0(pool, this);
        }
    }
};

// What holds a reference to one: lets go of it, and the entries forget it.
template <class Tag>
struct Unk_379b60_Ref {
    Unk_379440_T* field_0;

    void Clear();
};

template <class Tag>
void Unk_379b60_Ref<Tag>::Clear() {
    if (field_0 != nullptr) {
        for (Unk_379b60_Entry* entry = field_0->field_0; entry != nullptr; entry = entry->field_0)
            entry->field_8->field_18 = nullptr;
        field_0->Release();
        field_0 = nullptr;
    }
}

struct Unk_379b60_A;
struct Unk_379be0_A;
// 0x7100379b60
template void Unk_379b60_Ref<Unk_379b60_A>::Clear();
// 0x7100379be0
template void Unk_379b60_Ref<Unk_379be0_A>::Clear();
