#pragma once
// Wwise's object index: 14 hash tables of reference-counted objects by ID,
// each with its lock. Placeholder names.
#include <nn/os.h>
#include "Unk_3476d0.h"
#include "containers.h"

// A hash table of T by key: T has the next item of its chain at field_8 and
// its key at field_10.
template <class T>
struct Unk_HashListBare {
    struct Iterator {
        Unk_HashListBare* table;
        u32 bucket;
        T* item;

        T* operator*() const { return item; }
        bool operator!=(const Iterator& other) const { return item != other.item; }

        void operator++() {
            item = static_cast<T*>(item->field_8);
            while (item == nullptr) {
                if (++bucket >= table->field_0.Length())
                    break;
                item = table->field_0.field_0[bucket];
            }
        }
    };

    Unk_Array<T*> field_0;  // buckets
    u32 field_10;  // number of items

    Iterator Begin() {
        Iterator it;
        it.table = this;
        it.bucket = 0;
        it.item = nullptr;
        if (field_0.Length() > 0) {
            it.item = field_0.field_0[0];
            while (it.item == nullptr && ++it.bucket < field_0.Length())
                it.item = field_0.field_0[it.bucket];
        }
        return it;
    }

    Iterator End() {
        Iterator it;
        it.table = this;
        it.bucket = 0;
        it.item = nullptr;
        return it;
    }

    u32 Length() const { return field_10; }

    T* Exists(u32 key) const {
        if (field_0.Length() != 0) {
            u32 bucket = key % field_0.Length();
            for (T* p = field_0.field_0[bucket]; p != nullptr; p = static_cast<T*>(p->field_8)) {
                if (p->field_10 == key)
                    return p;
            }
        }
        return nullptr;
    }
};

// 0x38 bytes: one of the index's tables.
template <class T>
struct Unk_Index {
    nn::os::MutexType field_0;
    Unk_HashListBare<T> field_20;

    T* GetAndAddRef(u32 key) {
        nn::os::LockMutex(&field_0);
        T* p = field_20.Exists(key);
        if (p != nullptr)
            p->field_14++;
        nn::os::UnlockMutex(&field_0);
        return p;
    }
};

// An object of the table at 0x1c0.
struct Unk_3350e0_Obj : Unk_3476d0_Obj {
    u8 _18[0x54];
    u32 field_6c;
};
PKMN_OFFSET_ASSERT(Unk_3350e0_Obj, field_6c, 0x6c);

struct Unk_334be0_T {
    Unk_Index<Unk_3476d0_Obj> field_0;
    Unk_Index<Unk_3476d0_Obj> field_38;
    Unk_Index<Unk_3476d0_Obj> field_70;
    Unk_Index<Unk_3476d0_Obj> field_a8;
    Unk_Index<Unk_3476d0_Obj> field_e0;
    Unk_Index<Unk_3476d0_Obj> field_118;
    Unk_Index<Unk_3476d0_Obj> field_150;
    Unk_Index<Unk_3476d0_Obj> field_188;
    Unk_Index<Unk_3350e0_Obj> field_1c0;
    Unk_Index<Unk_3476d0_Obj> field_1f8;
    Unk_Index<Unk_3476d0_Obj> field_230;
    Unk_Index<Unk_3476d0_Obj> field_268;
    Unk_Index<Unk_3476d0_Obj> field_2a0;
    Unk_Index<Unk_3476d0_Obj> field_2d8;

    bool Unk_334be0();
    void Unk_334cf0();
    void Unk_334f70();
    void Unk_3350e0();
};
PKMN_SIZE_ASSERT(Unk_334be0_T, 0x310);

// 0x71003351b0: an object of the first or the second table, with a reference.
Unk_3476d0_Obj* Unk_3351b0(void* self, u32 id, u32 type);
