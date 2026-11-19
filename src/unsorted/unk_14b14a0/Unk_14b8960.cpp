// Scope: common
//
// A class with nothing in its vtable but its destructor (vtable
// 0x7102442e48): three holders (Unk_236d3d8). Its destructor is its key
// function: its vtable is emitted here. Placeholder names: rename once the
// class is known.
#include "unsorted/Unk_236d3d8.h"

class Unk_2442e48 {
public:
    virtual ~Unk_2442e48();

    u64 field_8;
    Unk_236d3d8 field_10;
    Unk_236d3d8 field_120;
    Unk_236d3d8 field_230;
};
static_assert(sizeof(Unk_2442e48) == 0x340, "Unk_2442e48");

// 0x71014b8960, its D0
Unk_2442e48::~Unk_2442e48() {}
