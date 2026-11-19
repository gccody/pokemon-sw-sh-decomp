// Scope: common
// Unk_23aced8's function (the TU of 0x710082ee40-0x710082ef90).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void Unk_80f3e0(void* self, u8 kind, u16 id);
void Unk_80fb90(void* self, void* object, u32 id, u32 arg3, u32 arg4, u32 arg5);

// 0x710082ee70
void Unk_82ee70(Unk_23aced8* self, Unk_23acc98_Result& /*result*/, const Unk_82ee70_Arg& arg) {
    u8 kind = Unk_82abb0(self, Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(arg.field_0)));
    if (kind != 5 && arg.field_a)
        Unk_80f3e0(Unk_23acc98_Field20(self), kind, 0x33);
    Unk_80fb90(Unk_23acc98_Field20(self), arg.field_0, arg.field_8, 0, 0x1f, arg.field_a);
}
