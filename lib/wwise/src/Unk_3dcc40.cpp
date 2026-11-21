// Scope: common
// An effect between a source and what plays it (vtable 0x7102384c90).
// Written from the executable. Placeholder names.
#include "Unk_2384c90.h"

// 0x71003dcc40: the destructor
void Unk_3dcc40(Unk_2384c90_T* self) {
    *reinterpret_cast<void***>(self) = Unk_2384c90_Vtable + 2;
    Unk_2380be8_Dtor(&self->field_20);
}

// 0x71003dcc70: the deleting destructor
void Unk_3dcc70(Unk_2384c90_T* self) {
    *reinterpret_cast<void***>(self) = Unk_2384c90_Vtable + 2;
    Unk_2380be8_Dtor(&self->field_20);
    operator delete(self);
}

// 0x71003dcd10
u32 Unk_3dcd10(Unk_2384c90_T* self, u64 arg1, bool arg2) {
    if (self->field_88)
        return 1;
    return self->field_8->vf6(arg1, arg2);
}

// 0x71003dce10
void Unk_3dce10(Unk_2384c90_T* self) {
    Unk_362360(reinterpret_cast<Unk_362360_T*>(&self->field_20));
    Unk_24df148_Object* object = self->field_18;
    if (object != nullptr) {
        int pool = Unk_2381488;
        object->vf0();
        Unk_3047c0(pool, object);
        self->field_18 = nullptr;
    }
}

struct Unk_2383e40_T;
struct Unk_360c20_T;
struct Unk_360c20_Params;
struct Unk_369950_Sound;
Unk_360c20_Params* Unk_361400(Unk_362360_T* self, Unk_360c20_T* object, Unk_369950_Sound* sound);
void Unk_3c9bc0(Unk_2383e40_T* self, void* arg1, u32 arg2);

// 0x71003dcd40
u32 Unk_3dcd40(Unk_2384c90_T* self, Unk_2384c90_Plugin* /*plugin*/, void* arg2, u32 arg3,
               void* arg4) {
    Unk_3dcd40_Ctx* ctx = static_cast<Unk_3dcd40_Ctx*>(arg4);
    Unk_3dcd40_Desc** desc = static_cast<Unk_3dcd40_Desc**>(arg2);
    self->field_10 = ctx;
    self->field_18 = nullptr;
    self->field_88 = false;
    self->field_8a = 0;
    self->field_8c = 0;
    self->field_90 = arg3;
    // The playing context of what the source has, then its part at 0x18 again.
    Unk_3dcd40_Second* second = ctx->field_20;
    if (Unk_361400(reinterpret_cast<Unk_362360_T*>(&self->field_20),
                   reinterpret_cast<Unk_360c20_T*>(*desc),
                   reinterpret_cast<Unk_369950_Sound*>(static_cast<Unk_3dcd40_Second*>(
                       static_cast<Unk_3dcd40_Playing*>(second)))) == nullptr)
        return 2;
    self->field_20.field_60 = (*desc)->field_30;
    Unk_2383e40_T* object = static_cast<Unk_2383e40_T*>(Unk_3045e0(Unk_2381488, 0x28));
    if (object != nullptr)
        Unk_3c9bc0(object, ctx, arg3);
    self->field_18 = reinterpret_cast<Unk_24df148_Object*>(object);
    return object != nullptr ? 1 : 2;
}
