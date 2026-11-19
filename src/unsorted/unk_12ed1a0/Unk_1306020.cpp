// Scope: common
//
// A class (vtable 0x710242f448) on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h), with ten
// holders (Unk_236d3d8). Its destructor is its key function: its vtable is
// emitted here. Placeholder names: rename once the
// classes are known.
#include "unsorted/Unk_23a7ca0_Base.h"

class Unk_242f448 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_242f448() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50[10];
};
static_assert(sizeof(Unk_242f448) == 0xaf0, "Unk_242f448");

// 0x7101306020, its D0
Unk_242f448::~Unk_242f448() {}
