// Scope: common
// The constructor and destructors of Unk_2432200, and the reset of its block.
// The destructor is its key function: its vtables and thunks are emitted here.
#include "unsorted/Unk_13630d0.h"

#include <algorithm>
#include <cstring>

// 0x7101363740
Unk_2432200::Unk_2432200() {
    Unk_1363780();
}

// 0x7101363780
void Unk_2432200::Unk_1363780() {
    std::memset(field_60.field_0, 0, sizeof(field_60.field_0));
    Unk_ead0f0_Random random;
    random.Unk_ead0f0(Unk_ead110());
    std::uniform_int_distribution<u32> number(1, 100);
    for (int i = 0; i < 512; i++) {
        field_60.field_0[i].field_0 = 0;
        field_60.field_0[i].field_1 = number(random);
        field_60.field_0[i].field_2 = number(random);
    }
    field_60.field_800 = Unk_ead110();
    field_60.field_808 = Unk_ead110();
}

// 0x7101363870, 0x7101363960 (D0), thunks 0x71013638c0/0x71013639b0 (+0x48)
// and 0x7101363910/0x7101363a00 (+0x50)
Unk_2432200::~Unk_2432200() {}
