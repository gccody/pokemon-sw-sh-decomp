// Scope: common
// Unk_23ad158's function (the TU of 0x7100832840-0x7100832940).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_804630_Flow;
struct Unk_7ee6b0;
struct Unk_807e00_Move;
void Unk_80ac20(Unk_804630_Flow* self,
                const Unk_7ee6b0* object,
                const Unk_7ee6b0* arg2,
                const Unk_807e00_Move* arg3,
                u32 arg4,
                u32 arg5,
                bool arg6,
                bool arg7);

// 0x7100832870
void Unk_832870(Unk_23ad158* self, Unk_23acc98_Result& /*result*/, const Unk_832870_Arg& arg) {
    Unk_80ac20(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
               static_cast<const Unk_7ee6b0*>(arg.field_0),
               static_cast<const Unk_7ee6b0*>(arg.field_8),
               static_cast<const Unk_807e00_Move*>(arg.field_10), arg.field_18, arg.field_1c,
               arg.field_20, arg.field_21);
}
