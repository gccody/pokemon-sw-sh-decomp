// Scope: common
// Unk_23acf38's function (the TU of 0x710082f1e0-0x710082f420).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void Unk_80dd60(void* self, const Unk_23acc98_Message* message);
u32 Unk_807250(void* self, void* object, u32 arg2, u8 arg3, u16 arg4, u32 arg5);
bool Unk_8073a0(void* self, void* object, u8 arg2, u32 arg3, u32 arg4, u8 arg5);
void Unk_807490(void* self, void* object, u8 arg2, u32 arg3, u32 arg4);
void Unk_810200(void* self, void* object, u32 arg2, u32 arg3, u16 arg4, u32 arg5, u8 arg6);
void Unk_807300(void* self, u8 arg1, void* object, u32 arg3, u32 arg4);

// 0x710082f210
void Unk_82f210(Unk_23acf38* self, Unk_23acc98_Result& result, const Unk_82f210_Arg& arg) {
    result.field_0 = false;
    result.field_4 = 0;
    Unk_82f450_Arg a{
        arg.field_0,  Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(arg.field_8)),
        arg.field_10, arg.field_14,
        arg.field_18, arg.field_1a,
        arg.field_1c, arg.field_20,
        arg.field_21, arg.field_28};
    Unk_23acc98_Result done;
    Unk_82f450(Unk_7e0080_Get16a0(Unk_23acc98_Holder(self)), done, a);
    if (!done.field_0)
        return;
    result.field_0 = true;
    if (arg.field_38)
        Unk_80dd60(Unk_23acc98_Field20(self), arg.field_38);
    u32 value = Unk_807250(Unk_23acc98_Field38(self), arg.field_8, arg.field_10, arg.field_0,
                           arg.field_1a, arg.field_14);
    if (Unk_8073a0(Unk_23acc98_Field38(self), arg.field_8, arg.field_0, arg.field_10, value,
                   arg.field_18)) {
        Unk_807490(Unk_23acc98_Field38(self), arg.field_8, arg.field_0, arg.field_10, value);
    } else {
        Unk_810200(Unk_23acc98_Field20(self), arg.field_8, arg.field_10, value, arg.field_1a,
                   arg.field_30, arg.field_40);
        Unk_807300(Unk_23acc98_Field38(self), arg.field_0, arg.field_8, arg.field_10, value);
        result.field_4 = value;
    }
}
