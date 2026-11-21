// Scope: common
// An item of the owner 0x7102383cc0 with a second base at 0x58 (the class of
// 0x71003e1d40): small functions. Written from the executable. Placeholder
// names.
#include "Unk_3e2390.h"

struct Unk_3a7f20;
extern u64 Unk_24bbbe0;
void Unk_3c3eb0(Unk_2383cc0* self, Unk_2383c58_Item* item);
void Unk_3c3f90(Unk_2383cc0* self, Unk_2383c58_Item* item);
void Unk_314a70(Unk_3e22b0_Node* node, bool* done, u32* kind);
void Unk_30ac40(Unk_3e22b0_Node* node, bool* done, u32* kind);
void Unk_30acb0(Unk_3e22b0_Node* node, bool* done, f32* value);
void Unk_3a7eb0(void* self, u8** start, u32* size, Unk_3e23a0_Object** object);
void Unk_3a7f20_update(const Unk_3a7f20* self);

// The object of its second base (a number less, as the bus's).
static inline Unk_3e2390_T* Unk_3e2390_Outer(Unk_3e2390_Second* self) {
    return reinterpret_cast<Unk_3e2390_T*>(reinterpret_cast<u64>(self) - 0x58);
}

static inline Unk_2383c58_Item* Unk_3e2390_Item(Unk_3e2390_T* self) {
    return reinterpret_cast<Unk_2383c58_Item*>(self);
}

// 0x71003e2390
bool Unk_3e2390(Unk_3e2390_T* self, void* arg1) {
    return self->field_d8 == arg1;
}

// 0x71003e23a0: something else to play, when there is something
bool Unk_3e23a0(Unk_3e2390_T* self, void* /*arg1*/) {
    Unk_3e23a0_Object* found = nullptr;
    if (Unk_24bbbe0 == 0)
        return false;
    u8* start = nullptr;
    u32 size;
    Unk_3a7eb0(self->field_c8, &start, &size, &found);
    if (found == nullptr)
        return false;
    Unk_3a7f20_update(static_cast<const Unk_3a7f20*>(self->field_c8));
    Unk_3e23a0_Object* old = self->field_d8;
    self->field_d8 = found;
    Unk_3e2ee0(&self->field_f0, start);
    self->field_e0 = start;
    self->field_e8 = size;
    if (old != nullptr)
        old->vf0(0);
    return true;
}

// 0x71003e2480
void Unk_3e2480(Unk_3e2390_Second* self, u64 arg1) {
    Unk_3e2390_Outer(self)->vf12(arg1);
}

// 0x71003e2490
void Unk_3e2490(Unk_3e2390_T* self) {
    self->field_17c_0 = 1;
    if (self->field_b8 != nullptr)
        Unk_3c3eb0(self->field_b8, Unk_3e2390_Item(self));
}

// 0x71003e24c0
void Unk_3e24c0(Unk_3e2390_Second* self) {
    Unk_3e2490(Unk_3e2390_Outer(self));
}

// 0x71003e24f0
void Unk_3e24f0(Unk_3e2390_T* self) {
    self->field_17c_0 = 0;
    if (self->field_b8 != nullptr)
        Unk_3c3f90(self->field_b8, Unk_3e2390_Item(self));
}

// 0x71003e2520
void Unk_3e2520(Unk_3e2390_Second* self) {
    Unk_3e24f0(Unk_3e2390_Outer(self));
}

// 0x71003e22b0: asks the nodes above its node
f32 Unk_3e22b0(Unk_3e2390_T* self) {
    f32 value = 0;
    u32 kind;
    bool done;
    Unk_314a70(self->field_c0, &done, &kind);
    for (Unk_3e22b0_Node* node = self->field_c0->field_78; node != nullptr && !done;
         node = node->field_78)
        Unk_30ac40(node, &done, &kind);
    if (kind == 0) {
        done = false;
        for (Unk_3e22b0_Node* node = self->field_c0->field_78; node != nullptr && !done;
             node = node->field_78)
            Unk_30acb0(node, &done, &value);
    }
    return value;
}
