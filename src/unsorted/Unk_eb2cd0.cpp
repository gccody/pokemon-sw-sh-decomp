// Scope: common
//
// The destructor and virtual functions of Unk_23f5ec8
// (src/unsorted/Unk_23f5ec8.h). Its destructor is its key function: its
// vtable and thunks are emitted here.
#include "unsorted/Unk_23f5ec8.h"

// 0x7100eb2cd0, 0x7100eb2eb0 (D0: a trap, the class is abstract), thunks
// 0x7100eb2d70/0x7100eb2ec0 (+0x48) and 0x7100eb2e10/0x7100eb2ed0 (+0x50)
Unk_23f5ec8::~Unk_23f5ec8() {}

// 0x7100eb5320
void Unk_23f5ec8::vf12() {
    Unk_eb5330(this, 0);
}

// 0x7100eb5790, thunks 0x7100eb57a0 (+0x48) and 0x7100eb57b0 (+0x50)
const Unk_239a418_Type* Unk_23f5ec8::vf_type() {
    return Unk_eb57c0();
}
