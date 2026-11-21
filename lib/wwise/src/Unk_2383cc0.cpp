// Scope: common
// The owner of the items (vtable 0x7102383cc0). Written from the executable.
// Placeholder names.
#include "Unk_2383cc0.h"

// 0x71003c2cb0
Unk_2383cc0::Unk_2383cc0() {
    Unk_2383cc0_SetVptr(this, Unk_2383cc0_Vtable);
    field_8.first = nullptr;
    field_10.field_0 = nullptr;
    field_10.field_8 = 0;
    field_10.field_c = 0;
    field_20.last = nullptr;
    field_20.first = nullptr;
}

// 0x71003c2cd0
// NON_MATCHING: the array's part is the original's. In the loop that empties
// the list, the original goes on with the next item it saved and only
// compares it with the list's first one (a trap when they differ); here the
// first one, read again, is what goes on, and the trap's block is merged (8
// bytes less).
Unk_2383cc0::~Unk_2383cc0() {
    Unk_2383cc0_SetVptr(this, Unk_2383cc0_Vtable);
    auto it = field_10.Begin();
    while (it != field_10.End()) {
        if ((*it).item.first == nullptr)
            it = field_10.Erase(it);
        else
            ++it;
    }
    field_10.Term();
    for (Unk_3c44e0_Use* p = field_20.first; p != nullptr;) {
        Unk_3c44e0_Use* next = p->next;
        Unk_3c44e0_T* object = p->field_10;
        field_20.RemoveItem(p, nullptr);
        object->field_10 = nullptr;
        Unk_3c5180(p);
        Unk_3c4880(p);
        p = next;
    }
}

// 0x71003c2ec0
void Unk_3c2ec0(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    self->field_8.AddFirst(item);
}

// 0x71003c2ee0
void Unk_3c2ee0(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    self->field_8.Remove(item);
}

struct Unk_2383c58_T;
void Unk_3c3020(Unk_2383cc0* self, Unk_2383c58_Item* item, u32* arg2, u32 arg3, u32 arg4,
                bool arg5);
void Unk_3c33f0(Unk_2383cc0* self, u32 count);

// 0x71003c2f40 was named with the derived class: passes the events on, then
// lets the time go on
void Unk_3c2f40(Unk_2383c58_T* object, Unk_3c2490_Pair* events, u32 count) {
    Unk_2383cc0* self = reinterpret_cast<Unk_2383cc0*>(object);
    while (!events->IsEmpty()) {
        Unk_3c2f40_Event* event = events->First();
        events->RemoveFirst();
        if (!event->field_10_30 && event->field_10_31)
            Unk_2383cc0_vf1(self, events, event);
        Unk_3c3020(self, event->field_0, &event->field_8, event->field_c, 0, true);
        int pool = Unk_237e820;
        event->~Unk_3c2f40_Event();
        Unk_3047c0(pool, event);
    }
    Unk_3c33f0(self, count);
}

// 0x71003c3e40: the use of a node goes out of the list
void Unk_3c3e40(Unk_2383cc0* self, Unk_3c44e0_T* key) {
    for (auto it = self->field_20.BeginEx(); it != self->field_20.End(); ++it) {
        if ((*it)->field_10 == key) {
            Unk_3c44e0_Use* use = *it;
            self->field_20.Erase(it);
            key->field_10 = nullptr;
            Unk_3c4880(use);
            return;
        }
    }
}

// The uses of a node, or the end of the array.
static inline Unk_Array<Unk_2383cc0_Entry>::Iterator Unk_2383cc0_Find(Unk_2383cc0* self,
                                                                       Unk_23837d0_Node* key) {
    auto it = self->field_10.Begin();
    for (auto end = self->field_10.End(); it != end; ++it) {
        if ((*it).key == key)
            break;
    }
    return it;
}

// 0x71003c3eb0: for the uses of an item
void Unk_3c3eb0(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    auto it = Unk_2383cc0_Find(self, item->field_40);
    if (it != self->field_10.End()) {
        for (Unk_3c44e0_Use* use = (*it).item.first; use != nullptr; use = use->next) {
            if (use->field_18 == item)
                Unk_3c51e0(use);
        }
    }
    for (Unk_3c44e0_Use* use = self->field_20.first; use != nullptr; use = use->next) {
        if (use->field_18 == item)
            Unk_3c51e0(use);
    }
}

// 0x71003c3f90: the same with the other function
void Unk_3c3f90(Unk_2383cc0* self, Unk_2383c58_Item* item) {
    auto it = Unk_2383cc0_Find(self, item->field_40);
    if (it != self->field_10.End()) {
        for (Unk_3c44e0_Use* use = (*it).item.first; use != nullptr; use = use->next) {
            if (use->field_18 == item)
                Unk_3c5260(use);
        }
    }
    for (Unk_3c44e0_Use* use = self->field_20.first; use != nullptr; use = use->next) {
        if (use->field_18 == item)
            Unk_3c5260(use);
    }
}
