// Scope: common
// Unk_23ad0d8's functions (the TU of 0x7100831b10-0x7100831f90). 0x7100831c60
// and 0x7100831d80 call leaf placeholders declared without the parameter
// they're given (0x71007ef6a0, 0x71007ef2b0).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_804630_Flow;
struct Unk_7ee6b0;
struct Unk_813270;
struct Unk_806e40_Arg;
struct Unk_807e00_Move;
void Unk_8098b0(Unk_804630_Flow* self,
                const Unk_7ee6b0* arg1,
                const Unk_813270* list,
                const Unk_806e40_Arg* arg3,
                const Unk_807e00_Move* arg4,
                bool arg5,
                bool arg6,
                u32 kind);
void Unk_809b00(Unk_804630_Flow* self,
                const Unk_7ee6b0* arg1,
                const Unk_7ee6b0* list,
                const u32* arg3,
                bool arg4);

// 0x7100831b40
void Unk_831b40(Unk_23ad0d8* self, Unk_23acc98_Result& /*result*/, const Unk_831b40_Arg& arg) {
    Unk_831c60(self, arg.field_8, arg, arg.field_18);
    Unk_831d80(self, arg.field_18);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 0, 0xa3);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 1, 0xa2);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 0, 0xa4);
    Unk_831e80(self, arg.field_18);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 0, 0xa5);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 0, 0xa6);
    Unk_8098b0(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_813270*>(arg.field_18),
               static_cast<const Unk_806e40_Arg*>(arg.field_0),
               reinterpret_cast<const Unk_807e00_Move*>(arg.field_8), arg.field_20, 1, 0xa7);
    Unk_809b00(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_10),
               reinterpret_cast<const Unk_7ee6b0*>(arg.field_18),
               reinterpret_cast<const u32*>(arg.field_8), arg.field_20);
}
