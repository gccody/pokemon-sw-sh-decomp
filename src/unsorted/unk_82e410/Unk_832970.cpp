// Scope: common
// Unk_23ad178's function (the TU of 0x7100832940-0x7100832a40).
#include "unsorted/unk_82e410/Handler.h"

void Unk_810520(void* self,
                void* object,
                void* arg2,
                u8 arg3,
                u8 arg4,
                u32 arg5,
                u32 arg6,
                u16 arg7);

// 0x7100832970
void Unk_832970(Unk_23ad178* self, Unk_23acc98_Result& /*result*/, const Unk_832970_Arg& arg) {
    Unk_810520(Unk_23acc98_Field20(self), arg.field_0, arg.field_8, arg.field_10,
               arg.field_18->field_e, arg.field_18->field_10, arg.field_18->field_0, arg.field_20);
}
