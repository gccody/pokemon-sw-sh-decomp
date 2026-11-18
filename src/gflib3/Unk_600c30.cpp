// Scope: common
//
// The destructor and virtual functions of Unk_239bb58
// (src/gflib3/Unk_239bb58.h). Its destructor is its key function: its
// vtable and thunks are emitted here.
#include "gflib3/Unk_239bb58.h"

// 0x7100600c30, 0x7100600ea0 (D0), thunks 0x7100600d00/0x7100600f70 (+0x48)
// and 0x7100600dd0/0x7100601040 (+0x50)
Unk_239bb58::~Unk_239bb58() {}

// 0x71006014e0, thunks 0x7100601500 (+0x48) and 0x7100601510 (+0x50)
const Unk_239a418_Type* Unk_239bb58::vf_type() {
    return Unk_601520();
}

// 0x71006014f0
void Unk_239bb58::vf7() {}

// 0x71005ff390
void Unk_239bb58::vf9() {}

// 0x71005ff3a0
void Unk_239bb58::vf10() {}

// 0x71005ff3b0
bool Unk_239bb58::vf11() {
    return field_78 == 0xffffffff;
}
