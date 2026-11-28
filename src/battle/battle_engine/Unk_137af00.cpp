// Scope: common
// The constructor, destructors and the writing virtual functions of
// Unk_2432ba8. The destructor is its key function: its vtables and thunks are
// emitted here.
#include "battle/battle_engine/Unk_137af00.h"

#include <cstring>

// 0x710137b110
// NON_MATCHING: the inlined vf10, as vf10's.
Unk_2432ba8::Unk_2432ba8() {
    vf10();
}

// 0x710137b1d0, 0x710137b2c0 (D0), thunks 0x710137b220/0x710137b310 (+0x48)
// and 0x710137b270/0x710137b360 (+0x50)
Unk_2432ba8::~Unk_2432ba8() {}

// 0x710137b180
// NON_MATCHING: the original computes the address of field_60.field_10c
// (x20 = this + 0x16c) before the memset and keeps it across the call; this
// computes it after (x8). Every spelling tried (two s32, an 8-byte pair, a
// reference taken first, memset 0xff, value-initialising a block with
// default member initialisers, in place or through a temporary) does that.
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
// NON_MATCHING: the inlined vf10, as vf10's.
void Unk_2432ba8::vf7() {
    vf10();
    vf9();
}

// 0x710137b410
// NON_MATCHING: the first key is at sp+0x1c, the original's at sp+0x18 (with
// 4 unused bytes above it); every other slot matches. Named and temporary
// data/size/which, the key declared first and inline helpers taking it
// don't give the original's layout.
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
