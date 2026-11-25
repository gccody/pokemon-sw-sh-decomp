// Scope: common
// The destructors of the classes of vtables 0x710237dbc8 and 0x710237dd38
// (Unk_31b990.h), the second one's constructor, and slots of the first.
// Placeholder names.
#include <types.h>

#include "Unk_31b990.h"

// 0x710031b990: the destructor of the class of vtable 0x710237dbc8 (slot 10)
void Unk_31b990(void* object) {
    Unk_31b990_T* self = static_cast<Unk_31b990_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dbc8);
    if (self->field_90 != nullptr)
        self->field_90->vf3();
    Unk_3191e0(self);
}

// 0x710031b9f0: the destructor through the vptr at 0x18
void Unk_31b9f0(void* object) {
    Unk_31b990(static_cast<u8*>(object) - 0x18);
}

// 0x710031ba50: the deleting destructor (slot 11)
void Unk_31ba50(void* object) {
    Unk_31b990(object);
    operator delete(object);
}

// 0x710031bab0: the deleting destructor through the vptr at 0x18
void Unk_31bab0(void* object) {
    Unk_31ba50(static_cast<u8*>(object) - 0x18);
}

// 0x710031c020: the constructor of the class of vtable 0x710237dd38
void Unk_31c020(Unk_310160_T* object, Unk_237c170* node, void* a2) {
    Unk_319190(object, a2);
    Unk_31c020_T* self = reinterpret_cast<Unk_31c020_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dd38);
    self->field_90 = node;
    Unk_3168a0(&self->field_98, node);
    self->field_e0 = true;
    if (self->field_90 != nullptr)
        self->field_90->vf2();
}

// 0x710031c0a0: its destructor (slot 10)
void Unk_31c0a0(void* object) {
    Unk_31c020_T* self = static_cast<Unk_31c020_T*>(object);
    Unk_31b990_SetVtables(self, _ZTV11Unk_237dd38);
    Unk_316c50(&self->field_98);
    if (self->field_90 != nullptr)
        self->field_90->vf3();
    Unk_3168d0_update(reinterpret_cast<u64>(&self->field_98));
    Unk_3191e0(self);
}

// 0x710031c110: the destructor through the vptr at 0x18
void Unk_31c110(void* object) {
    Unk_31c0a0(static_cast<u8*>(object) - 0x18);
}

// 0x710031c190: the deleting destructor (slot 11)
void Unk_31c190(void* object) {
    Unk_31c0a0(object);
    operator delete(object);
}
