// Scope: common
//
// A class (vtable 0x71023a7ca0) on Unk_23a7ca0_Primary (src/unsorted/Unk_23a7ca0_Base.h), each with
// a holder (Unk_236d3d8). Its destructor is its key function: its vtable is
// emitted here. Placeholder names: rename once the
// classes are known.
#include "unsorted/Unk_23a7ca0_Base.h"

class Unk_23a7ca0 : public Unk_23a7ca0_Primary, public Unk_23a7ca0_Interface {
public:
    ~Unk_23a7ca0() override;
    void vf2() override;
    void vf3() override;

    Unk_236d3d8 field_50;
};
static_assert(sizeof(Unk_23a7ca0) == 0x160, "Unk_23a7ca0");
static_assert(__builtin_offsetof(Unk_23a7ca0, field_50) == 0x50, "Unk_23a7ca0::field_50");

// 0x7100786130, its D0
Unk_23a7ca0::~Unk_23a7ca0() {}
