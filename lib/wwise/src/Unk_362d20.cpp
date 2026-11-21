// Scope: common
// The base class with the vtable 0x7102380d50 (an object that is in two of
// the managers' lists and owns an array of objects), its destructor, and a
// class derived from it. Placeholder names.
#include "Unk_Indexed.h"
#include "Unk_PlacementNew.h"

u32 Unk_304740(int poolId, void* ptr);

// What a value is looked up by (0x30 bytes, every member in a word of its
// own): here with the object alone, the rest any.
struct Unk_362d20_Key {
    void* field_0;
    u32 field_8;
    u32 field_10 __attribute__((aligned(8)));
    u8 field_18 __attribute__((aligned(8)));
    u8 field_20 __attribute__((aligned(8)));
    void* field_28;

    explicit Unk_362d20_Key(void* object)
        : field_8(0), field_10(0), field_18(0xff), field_20(0xff), field_28(nullptr) {
        field_0 = object;
    }
};
PKMN_SIZE_ASSERT(Unk_362d20_Key, 0x30);

// The two managers the object's IDs are registered with.
extern void* Unk_24bbc18;
extern void* Unk_24bbbf8;
void Unk_378a00(void* manager, u32 id, const Unk_362d20_Key* key);
void Unk_39e270(void* manager, u32 id, const Unk_362d20_Key* key);

// The IDs an object has with each of the two.
struct Unk_3a5710_T {
    Unk_GrowArray<u32> field_0;
    Unk_GrowArray<u32> field_10;
};

// 0x71003a5710
void Unk_3a5710(Unk_3a5710_T* self, const Unk_362d20_Key* key) {
    for (auto it = self->field_0.Begin(); it != self->field_0.End(); ++it)
        Unk_378a00(Unk_24bbc18, *it, key);
    self->field_0.Term();
    for (auto it = self->field_10.Begin(); it != self->field_10.End(); ++it)
        Unk_39e270(Unk_24bbbf8, *it, key);
    self->field_10.Term();
}

void Unk_3a5700_update(u64 self);

// An object the base class owns.
struct Unk_362d20_Owned {
    virtual ~Unk_362d20_Owned();
};

// The object: its array has room for two items in the object itself.
struct Unk_2380d50_T {
    void** vptr;
    Unk_3a5710_T field_8;
    Unk_362d20_Owned* field_28[2];
    Unk_362d20_Owned** field_38;
    u32 field_40;
    u32 field_44;

    Unk_362d20_Owned** Begin() { return field_38; }
    Unk_362d20_Owned** End() { return field_38 + field_40; }

    // What the array frees its items' memory with: the two in the object
    // aren't freed.
    void Free(void* items) {
        if (field_28 != items)
            Unk_304740(Unk_237e820, items);
    }

    void Term() {
        if (field_38 != nullptr) {
            field_40 = 0;
            Free(field_38);
            field_38 = nullptr;
            field_44 = 0;
        }
    }
};
PKMN_SIZE_ASSERT(Unk_2380d50_T, 0x48);

extern void* Unk_2380d50[];

// 0x7100362d20: the destructor.
// NON_MATCHING: one compare has its operands in the other order (`cmp x21,
// x8` for `cmp x8, x21`). The function has the name deleting_dtors.cpp
// declared it with, with a `void*` parameter: the address of the two items
// in the object is then a cast of a byte offset, which InstCombine puts on
// the right of a compare; with a typed `this` it stays on the left.
void Unk_362d20(void* object) {
    Unk_2380d50_T* self = static_cast<Unk_2380d50_T*>(object);
    Unk_SetVtable(self, Unk_2380d50);
    Unk_362d20_Key key(self);
    Unk_3a5710(&self->field_8, &key);
    for (Unk_362d20_Owned** it = self->Begin(); it != self->End(); ++it) {
        if (*it != nullptr)
            Unk_Delete(*it);
        *it = nullptr;
    }
    self->Term();
    Unk_3a5700_update(reinterpret_cast<u64>(&self->field_8));
}

// The class with the vtable 0x7102382b38, derived from it and registered
// with the switch groups' manager.
struct Unk_3babc0;
extern Unk_3babc0* Unk_24bbbc8;
void Unk_3bbf80(Unk_3babc0* self, void* subscriber);
extern void* Unk_2382b38[];

// 0x7100395790
void Unk_395790(void* self) {
    Unk_SetVtable(self, Unk_2382b38);
    Unk_3bbf80(Unk_24bbbc8, self);
    Unk_362d20(self);
}

// 0x71003957e0
void Unk_3957e0(void* self) {
    Unk_SetVtable(self, Unk_2382b38);
    Unk_3bbf80(Unk_24bbbc8, self);
    Unk_362d20(self);
    operator delete(self);
}
