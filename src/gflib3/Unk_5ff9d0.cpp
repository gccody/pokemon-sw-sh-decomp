// Scope: common
//
// The destructor and virtual functions of Unk_239b8d8
// (src/gflib3/Unk_239b8d8.h). Its destructor is its key function: its vtable,
// D0 and destructor thunks are emitted here.
#include "gflib3/Unk_239b8d8.h"

// 0x71005ff9d0, D0 0x71005ffb30 (a trap), thunks 0x71005ffb50/0x71005ffb60
// (+0x48) and 0x71005ffb90/0x71005ffba0 (+0x50)
Unk_239b8d8::~Unk_239b8d8() {}

// 0x71005ffb40, thunks 0x71005ffb70 (+0x48) and 0x71005ffb80 (+0x50); its
// getter 0x71005ffbb0
const Unk_239a418_Type* Unk_239b8d8::vf_type() {
    return Unk_GetType();
}
