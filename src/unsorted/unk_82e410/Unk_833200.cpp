// Scope: common
// Unk_23ad1d8's function (the TU of 0x71008331d0-0x71008332e0).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_804630_Flow;
struct Unk_7ee6b0;
bool Unk_806770(Unk_804630_Flow* self, const Unk_7ee6b0* object, u32 value, u8 arg3);

// 0x7100833200
void Unk_833200(Unk_23ad1d8* self, Unk_23acc98_Result& result, const Unk_833200_Arg& arg) {
    result.field_0 = false;
    if (Unk_806770(static_cast<Unk_804630_Flow*>(Unk_23acc98_Field38(self)),
                   static_cast<const Unk_7ee6b0*>(arg.field_0), arg.field_8, arg.field_c))
        result.field_0 = true;
}
