// Scope: common
// A list of objects sorted by a time (the class of vtable 0x710237dba8, and
// its derived classes' members), and a table of entries with a time stamp
// guarded by a mutex (Unk_24bb9a0). Placeholder names.
#include <nn/os.h>
#include <string.h>
#include <types.h>

#include "Unk_Indexed.h"
#include "Unk_KeyArray.h"
#include "Unk_31b990.h"
#include "Unk_PlacementNew.h"
#include "containers.h"

// An item of the list: destroyed through its vtable.
class Unk_31b1a0_Item {
public:
    virtual ~Unk_31b1a0_Item();
    virtual s32 vf2();

    Unk_31b1a0_Item* next;
    s32 field_10;  // the time the list is sorted by
    void* field_18;  // the object the item is for
};
PKMN_OFFSET_ASSERT(Unk_31b1a0_Item, next, 0x8);
PKMN_OFFSET_ASSERT(Unk_31b1a0_Item, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_31b1a0_Item, field_18, 0x18);

struct Unk_31b1a0_List : Unk_ListBare<Unk_31b1a0_Item> {
    void AddLast(Unk_31b1a0_Item* item) {
        item->next = nullptr;
        if (field_8 == nullptr) {
            field_8 = item;
            field_0 = item;
        } else {
            field_0->next = item;
            field_0 = item;
        }
    }

    void RemoveFirst() {
        if (field_8 == nullptr)
            return;
        if (field_8->next == nullptr) {
            field_8 = nullptr;
            field_0 = nullptr;
        } else {
            field_8 = field_8->next;
        }
    }

    IteratorEx Erase(const IteratorEx& it) {
        IteratorEx next;
        next.item = it.item->next;
        next.prev = it.prev;
        RemoveItem(it.item, it.prev);
        return next;
    }

    // Removes and destroys the items of `owner` that vf2 accepts.
    void RemoveOwned(void* owner) {
        IteratorEx it = BeginEx();
        while (it.item != nullptr) {
            Unk_31b1a0_Item* item = it.item;
            if (item->vf2() == 1 && item->field_18 == owner) {
                it = Erase(it);
                Unk_Delete(item);
            } else {
                ++it;
            }
        }
    }
};

// The vtable of the class, data here.
extern void* _ZTV11Unk_237dba8[];

struct Unk_237dba8 {
    void* vptr;
    Unk_31b1a0_List list;
};
PKMN_OFFSET_ASSERT(Unk_237dba8, list, 0x8);
PKMN_SIZE_ASSERT(Unk_237dba8, 0x18);

// 0x710031b1a0: the constructor
void Unk_31b1a0(Unk_237dba8* self) {
    self->list.field_8 = nullptr;
    self->list.field_0 = nullptr;
    Unk_SetVtable(self, _ZTV11Unk_237dba8);
}

// 0x710031b1c0: the destructor
void Unk_31b1c0(void* self) {
    Unk_237dba8* list = static_cast<Unk_237dba8*>(self);
    Unk_SetVtable(list, _ZTV11Unk_237dba8);
    list->list.field_0 = nullptr;
    list->list.field_8 = nullptr;
}

// 0x710031b1f0: adds the item after the ones with the same time
void Unk_31b1f0(Unk_237dba8* self, Unk_31b1a0_Item* item) {
    s32 time = item->field_10;
    Unk_31b1a0_List::IteratorEx it = self->list.BeginEx();
    for (; it.item != nullptr; ++it) {
        if (time < it.item->field_10)
            break;
    }
    if (it.item == nullptr) {
        self->list.AddLast(item);
        return;
    }
    item->next = it.item;
    if (it.prev == nullptr)
        self->list.field_8 = item;
    else
        it.prev->next = item;
}

// 0x710031b260: takes the first item when it is due before `time + delta`
u32 Unk_31b260(Unk_237dba8* self, s32 time, s32 delta, Unk_31b1a0_Item** out) {
    Unk_31b1a0_Item* first = self->list.field_8;
    if (first != nullptr && first->field_10 < time + delta) {
        *out = first;
        self->list.RemoveFirst();
        return 0x2d;
    }
    *out = nullptr;
    return 0x11;
}

