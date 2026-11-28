// Scope: common
// The constructor, destructors and the writing virtual functions of
// Unk_2432ba8. The destructor is its key function: its vtables and thunks are
// emitted here.
#include "battle/battle_engine/Unk_137af00.h"

#include <cstring>

// 0x710137b110
Unk_2432ba8::Unk_2432ba8() {
    vf10();
}

// 0x710137b1d0, 0x710137b2c0 (D0), thunks 0x710137b220/0x710137b310 (+0x48)
// and 0x710137b270/0x710137b360 (+0x50)
Unk_2432ba8::~Unk_2432ba8() {}

// 0x710137b180
void Unk_2432ba8::vf10() {
    std::memset(&field_60, 0, sizeof(field_60));
    field_60.field_10c = -1;
    field_60.field_110 = -1;
    field_60.field_130 = 0;
    field_27c = 0;
    field_27e = 0;
    field_280 = 0;
    field_282 = 0;
    field_284 = -1;
}

// 0x710137b3b0
void Unk_2432ba8::vf7() {
    vf10();
    vf9();
}

// 0x710137b410
void Unk_2432ba8::vf9() {
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x1b882b09;
        store->Unk_13456e0(key, &field_60, sizeof(field_60));
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x3f8120ba;
        Unk_1345aa0(store, key, field_27c);
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x9ec079da;
        Unk_1345aa0(store, key, field_27e);
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0xe2798dde;
        Unk_134c3e0(store, key, field_280);
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0x6c99f9a0;
        Unk_1345aa0(store, key, field_282);
    }
    {
        Unk_13471e0_Store* store = Unk_137e480(Unk_24ba4e0, 0);
        u32 key = 0xc7652f1c;
        Unk_1358150(store, key, field_284);
    }
}
