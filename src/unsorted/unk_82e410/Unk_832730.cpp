// Scope: common
// Unk_23ad138's function (the TU of 0x7100832700-0x7100832840).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void Unk_80e1f0(void* self, void* object, u16 id);
void Unk_8108c0(void* self, u8 id);
void Unk_8121d0(void* self, u8 kind);

// 0x7100832730
void Unk_832730(Unk_23ad138* self, Unk_23acc98_Result& /*result*/, const Unk_832730_Arg& arg) {
    u8 id = Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(arg.field_0));
    u8 kind = Unk_82abb0(self, id);
    if (arg.field_8)
        Unk_80e1f0(Unk_23acc98_Field20(self), arg.field_0, 0x42e);
    Unk_8108c0(Unk_23acc98_Field20(self), id);
    Unk_8121d0(Unk_23acc98_Field20(self), kind);
}
