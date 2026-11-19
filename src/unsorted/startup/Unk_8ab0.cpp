// Scope: common
//
// A class on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h, vtable
// 0x710236d468) with eight holders (Unk_236d4d8). Its destructor is its key
// function: its vtable is emitted here. Placeholder names: rename once the
// class is known.
#include "unsorted/Unk_23a7ca0_Base.h"

class Unk_236d468 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d468() override;
    void vf2() override;
    void vf3() override;

    Unk_236d4d8 field_50[8];
};
static_assert(sizeof(Unk_236d468) == 0x8d0, "Unk_236d468");

// 0x7100008ab0, its D0
Unk_236d468::~Unk_236d468() {}
