// Scope: common
// Unk_23ad0d8's functions (the TU of 0x7100831b10-0x7100831f90).
#include "unsorted/unk_82e410/Handler.h"

struct Unk_7ee6b0;
u8 Unk_7ee6b0_getField7d(const Unk_7ee6b0* self);
void Unk_813130_clearField4e(Unk_813130* self);
void* Unk_813140(Unk_813130* self);

// 0x7100831e80
void Unk_831e80(Unk_23ad0d8* self, Unk_813130* list) {
    Unk_813130_clearField4e(list);
    while (void* object = Unk_813140(list)) {
        Unk_82c210_Arg a{Unk_7ee6b0_getField7d(static_cast<const Unk_7ee6b0*>(object)), 1};
        Unk_23acc98_Result done;
        Unk_82c210(Unk_7e0080_Get2c0(Unk_23acc98_Holder(self)), done, a);
    }
}
