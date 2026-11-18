// Scope: common
//
// The destructor and vf_type of Unk_23a45c8 (src/unsorted/Unk_23a45c8.h).
// Its destructor is its key function: its vtable and thunks are emitted here.
#include "unsorted/Unk_23a45c8.h"

// 0x71006ce5e0, 0x71006ce700 (D0: a trap, the class is abstract), thunks
// 0x71006ce720/0x71006ce730 (+0x48) and 0x71006ce760/0x71006ce770 (+0x50)
Unk_23a45c8::~Unk_23a45c8() {}

// 0x71006ce710, thunks 0x71006ce740 (+0x48) and 0x71006ce750 (+0x50)
const Unk_239a418_Type* Unk_23a45c8::vf_type() {
    return Unk_GetType();
}
