// Scope: common
// Unk_23ad0d8's functions (the TU of 0x7100831b10-0x7100831f90). 0x7100831c60
// and 0x7100831d80 call leaf placeholders declared without the parameter
// they're given (0x71007ef6a0, 0x71007ef2b0).
#include "unsorted/unk_82e410/Handler.h"

void Unk_8098b0(void* self,
                void* arg1,
                Unk_813130* list,
                void* arg3,
                void* arg4,
                u8 arg5,
                u32 arg6,
                u32 kind);
void Unk_809b00(void* self, void* arg1, Unk_813130* list, void* arg3, u8 arg4);

// 0x7100831b40
void Unk_831b40(Unk_23ad0d8* self, Unk_23acc98_Result& /*result*/, const Unk_831b40_Arg& arg) {
    Unk_831c60(self, arg.field_8, arg, arg.field_18);
    Unk_831d80(self, arg.field_18);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 0, 0xa3);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 1, 0xa2);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 0, 0xa4);
    Unk_831e80(self, arg.field_18);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 0, 0xa5);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 0, 0xa6);
    Unk_8098b0(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_0, arg.field_8,
               arg.field_20, 1, 0xa7);
    Unk_809b00(Unk_23acc98_Field38(self), arg.field_10, arg.field_18, arg.field_8, arg.field_20);
}
