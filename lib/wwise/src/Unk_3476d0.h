#pragma once
// The types of the bank reading functions of Unk_3476d0.cpp. Placeholder
// names.
#include <nn/os.h>
#include "containers.h"

// An object kept in an index: its hash-chain link, key and reference count.
struct Unk_3476d0_Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();  // release

    Unk_3476d0_Obj* field_8;  // next in the hash chain
    u32 field_10;  // key
    u32 field_14;  // reference count
};
PKMN_OFFSET_ASSERT(Unk_3476d0_Obj, field_8, 0x8);
PKMN_OFFSET_ASSERT(Unk_3476d0_Obj, field_10, 0x10);
PKMN_OFFSET_ASSERT(Unk_3476d0_Obj, field_14, 0x14);

// A hash table of objects by key, with its lock.
struct Unk_3476d0_Index {
    nn::os::MutexType field_0;
    Unk_Array<Unk_3476d0_Obj*> field_20;  // buckets

    Unk_3476d0_Obj* GetAndAddRef(u32 key) {
        nn::os::LockMutex(&field_0);
        Unk_3476d0_Obj* p = nullptr;
        if (field_20.Length() != 0) {
            u32 bucket = key % field_20.Length();
            for (p = field_20.field_0[bucket]; p != nullptr; p = p->field_8) {
                if (p->field_10 == key)
                    break;
            }
            if (p != nullptr)
                p->field_14++;
        }
        nn::os::UnlockMutex(&field_0);
        return p;
    }
};
PKMN_OFFSET_ASSERT(Unk_3476d0_Index, field_20, 0x20);

struct Unk_3476d0_Data {
    u8 field_0;
    u32 field_1;
} __attribute__((packed));

struct Unk_3476d0_Out {
    u8 _0[0x60];
    Unk_Array<Unk_3476d0_Obj*> field_60;
};
PKMN_OFFSET_ASSERT(Unk_3476d0_Out, field_60, 0x60);

struct Unk_34e550;
struct Unk_3476d0_Self {
    u8 _0[8];
    u8 field_8;  // start of a member (Unk_34e250, Unk_34e550_call)
};

u32* Unk_34e250(void* self, u32 size);
