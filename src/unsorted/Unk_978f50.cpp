// Scope: common
//
// The destructor and type getter of Unk_23c1a68 (src/unsorted/Unk_23c1a68.h),
// with its vtable.
#include "unsorted/Unk_23c1a68.h"

// 0x7100978f50, 0x71009790d0 (D0), thunks 0x7100979150/0x7100979160 (+0x48)
// and 0x7100979250/0x7100979260 (+0x50)
Unk_23c1a68::~Unk_23c1a68() {}

// 0x71009790e0, thunks with it inlined 0x7100979170 (+0x48) and 0x71009791e0
// (+0x50)
const Unk_239a418_Type* Unk_23c1a68::vf_type() {
    return Unk_GetType();
}
