// Scope: common
//
// A class with nothing in its vtable but its destructor (vtable
// 0x71023a7fc0): sixteen entries of two references. Its destructor is its key
// function: its vtable is emitted here. Placeholder names: rename once the
// class is known.
#include "gflib3/Unk_239a418.h"

struct Unk_23a7fc0_Entry {
    Unk_239a418_Ref<Unk_239a418> field_0;
    Unk_239a418_Ref<Unk_239a418> field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_23a7fc0_Entry) == 0x18, "Unk_23a7fc0_Entry");

class Unk_23a7fc0 {
public:
    virtual ~Unk_23a7fc0();

    u64 field_8;
    Unk_23a7fc0_Entry field_10[16];
};
static_assert(sizeof(Unk_23a7fc0) == 0x190, "Unk_23a7fc0");

// 0x710078fcb0, its D0
Unk_23a7fc0::~Unk_23a7fc0() {}
