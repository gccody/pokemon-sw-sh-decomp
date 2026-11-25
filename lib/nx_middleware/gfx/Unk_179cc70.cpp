// Scope: common
// NintendoWare ui2d 7.3.2's initialisation: its SDK MW tag, then the
// allocator (0x710179ccc0, which the original calls instead of inlining).
// Placeholder names.
#include <nn/os.h>
#include "nx_middleware/gfx/Unk_179cc10.h"

// 0x710179cc70
void Unk_179cc70(Unk_179cc10_AllocateFunction allocateFunction, Unk_179cc10_FreeFunction freeFunction,
                 void* userData) {
    nn::util::ReferSymbol("SDK MW+Nintendo+NintendoWare_Ui2d-7_3_2-Release");
    Unk_179ccc0(allocateFunction, freeFunction, userData);
}
