// Scope: common
//
// The out-of-line virtual functions of Unk_23dc940 (src/unsorted/Unk_23dc940.h).
// vf10 is its key function: its vtable is emitted here, with its D0
// (0x7100c64ca0), its destructor thunks (0x7100c64d70/0x7100c64d80 for +0x48,
// 0x7100c64ef0/0x7100c64f00 for +0x50, all `b <D2>`) and its inline functions.
#include "unsorted/Unk_23dc940.h"

// 0x7100c628b0
u32 Unk_23dc940::vf10() {
    field_1e0 = 1;
    return 1;
}

// 0x7100c628c0
u32 Unk_23dc940::vf12() {
    return 1;
}

// 0x7100c63380
void Unk_23dc940::vf24() {}

// 0x7100c63390
void Unk_23dc940::vf25() {
    field_308 = field_b8;
    field_300 = field_b0;
}

// 0x7100c64cb0, thunks with it inlined 0x7100c64d90 (+0x48) and 0x7100c64e40
// (+0x50)
const Unk_239a418_Type* Unk_23dc940::vf_type() {
    return Unk_GetType();
}
