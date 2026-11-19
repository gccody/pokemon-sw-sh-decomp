// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x710242f3e0): a
// reference it resets before it goes. Its destructor is its key function: its
// vtable and thunks are emitted here. Placeholder names: rename once the
// class is known.
#include "gflib3/Unk_239a4c0.h"

class Unk_242f3e0 : public Unk_239a4c0 {
public:
    ~Unk_242f3e0() override;

    Unk_239a418_Ref<Unk_239a418> field_58;
};
static_assert(sizeof(Unk_242f3e0) == 0x60, "Unk_242f3e0");
static_assert(__builtin_offsetof(Unk_242f3e0, field_58) == 0x58, "Unk_242f3e0::field_58");

// 0x7101305ad0, its D0 and thunks for +0x48
Unk_242f3e0::~Unk_242f3e0() {
    field_58.Reset();
}
