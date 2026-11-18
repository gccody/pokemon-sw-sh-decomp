// Scope: common
//
// The destructor and out-of-line virtual functions of Unk_23c9470
// (src/unsorted/Unk_23c9470.h). Its destructor is its key function here: its
// vtable, inline functions and thunks are emitted here.
#include "unsorted/Unk_23c9470.h"

// 0x7100ac70e0, 0x7100ad0bb0 (D0), thunks 0x7100ad0c00/0x7100ad0c10 (+0x48)
// and 0x7100ad0c40/0x7100ad0c50 (+0x50)
Unk_23c9470::~Unk_23c9470() {}

// 0x7100ad0bc0, thunks 0x7100ad0c20 (+0x48) and 0x7100ad0c30 (+0x50): they
// tail-call its getter (0x7100ac7630), which inlines Unk_23f4660's
const Unk_239a418_Type* Unk_23c9470::vf_type() {
    return Unk_GetType();
}

// 0x7100aced10
void Unk_23c9470::vf20() {
    field_600 = 0;
    field_608 = 0;
}

// 0x7100ac7470
void Unk_23c9470::vf21() {
    field_630->field_58 = field_630->field_58 & 0xfe;
}
