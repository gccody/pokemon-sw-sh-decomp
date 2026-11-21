// Scope: common
// The set of keys that the plug-in context's members build (one key in the
// object itself) and hand to Unk_3d08c0.cpp's functions, and those members.
// Placeholder names.
#include "Unk_369950.h"
#include "Unk_HybridArray.h"

extern "C" void* memcpy(void* dest, const void* src, size_t size);

// The set, with the name Unk_3d08c0.cpp has for it. Its keys are objects'
// addresses, kept as integers: the items are copied as integers when the
// array grows.
struct Unk_3d08c0_Set : Unk_AllocSortedSet<u64, Unk_HybridAlloc<u64, 1>> {};
PKMN_SIZE_ASSERT(Unk_3d08c0_Set, 0x18);

// 0x710036a200
template u64* Unk_AllocSortedSet<u64, Unk_HybridAlloc<u64, 1>>::AddNoSetKey(u64);

// An item of the context's object (0x60 bytes, 0x58 of them copied out).
struct Unk_3d08c0_Item;

// The number of the object's items whose key is in the set, and the item of
// that kind at `index` (Unk_3d08c0.cpp).
u32 Unk_3d08c0(Unk_3d08c0_Self* self, const Unk_3d08c0_Set& set, u32 mode);
Unk_3d08c0_Item* Unk_3d0a00(Unk_3d08c0_Self* self, const Unk_3d08c0_Set& set, u32 mode, u32 index);

// The object of a key, a value from it and an item, and what the sound makes
// of that value.
void* Unk_32c040(u64 key);
f32 Unk_32df00(void* object, void* item);
f32 Unk_34fe30(void* sound, f32 value);
f32 Unk_34ff30(void* sound, f32 value);

// 0x7100369d80
u32 Unk_369d80(Unk_369950_T* self) {
    if (self->field_48->field_20->field_154_0 != 1)
        return 0;
    Unk_3d08c0_Set set;
    if (set.Add(self->field_c8) == nullptr)
        return 0;
    return Unk_3d08c0(self->field_48, set, 0);
}

// 0x7100369e40: 1 with the item at `index` copied out, 2 without one.
u32 Unk_369e40(Unk_369950_T* self, u32 index, void* out) {
    Unk_3d08c0_Set set;
    if (set.Add(self->field_c8) != nullptr) {
        Unk_3d08c0_Item* item = Unk_3d0a00(self->field_48, set, 0, index);
        if (item != nullptr) {
            memcpy(out, item, 0x58);
            return 1;
        }
    }
    return 2;
}

// 0x7100369f10
f32 Unk_369f10(Unk_369950_T* self, u32 index) {
    Unk_3d08c0_Set set;
    if (set.Add(self->field_c8) == nullptr)
        return 2.0f;
    Unk_3d08c0_Item* item = Unk_3d0a00(self->field_48, set, 0, index);
    f32 result = 0.0f;
    if (item != nullptr) {
        void* object = Unk_32c040(self->field_c8);
        if (object != nullptr) {
            f32 value = Unk_32df00(object, item);
            result = Unk_34fe30(self->field_48->field_20, value);
        }
    }
    return result;
}

// 0x7100369ff0
f32 Unk_369ff0(Unk_369950_T* self, u32 index) {
    Unk_3d08c0_Set set;
    if (set.Add(self->field_c8) == nullptr)
        return 2.0f;
    Unk_3d08c0_Item* item = Unk_3d0a00(self->field_48, set, 0, index);
    if (item == nullptr)
        return 0.0f;
    f32 value = Unk_32df00(Unk_32c040(self->field_c8), item);
    return Unk_34ff30(self->field_48->field_20, value);
}
