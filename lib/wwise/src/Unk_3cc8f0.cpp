// Scope: common
// The stream source's function at 0x71003cc8f0, in a file of its own: the
// original calls 0x71003cc420 where one file would inline it.
#include "Unk_2384080.h"

// 0x71003cc8f0
u32 Unk_3cc8f0(Unk_2384080* self) {
    Unk_3cc420_Arg arg;
    arg.field_0 = 0;
    arg.field_4 = 0x800;
    arg.field_8 = 0;
    return Unk_3cc420(self, &arg);
}
