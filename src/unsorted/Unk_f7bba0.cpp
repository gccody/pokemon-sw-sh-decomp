// Scope: common
//
// The destructor and small virtual functions of Unk_24006c0
// (src/unsorted/Unk_24006c0.h). Its destructor is its key function here: its
// vtable, inline functions and thunks are emitted here.
#include "unsorted/Unk_24006c0.h"

// 0x7100f7bba0, 0x7100f7def0 (D0), thunks 0x7100f7df00/0x7100f7df10 (+0x48)
// and 0x7100f7df20/0x7100f7df30 (+0x50)
Unk_24006c0::~Unk_24006c0() {}

// 0x7100f7dbc0
void Unk_24006c0::vf9() {}

// 0x7100f7dbd0
void Unk_24006c0::vf17(u32) {}

// 0x7100f7dd40
void Unk_24006c0::vf13() {
    field_78 = 3;
    vf17(3);
}

// 0x7100f7dd60
void Unk_24006c0::vf14() {
    field_78 = 4;
    vf17(4);
}

// 0x7100f7dd80
void Unk_24006c0::vf15() {
    field_78 = 5;
    vf17(5);
}
