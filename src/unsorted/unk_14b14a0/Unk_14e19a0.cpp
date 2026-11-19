// Scope: common
//
// The UI tree node (src/unsorted/unk_14b14a0/Unk_2444570.h): its constructor,
// destructor (the key function: its vtable and thunks are emitted here) and
// the members of its TU.
#include "unsorted/unk_14b14a0/Unk_2444570.h"

// 0x71014e19a0
Unk_2444570::Unk_2444570()
    : field_60(0),
      field_68(nullptr),
      field_80(false),
      field_81(0),
      field_82(true),
      field_83(true),
      field_84(1),
      field_85(0),
      field_88(0),
      field_90(0) {}

// 0x71014e1a60
void Unk_14e1a60(Unk_2444570* node, u32 arg) {
    for (Unk_2444570* parent = node->field_68; parent; parent = parent->field_68)
        parent->vf11(node, arg);
}

// 0x71014e1ab0
void Unk_2444570::vf10() {
    if (field_80)
        return;
    Unk_14e2020(GetRoot(), false);
    vf20(true);
    for (Unk_2444570* parent = field_68; parent; parent = parent->field_68)
        parent->vf21(true, this);
    field_80 = true;
}

// 0x71014e1ba0, thunks 0x71014e1d70 (+0x48) and 0x71014e1e60 (+0x50); the
// D0s are traps (the class is abstract)
Unk_2444570::~Unk_2444570() {}

// 0x71014e1c80
void Unk_2444570::vf7(u64 arg) {
    static_cast<Unk_2444570_98_Base*>(field_98.m_ptr)->vf5(&field_88, arg);
}

// 0x71014e1ca0
void Unk_2444570::vf8() {
    field_98.m_ptr->vf6(&field_88);
}

// 0x71014e1cc0
void Unk_2444570::vf9(u64 arg) {
    field_98.m_ptr->vf7(&field_88, arg);
}