// 0x710031b2c0: destroys every item
void Unk_31b2c0(Unk_237dba8* self) {
    Unk_31b1a0_Item* item;
    while ((item = self->list.field_8) != nullptr) {
        self->list.RemoveFirst();
        Unk_Delete(item);
    }
}

// 0x710031b340
// NON_MATCHING: the code of Unk_31b420 (below). Its name has one parameter,
// `_Z10Unk_31b340Pv`, and the code reads a second one in x1.
void Unk_31b340(Unk_237dba8* self, void* owner) {
    self->list.RemoveOwned(owner);
}

// 0x710031b420
// NON_MATCHING: register allocation: the pool's address and the previous item
// have each other's registers, and the item kept loads the next one into a
// register of its own.
void Unk_31b420(Unk_237dba8* self, void* owner) {
    self->list.RemoveOwned(owner);
}

// 0x710031b920: the constructor of the class of vtable 0x710237dbc8
void Unk_31b920(Unk_310160_T* object, Unk_237c170* node, void* a2) {
    Unk_319190(object, a2);
    Unk_31b990_T* self = reinterpret_cast<Unk_31b990_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dbc8);
    self->field_90 = node;
    if (node != nullptr)
        node->vf2();
}

// The value of an entry of Unk_24bb9a0: 0x24 bytes and the tick they were
// set at.
struct Unk_24bb9a0_Value {
    u8 field_0[0x24];
    nn::os::Tick field_28;
};
PKMN_OFFSET_ASSERT(Unk_24bb9a0_Value, field_28, 0x28);
PKMN_SIZE_ASSERT(Unk_24bb9a0_Value, 0x30);

struct Unk_24bb9a0_T {
    Unk_24bb9a0_T();
    ~Unk_24bb9a0_T();

    Unk_KeyArray<u32, Unk_24bb9a0_Value> field_0;
    nn::os::MutexType field_10;
};
PKMN_OFFSET_ASSERT(Unk_24bb9a0_T, field_10, 0x10);
PKMN_SIZE_ASSERT(Unk_24bb9a0_T, 0x30);

// 0x710031b500
// NON_MATCHING: the original adds 0x10 to x0 after the zeroing store; here
// the add is folded into the store as a post-index (or, with the members
// assigned one by one, computed in another register before it).
Unk_24bb9a0_T::Unk_24bb9a0_T() : field_0() {
    nn::os::InitializeMutex(&field_10, true, 0);
}

// 0x710031b520
Unk_24bb9a0_T::~Unk_24bb9a0_T() {
    nn::os::FinalizeMutex(&field_10);
}

// 0x710031b580: adds an entry for `id`, or clears the one there: 1, or 2
// without memory
u32 Unk_31b580(Unk_24bb9a0_T* self, u32 id) {
    nn::os::LockMutex(&self->field_10);
    u32 result;
    Unk_24bb9a0_Value* value = self->field_0.Set(id);
    if (value != nullptr) {
        memset(value->field_0, 0, sizeof(value->field_0));
        value->field_28 = nn::os::GetSystemTick();
        result = 1;
    } else {
        result = 2;
    }
    nn::os::UnlockMutex(&self->field_10);
    return result;
}

// 0x710031b7b0: sets the entry of `id`
void Unk_31b7b0(Unk_24bb9a0_T* self, u32 id, void* data) {
    nn::os::LockMutex(&self->field_10);
    Unk_24bb9a0_Value* value = self->field_0.Exists(id);
    if (value != nullptr) {
        memcpy(value->field_0, data, sizeof(value->field_0));
        value->field_28 = nn::os::GetSystemTick();
    }
    nn::os::UnlockMutex(&self->field_10);
}

// 0x710031b860: removes the entry of `id`
void Unk_31b860(Unk_24bb9a0_T* self, u32 id) {
    nn::os::LockMutex(&self->field_10);
    self->field_0.Unset(id);
    nn::os::UnlockMutex(&self->field_10);
}
