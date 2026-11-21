// Scope: common
// The effect between a source and what plays it that has samples of its own
// (on the class with the vtable 0x7102384c90), and two deleting destructors.
// Written from the executable. Placeholder names.
#include "Unk_2384c90.h"
#include "Unk_3dd7b0.h"

// 0x71003dc880: the deleting destructor of what an effect starts with
void Unk_3dc880(Unk_24df148_SlotCtx* self) {
    Unk_2380be8_Dtor(self);
    operator delete(self);
}

void* Unk_3046a0(int poolId, u64 size, u32 align);

// 0x71003dc8e0: samples through the effect, in place
void Unk_3dc8e0(Unk_2384c90_T* self, Unk_3dd7b0_Buffer* buffer) {
    // The playing context is found before it is known to be needed.
    Unk_3dcd40_Playing* playing = static_cast<Unk_3dcd40_Playing*>(
        static_cast<Unk_3dcd40_Ctx*>(self->field_10)->field_20);
    if (self->field_8a != 0 || playing->field_e4 != 0) {
        if (!self->field_8c)
            self->field_98->vf3();
        self->field_8c = 1;
        return;
    }
    self->field_8c = 0;
    if (buffer->field_30 == 0x11)
        self->field_88 = true;
    if (buffer->field_0 == nullptr) {
        self->field_a0 = Unk_3046a0(Unk_2381488,
                                    sizeof(f32) * buffer->field_10 * (buffer->field_8 & 0xff), 0x10);
        if (self->field_a0 == nullptr) {
            buffer->field_30 = 2;
            return;
        }
        buffer->field_0 = self->field_a0;
        buffer->field_12 = 0;
    }
    buffer->field_c = buffer->field_30;
    self->field_98->vf8(buffer);
    buffer->field_30 = buffer->field_c;
}

// 0x71003dc9e0
void Unk_3dc9e0(Unk_2384c90_T* self) {
    if (self->field_a0 != nullptr) {
        Unk_304740(Unk_2381488, self->field_a0);
        self->field_a0 = nullptr;
    } else if (self->field_8 != nullptr) {
        self->field_8->vf3();
    }
}

// 0x71003dca80
void Unk_3dca80(Unk_2384c90_T* self, u32 arg1) {
    if (arg1 != 2)
        self->field_98->vf3();
    reinterpret_cast<Unk_2384c90*>(self)->vf5(arg1);
}

// 0x71003dcac0
// NON_MATCHING: the original compares the result of the last call with 1
// and returns it either way (a `cmp w0, #1` that nothing reads, after a
// call that is not a tail call); here the call is the function's last thing.
u32 Unk_3dcac0(Unk_2384c90_T* self, Unk_2384c90_Plugin* plugin, void* arg2, u32 arg3, void* arg4,
               Unk_2384c90_Info* info) {
    self->field_a8 = info->field_4;
    self->field_98 = plugin;
    self->field_a0 = nullptr;
    u32 result = Unk_3dcd40(self, plugin, arg2, arg3, arg4);
    if (result != 1)
        return result;
    result = self->field_98->vf7(&Unk_2380d10, self->field_18,
                                 *reinterpret_cast<void**>(&self->field_20._8[0]), info);
    if (result != 1)
        return result;
    result = self->field_98->vf3();
    if (result != 1)
        return result;
    return 1;
}

// 0x71003dcb40
void Unk_3dcb40(Unk_2384c90_T* self) {
    self->vf12();
    Unk_3dce10(self);
}

// 0x71003dcb70
void Unk_3dcb70(Unk_2384c90_T* self) {
    if (self->field_98 != nullptr) {
        self->field_98->vf2(&Unk_2380d10);
        self->field_98 = nullptr;
    }
    if (self->field_a0 != nullptr) {
        Unk_3047c0(Unk_2381488, self->field_a0);
        self->field_a0 = nullptr;
    }
}

// 0x71003dcbd0
u32 Unk_3dcbd0(Unk_2384c90_T* self, u32* count) {
    if (self->field_88)
        return 0x11;
    if (self->field_98 != nullptr)
        self->field_98->vf9(*count);
    return self->field_8->vf4(count);
}

// 0x71003dd5c0
void Unk_3dd5c0(Unk_2384c90_T* self) {
    if (self->field_98 != nullptr) {
        self->field_98->vf2(&Unk_2380d10);
        self->field_98 = nullptr;
    }
}

// 0x71003dd750: the deleting destructor of the class on it with nothing of
// its own to destroy
void Unk_3dd750(Unk_2384c90_T* self) {
    *reinterpret_cast<void***>(self) = Unk_2384c90_Vtable + 2;
    Unk_2380be8_Dtor(&self->field_20);
    operator delete(self);
}
