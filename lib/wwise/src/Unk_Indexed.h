#pragma once
// The objects the sound engine keeps by ID: each kind has an index (a hash
// table with a lock) in the global object at 0x71024bbbb8. Placeholder names.
#include <nn/os.h>
#include "Unk_HashList.h"

// An object kept in an index.
struct Unk_Indexed {
    virtual ~Unk_Indexed();

    Unk_Indexed* field_8;  // next in the hash chain
    u32 field_10;  // key
    u32 field_14;  // reference count
};
PKMN_OFFSET_ASSERT(Unk_Indexed, field_14, 0x14);

struct Unk_Index {
    nn::os::MutexType field_0;
    Unk_Array<Unk_Indexed*> field_20;  // buckets
    u32 field_30;  // number of objects

    void Remove(u32 key) {
        nn::os::LockMutex(&field_0);
        if (field_20.Length() != 0) {
            u32 index = key % field_20.Length();
            Unk_Indexed** bucket = &field_20.field_0[index];
            Unk_Indexed* prev = nullptr;
            for (Unk_Indexed* p = *bucket; p != nullptr; prev = p, p = p->field_8) {
                if (p->field_10 == key) {
                    if (prev == nullptr)
                        *bucket = p->field_8;
                    else
                        prev->field_8 = p->field_8;
                    field_30--;
                    break;
                }
            }
        }
        nn::os::UnlockMutex(&field_0);
    }
};
PKMN_OFFSET_ASSERT(Unk_Index, field_20, 0x20);
PKMN_OFFSET_ASSERT(Unk_Index, field_30, 0x30);

extern u8* Unk_24bbbb8;

template <u32 Offset>
static inline Unk_Index* Unk_GetIndex() {
    return reinterpret_cast<Unk_Index*>(Unk_24bbbb8 + Offset);
}

// The base class's constructor (0x7100363510) and destructor (0x7100363530).
// tools/vtables.py ctors took the destructor, slot 0 of its vtable, for the
// constructor of a class Unk_2380db0, and that is the name it has: the
// destructors of the derived classes end with it.
void Unk_363510(Unk_Indexed* self, u32 id);
class Unk_2380db0 {
public:
    Unk_2380db0();
    virtual ~Unk_2380db0();
};
static inline void Unk_IndexedDtor(Unk_Indexed* self) {
    new (self) Unk_2380db0;
}

// The vtables are data here: an object's vptr is its vtable's address point,
// two words in.
static inline void Unk_SetVtable(void* self, void** vtable) {
    *static_cast<void***>(self) = vtable + 2;
}

// The table of an index.
struct Unk_IndexedPolicy {
    static u32 Key(Unk_Indexed* item) { return item->field_10; }
    static Unk_Indexed*& Next(Unk_Indexed* item) { return item->field_8; }
};
typedef Unk_HashListBare<Unk_Indexed, Unk_IndexedPolicy> Unk_IndexTable;

template <u32 Offset>
static inline void Unk_IndexedAdd(Unk_Indexed* self) {
    Unk_Index* index = Unk_GetIndex<Offset>();
    nn::os::LockMutex(&index->field_0);
    Unk_IndexTable* table = reinterpret_cast<Unk_IndexTable*>(&index->field_20);
    if (table->field_0.Length() == 0 ||
        static_cast<f32>(table->field_10) / static_cast<f32>(table->field_0.Length()) > 0.9f)
        table->Reserve(table->HashSize());
    if (table->field_0.Length() != 0) {
        u32 bucket = self->field_10 % table->field_0.Length();
        self->field_8 = table->field_0.field_0[bucket];
        table->field_0.field_0[bucket] = self;
        table->field_10++;
    }
    nn::os::UnlockMutex(&index->field_0);
}

template <u32 Offset>
static inline Unk_Indexed* Unk_IndexedGetAndAddRef(u32 key) {
    Unk_Index* index = Unk_GetIndex<Offset>();
    nn::os::LockMutex(&index->field_0);
    Unk_Indexed* p = nullptr;
    if (index->field_20.Length() != 0) {
        u32 bucket = key % index->field_20.Length();
        for (p = index->field_20.field_0[bucket]; p != nullptr; p = p->field_8) {
            if (p->field_10 == key)
                break;
        }
        if (p != nullptr)
            p->field_14++;
    }
    nn::os::UnlockMutex(&index->field_0);
    return p;
}
