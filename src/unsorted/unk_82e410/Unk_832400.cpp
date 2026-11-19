// Scope: common
// Unk_23ad0f8's functions (the TU of 0x7100831f90-0x7100832560). The others,
// 0x7100831fc0 and 0x7100832190, aren't decompiled yet.
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
s32 Unk_7eef50(void* self, u32 index);
void Unk_80fcb0(void* self, void* object, s32 value, u32 arg3, u32 arg4, u8 id);
void Unk_8120a0(void* self, u8 id, u32 arg2, u32 value);
void Unk_812090(void* self, u8 id);
void Unk_806c70(void* self, void* target, void* object);

// 0x7100832400
void Unk_832400(Unk_23ad0f8* self, void* object, void* target, const u32* value, u32 arg4) {
    u8 id = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object));
    Unk_80fcb0(Unk_23acc98_Field20(self), object, Unk_7eef50(object, 0xd), 1, 5,
               Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(target)));
    Unk_8120a0(Unk_23acc98_Field20(self), id, arg4, *value);
    Unk_812090(Unk_23acc98_Field20(self), id);
    Unk_806c70(Unk_23acc98_Field38(self), target, object);
}
