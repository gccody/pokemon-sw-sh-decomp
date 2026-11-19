// Scope: common
//
// The box app's first TU (common/box.dat; it sets up the app's states and
// views): the functions decompiled so far.
#include "contents/pokebox/Unk_box.h"

// 0x7100a77470
bool Unk_23c63c8::Unk_a77470(u32 flag) const {
    if (flag <= 8)
        return field_70->field_188[flag];
    return false;
}

// 0x7100a774a0
void Unk_23c63c8::Unk_a774a0(u32 flag) {
    if (flag > 8)
        return;
    field_70->field_188[flag] = false;
}
