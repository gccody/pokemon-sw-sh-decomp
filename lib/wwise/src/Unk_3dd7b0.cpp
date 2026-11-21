// Scope: common
// What the samples of a sound come from (vtable 0x7102384dd0). Written from
// the executable. Placeholder names.
#include "Unk_3dd7b0.h"

struct Unk_38d2d0;
struct Unk_38d2f0;
extern void* Unk_2384dd0[];

void Unk_38d280(Unk_3dd7b0_Ctx* ctx, u32 arg1);
void Unk_38d2d0_set(Unk_38d2d0* self);
void Unk_38d2f0_set(Unk_38d2f0* self);
void Unk_390610(void* self, u32 id, Unk_3dd7b0_T* source, f32 arg3);
void Unk_390920(void* self, u32 id, Unk_3dd7b0_T* source);

// 0x71003dd7b0: the constructor
void Unk_3dd7b0(Unk_3dd7b0_T* self, Unk_3dd7b0_Ctx* ctx) {
    self->field_10 = 0;
    self->field_18 = ctx;
    *reinterpret_cast<void***>(self) = Unk_2384dd0 + 2;
    self->field_8 = 0;
    self->field_20_0 = 0;
    self->field_20_1 = 0;
}

// 0x71003dd9d0
void Unk_3dd9d0(Unk_3dd7b0_T* self, u32 arg1) {
    if (self->field_18 != nullptr) {
        if (self->field_18->field_a_4)
            Unk_390920(Unk_24bbc10, self->field_18->field_1d8, self);
        Unk_38d280(self->field_18, arg1);
    }
    self->vf11();
}

// 0x71003ddb90
void Unk_3ddb90(Unk_3dd7b0_T* self) {
    Unk_38d2d0_set(reinterpret_cast<Unk_38d2d0*>(self->field_18));
    Unk_390610(Unk_24bbc10, self->field_18->field_1d8, self, 0.0f);
}

// 0x71003ddbd0
void Unk_3ddbd0(Unk_3dd7b0_T* self, f32 arg1) {
    Unk_38d2f0_set(reinterpret_cast<Unk_38d2f0*>(self->field_18));
    Unk_390610(Unk_24bbc10, self->field_18->field_1d8, self, arg1);
}

// 0x71003ddc20
u32 Unk_3ddc20(Unk_3dd7b0_T* self) {
    if (self->field_18->field_26b_22)
        return self->vf25();
    return 1;
}

// 0x71003ddc60: asks for `*count` samples that nobody reads
u32 Unk_3ddc60(Unk_3dd7b0_T* self, u32* count) {
    Unk_3dd7b0_Buffer buffer;
    buffer.field_0 = nullptr;
    buffer.field_8 = 0;
    buffer.field_c = 0x2b;
    buffer.field_12 = 0;
    buffer.field_14 = 0;
    buffer.field_18 = 0;
    buffer.field_10 = *count;
    self->vf12(&buffer);
    if (buffer.field_0 != nullptr) {
        *count = buffer.field_12;
        self->vf3();
    } else {
        *count = 0;
    }
    return buffer.field_30;
}

// 0x71003ddce0
u32 Unk_3ddce0(Unk_3dd7b0_T* self) {
    if (self->field_20_0)
        return 1;
    u32 result = self->vf10();
    if (result == 1)
        self->field_20_0 = 1;
    return result;
}
