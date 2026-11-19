// Scope: common
// Unk_23ad1d8's function (the TU of 0x71008331d0-0x71008332e0).
#include "unsorted/unk_82e410/Handler.h"

bool Unk_806770(void* self, void* object, u32 value, u8 arg3);

// 0x7100833200
void Unk_833200(Unk_23ad1d8* self, Unk_23acc98_Result& result, const Unk_833200_Arg& arg) {
    result.field_0 = false;
    if (Unk_806770(Unk_23acc98_Field38(self), arg.field_0, arg.field_8, arg.field_c))
        result.field_0 = true;
}
