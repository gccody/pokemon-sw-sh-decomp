// Scope: common
//
// The destructor and small virtual functions of Unk_23f2df0
// (src/unsorted/Unk_23f2df0.h). Its destructor is its key function here: its
// vtable and thunks are emitted here.
#include "unsorted/Unk_23f2df0.h"

// 0x7100e67320
u32 Unk_23f2df0::vf9() {
    return 1;
}

// 0x7100e67330, 0x7100e67480 (D0: a trap, the class is abstract), thunks
// 0x7100e674e0/0x7100e674f0 (+0x48) and 0x7100e67520/0x7100e67530 (+0x50)
Unk_23f2df0::~Unk_23f2df0() {}

// 0x7100e67490, thunks 0x7100e67500 (+0x48) and 0x7100e67510 (+0x50)
const Unk_239a418_Type* Unk_23f2df0::vf_type() {
    return Unk_GetType();
}

// 0x7100e674a0
void Unk_23f2df0::vf10() {}

// 0x7100e674b0
void Unk_23f2df0::vf11() {}

// 0x7100e674c0
void Unk_23f2df0::vf14() {}

// 0x7100e674d0
void Unk_23f2df0::vf15() {}
