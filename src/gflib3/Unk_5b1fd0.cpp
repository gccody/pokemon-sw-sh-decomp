// Scope: common
// Unk_2398848's slots on its vector at +0xf8 and its destructor
// (src/gflib3/Unk_5b2810.h). Its destructor is its key function: its vtables
// come with it, and with them its D0 and destructor thunks. Slot 24
// (0x71005b1ee0) is written here so that its thunk, which inlines it, comes
// with it. Placeholder names.
#include "gflib3/Unk_5b2810.h"

// 0x71005b1ee0, 0x71005b1fd0 (its thunk from +0x48)
const Unk_8a9570_Name& Unk_2398848::vf24(const Unk_2398848_Id& id) {
    return id.field_0 ? field_f8.at(id.field_4).field_8 : Unk_8a9570_Name::Default();
}

// 0x71005b20c0, 0x71005b22d0 (its thunk from +0x48)
// NON_MATCHING: the test that the value changed. The original tests both
// values against zero, then the callable, then their exclusive or, in two
// branches; this compares the bytes and merges both tests into one (ccmp).
// As bytes, compared through their truths, the second value's load sinks
// below the callable's test instead. The slot of the vector at +0xc8
// (0x71005b1bc0) has the same shape, where the u32 and float ones
// (0x71005b1140, 0x71005b1680) compare and merge.
void Unk_2398848::vf25(const Unk_2398848_Id& id, bool value) {
    Unk_2398848_Trigger& entry = field_f8.at(id.field_4);
    bool before = entry.field_28;
    entry.field_28 = value;
    bool after = field_f8.at(id.field_4).field_28;
    if (field_2b0 && before != after) {
        Unk_2398848_Event event(Unk_2398848::vf24(id), id, before, after);
        field_2b0(&event);
    }
}

// 0x71005b2280, 0x71005b22e0 (its thunk from +0x48)
bool Unk_2398848::vf26(const Unk_2398848_Id& id) {
    return field_f8.at(id.field_4).field_28;
}

// 0x71005b2330, 0x71005b2380 (its thunk from +0x48)
void Unk_2398848::vf27(const Unk_2398848_Id& id) {
    field_f8.at(id.field_4).field_29 = true;
}

// 0x71005b23d0, 0x71005b2420 (its thunk from +0x48)
bool Unk_2398848::vf28(const Unk_2398848_Id& id) {
    return field_f8.at(id.field_4).field_29;
}

// 0x71005b2470, 0x71005b24d0 (its thunk from +0x48)
void Unk_2398848::vf29() {
    for (u32 i = 0; i < field_f8.size(); ++i) {
        Unk_2398848_Trigger& entry = field_f8[i];
        if (entry.field_29)
            entry.field_29 = false;
        else
            entry.field_28 = false;
    }
}

// 0x71005b2530, 0x71005b27b0 (D0), thunks 0x71005b2ac0/0x71005b2ad0 (+0x48)
// and 0x71005b2e30/0x71005b2e40 (+0x50)
Unk_2398848::~Unk_2398848() {}
