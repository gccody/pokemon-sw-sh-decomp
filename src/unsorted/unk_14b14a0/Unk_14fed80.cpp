// Scope: common
//
// A UI tree node on Unk_24446c0 (vtable 0x7102445fc8) with callables of its own.
// Its destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the class is known.
#include "unsorted/Unk_23d4470.h"
#include "unsorted/unk_14b14a0/Unk_2444570.h"

class Unk_2445fc8 : public Unk_24446c0 {
public:
    ~Unk_2445fc8() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_140;
    u64 field_148;
    Unk_23d4470_Callable field_150;
};
static_assert(sizeof(Unk_2445fc8) == 0x1d0, "Unk_2445fc8");
static_assert(__builtin_offsetof(Unk_2445fc8, field_150) == 0x150, "Unk_2445fc8::field_150");

// 0x71014fed80, its D0 and thunks for +0x48 and +0x50
Unk_2445fc8::~Unk_2445fc8() {}
