// Scope: common
// The work memory of the functions at 0x71003c08f0-0x71003c1c60 (points and
// what is built from them): four arrays of 0x18-byte items and three buffers
// from an allocator object. Written from the executable. Placeholder names.
#include "containers.h"

// What the buffers come from.
struct Unk_3c0e30_Alloc {
    virtual void vf0();
    virtual void vf1();
    virtual void* vf2(u64 size);  // allocates
    virtual void vf3(void* ptr);  // frees
};

struct Unk_3c0e30_Item {
    u8 field_0[0x18];
};

typedef Unk_Array<Unk_3c0e30_Item, Unk_Pool2381488> Unk_3c0e30_Array;

struct Unk_3c0e30_Point {
    f32 field_0[3];
};

struct Unk_3c0e30_T {
    u32 field_0;  // number of points and one
    Unk_3c0e30_Array field_8;
    Unk_3c0e30_Array field_18;
    Unk_3c0e30_Array field_28;
    Unk_3c0e30_Array field_38;
    Unk_3c0e30_Point* field_48;
    u64* field_50;
    u64* field_58;
};
PKMN_SIZE_ASSERT(Unk_3c0e30_T, 0x60);

void Unk_3c0fb0(Unk_3c0e30_T* self, Unk_3c0e30_Alloc* alloc);

// 0x71003c0e30
u32 Unk_3c0e30(Unk_3c0e30_T* self, Unk_3c0e30_Alloc* alloc, u32 count) {
    self->field_0 = count + 1;
    self->field_8.Reserve(self->field_0 * 2);
    self->field_18.Reserve(self->field_0 * 2);
    self->field_28.Reserve(self->field_0 * 2);
    self->field_38.Reserve(self->field_0 * 2);
    self->field_48 =
        static_cast<Unk_3c0e30_Point*>(alloc->vf2(sizeof(Unk_3c0e30_Point) * self->field_0));
    self->field_50 = static_cast<u64*>(alloc->vf2(sizeof(u64) * self->field_0));
    self->field_58 = static_cast<u64*>(alloc->vf2(sizeof(u64) * self->field_0));
    if (self->field_48 == nullptr || self->field_50 == nullptr || self->field_58 == nullptr) {
        Unk_3c0fb0(self, alloc);
        return 0x34;
    }
    return 1;
}

// 0x71003c0fb0
void Unk_3c0fb0(Unk_3c0e30_T* self, Unk_3c0e30_Alloc* alloc) {
    self->field_8.Term();
    self->field_18.Term();
    self->field_28.Term();
    self->field_38.Term();
    if (self->field_48 != nullptr)
        alloc->vf3(self->field_48);
    if (self->field_50 != nullptr)
        alloc->vf3(self->field_50);
    if (self->field_58 != nullptr)
        alloc->vf3(self->field_58);
    self->field_48 = nullptr;
    self->field_50 = nullptr;
    self->field_58 = nullptr;
}
