// Scope: common
//
// The constructor and the destructor of Unk_23f5d00 (src/unsorted/
// Unk_23f5d00.h), its key function: its vtable, D0 and thunks are emitted
// here, and vf5.
#include "unsorted/Unk_23f5d00.h"
#include "unsorted/Unk_2771620.h"

// 0x7100ead190 (Shield 0x7100ead1c0)
Unk_23f5d00::Unk_23f5d00() : field_60(), field_170(), field_178(0) {}

// 0x7100ead240 (Shield 0x7100ead270), D0 0x7100ead370 (Shield 0x7100ead3a0),
// thunks 0x7100ead360/0x7100ead380 (Shield 0x7100ead390/0x7100ead3b0)
Unk_23f5d00::~Unk_23f5d00() {
    field_60.Reset();
}

// 0x7100ead390 (Shield 0x7100ead3c0)
u8* Unk_23f5d00::vf5() {
    static u8 s_0;
    return &s_0;
}
