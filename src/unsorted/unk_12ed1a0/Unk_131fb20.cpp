// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x710242fc60): a
// callback and an array of 16-byte elements. Its destructor is its key function: its vtable
// and thunks are emitted here. Placeholder names: rename once the class is
// known.
#include "unsorted/Unk_131fb20_Array.h"

// The array's element.
struct Unk_242fc60_Element {
    u64 field_0;
    u64 field_8;
};

class Unk_242fc60 : public Unk_239a418 {
public:
    ~Unk_242fc60() override;
    const Unk_239a418_Type* vf_type() override;
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual u32 vf10();

    u64 field_60;
    u64 field_68;
    std::function<void()> field_70;
    Unk_131fb20_Array<Unk_242fc60_Element> field_a0;
};
static_assert(sizeof(Unk_242fc60) == 0x100, "Unk_242fc60");
static_assert(__builtin_offsetof(Unk_242fc60, field_70) == 0x70, "Unk_242fc60::field_70");
static_assert(__builtin_offsetof(Unk_242fc60, field_a0) == 0xa0, "Unk_242fc60::field_a0");

// 0x710131fb20, 0x710131fc10 (D0), thunks 0x710131ff00/0x710131fff0 (+0x48)
// and 0x71013201c0/0x71013202b0 (+0x50)
Unk_242fc60::~Unk_242fc60() {}
