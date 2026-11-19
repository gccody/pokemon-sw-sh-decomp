// Scope: common
// Unk_23ad258's function (the TU of 0x7100834170-0x7100834290).
#include "unsorted/unk_82e410/Handler.h"

u8 Unk_805dc0(void* self);
u8 Unk_805e40(void* self, u8 index, u8 value);

// 0x71008341a0
void Unk_8341a0(Unk_23ad258* self, Unk_8341a0_Result& result, const Unk_8341a0_Arg& arg) {
    u8 value = Unk_805dc0(Unk_23acc98_Field38(self));
    u8 index = arg.field_0;
    if (index != 0x1f)
        value = Unk_805e40(Unk_23acc98_Field38(self), index, value);
    result.field_0 = value;
}
