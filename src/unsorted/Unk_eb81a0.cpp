// Scope: common
//
// The destructor and vf_type of Unk_23f6328 (src/unsorted/Unk_23f6328.h). Its
// destructor is its key function: its vtable and thunks are emitted here, and
// Unk_236d3f8's vtable and destructors with it.
#include "unsorted/Unk_23f6328.h"

// 0x7100eb81a0, 0x7100eb8f40 (D0: a trap, the class is abstract), thunks
// 0x7100eb8f60/0x7100eb8f70 (+0x48) and 0x7100eb8fa0/0x7100eb8fb0 (+0x50)
Unk_23f6328::~Unk_23f6328() {}

// 0x7100eb8f50, thunks 0x7100eb8f80 (+0x48) and 0x7100eb8f90 (+0x50)
const Unk_239a418_Type* Unk_23f6328::vf_type() {
    return Unk_GetType();
}
