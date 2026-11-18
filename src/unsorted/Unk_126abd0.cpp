// Scope: common
//
// The virtual functions of Unk_24284d0 (src/unsorted/Unk_24284d0.h). vf7 is
// its key function: its vtable, its inline destructor and vf_type, and their
// thunks are emitted here.
#include "unsorted/Unk_24284d0.h"

// 0x710126abd0
void Unk_24284d0::vf7(u64 arg) {
    field_68 = arg;
    field_70.Reset();
}

// 0x710126ac00
Unk_239a418_Ref<Unk_239a418> Unk_24284d0::vf8() {
    if (field_70.m_ptr)
        return field_70;
    return Unk_239a418_Ref<Unk_239a418>(this);
}

// 0x710126ac30
void Unk_24284d0::vf9() {
    field_70.Reset();
    field_78.Reset();
}

// 0x710126ad40
void Unk_24284d0::vf10() {}

// The destructor (implicit): 0x710126bd00, 0x710126be50 (D0), thunks
// 0x710126c090/0x710126c1d0 (+0x48) and 0x710126c330/0x710126c470 (+0x50).
// vf_type is 0x710126bfa0, its thunks 0x710126c310 (+0x48) and 0x710126c320
// (+0x50).
