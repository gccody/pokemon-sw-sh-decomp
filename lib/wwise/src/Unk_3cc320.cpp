// Scope: common
// The source that reads its samples from a stream (vtable 0x7102384080, on
// the class of 0x7102383f80). Written from the executable. Placeholder
// names.
#include "Unk_2384080.h"

#include <string.h>

extern int Unk_2381488;
extern void* Unk_2384080_Vtable[];

void* Unk_3045e0(int poolId, u64 size);
u32 Unk_3047c0(int poolId, void* ptr);
void Unk_3cbca0(Unk_2383f80* self);
void Unk_3cbcd0(void* self);
u32 Unk_3cc0e0(Unk_2383f80* self);
u32 Unk_3cc4d0(Unk_2384080* self);
u32 Unk_3cc6a0(Unk_2384080* self, Unk_3cc420_Arg* arg, bool arg2);
u32 Unk_3cc7b0(Unk_2384080* self, bool* result);
u32 Unk_3ccf50(Unk_2384080* self, u32 position, u32* result);
u32 Unk_405700(Unk_2384080* self);

// 0x71003cc320: one loop less
u32 Unk_3cc320(Unk_2384080* self, bool last) {
    if (self->field_54 > 1)
        self->field_54--;
    return last ? 0x11 : 0x2d;
}

// 0x71003cc350
Unk_2384080::Unk_2384080() {
    field_0 = Unk_2384080_Vtable + 2;
    field_58 = nullptr;
    field_60 = nullptr;
    field_68 = 0;
    field_6c = 0;
    field_70 = 0;
    field_74 = 0;
    field_78 = 0;
    field_7c = 0;
    field_80 = 0;
    field_82_0 = 0;
    field_82_1 = 0;
    field_82_2 = 0;
    field_82_3 = 0;
    field_82_4 = 0;
}

// 0x71003cc3a0: the destructor
void Unk_3cc3a0(void* arg) {
    Unk_2384080* self = static_cast<Unk_2384080*>(arg);
    self->field_0 = Unk_2384080_Vtable + 2;
    if (self->field_10 != nullptr && !self->field_82_4)
        Unk_3047c0(Unk_2381488, self->field_10);
    if (self->field_58 != nullptr)
        reinterpret_cast<Unk_3dd7b0_T*>(self)->vf11();
    Unk_3cbca0(self);
}

// What comes after the stream is there.
static inline u32 Unk_3cc420_Finish(Unk_2384080* self) {
    u32 result = Unk_3cc4d0(self);
    if (result != 1)
        return result;
    return Unk_405700(self);
}

// 0x71003cc420
u32 Unk_3cc420(Unk_2384080* self, Unk_3cc420_Arg* arg) {
    if (self->field_82_2)
        return Unk_405700(self);
    if (self->field_58 != nullptr)
        return Unk_3cc420_Finish(self);
    u32 result = Unk_3cc6a0(self, arg, false);
    if (result != 1)
        return result;
    bool done;
    result = Unk_3cc7b0(self, &done);
    if (result != 1)
        return result;
    result = self->field_58->vf12();
    if (result != 1)
        return result;
    if (done)
        return result;
    return Unk_3cc420_Finish(self);
}

// 0x71003cc930
u32 Unk_3cc930(Unk_2384080* self, u64 arg1, u64 arg2) {
    if (self->field_82_3)
        self->field_60 = self->field_60 + arg1 - arg2;
    return 1;
}

// 0x71003ccad0
void Unk_3ccad0(Unk_2384080* self) {
    if (self->field_58 != nullptr) {
        self->field_58->vf2();
        self->field_58 = nullptr;
    }
    Unk_3cbcd0(self);
}

// 0x71003ccb10
u32 Unk_3ccb10(Unk_2384080* self) {
    self->field_54 = self->field_80 + 1;
    if (self->field_58 != nullptr) {
        Unk_2384080_Info info;
        self->field_58->vf5(&info);
        info.field_8 = 0;
        self->field_58->vf6(&info);
    }
    return 1;
}

// Where the playing context says it is, in the stream.
static inline u32 Unk_3ccc50_Seek(Unk_2384080* self) {
    u32 position = Unk_3cc0e0(self);
    if (Unk_3ccf50(self, position, &self->field_28) != 1)
        return 2;
    self->field_18->SetSeek(position - self->field_28);
    return 1;
}

// 0x71003ccc50
u32 Unk_3ccc50(Unk_2384080* self) {
    return Unk_3ccc50_Seek(self);
}

// 0x71003cd0c0
u32 Unk_3cd0c0(Unk_2384080* self) {
    if (Unk_3ccc50_Seek(self) != 1)
        return 2;
    if (self->field_82_1)
        self->field_82_1 = 0;
    else
        self->field_58->vf17();
    self->field_68 = 0;
    self->field_60 = nullptr;
    return 1;
}

// 0x71003cd170: its own copy of the data it is given, when it needs one
u32 Unk_3cd170(Unk_2384080* self, Unk_3cd170_Data* data) {
    if (self->field_82_4) {
        self->field_10 = data->field_8;
        return 1;
    }
    self->field_10 = Unk_3045e0(Unk_2381488, data->field_0);
    if (self->field_10 == nullptr)
        return 0x34;
    memcpy(self->field_10, data->field_8, data->field_0);
    return 1;
}

// 0x71003cd1f0: one loop less, of both counts
u32 Unk_3cd1f0(Unk_2384080* self, bool last) {
    if (!last)
        self->field_80--;
    if (self->field_54 > 1)
        self->field_54--;
    return last ? 0x11 : 0x2d;
}
