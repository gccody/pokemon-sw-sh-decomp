// Scope: common
//
// A class on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h, vtable
// 0x710236d768) with five holders (Unk_236d3d8). Its destructor is its key
// function: its vtable is emitted here. Placeholder names: rename once the
// class is known.
#include "unsorted/Unk_23a7ca0_Base.h"

class Unk_236d768 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_236d768() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50[5];
};
static_assert(sizeof(Unk_236d768) == 0x5a0, "Unk_236d768");

// 0x710000ba20, its D0
Unk_236d768::~Unk_236d768() {}
