// Scope: common
// A class of game/nesthole on gflib3's object (vtable 0x7102402190) that
// holds six references: its constructor, destructors and the accessors of the
// references. Its destructor is its key function: its vtables are emitted here
// (vf_type and its thunks are in src/unsorted/types/Unk_fa24e0.cpp).
// Placeholder names: rename once the class is known.
#include "unsorted/nesthole/Unk_fa2190.h"

// 0x7100fa2190
Unk_2402180::Unk_2402180() {}

// 0x7100fa21e0
void Unk_2402180::Unk_fa21e0(const Unk_2402180_Refs& refs) {
    field_60 = refs;
}

// 0x7100fa2340
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa2340() const {
    return field_60.field_0;
}

// 0x7100fa2360
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa2360() const {
    return field_60.field_8;
}

// 0x7100fa2380
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa2380() const {
    return field_60.field_10;
}

// 0x7100fa23a0
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa23a0() const {
    return field_60.field_18;
}

// 0x7100fa23c0
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa23c0() const {
    return field_60.field_20;
}

// 0x7100fa23e0
Unk_239a418_Ref<Unk_239a418> Unk_2402180::Unk_fa23e0() const {
    return field_60.field_28;
}

// 0x7100fa2400, 0x7100fa24d0 (D0), thunks 0x7100fa24f0/0x7100fa2500 (+0x48)
// and 0x7100fa2530/0x7100fa2540 (+0x50)
Unk_2402180::~Unk_2402180() {}
