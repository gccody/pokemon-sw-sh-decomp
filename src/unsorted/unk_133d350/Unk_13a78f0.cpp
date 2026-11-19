// Scope: common
//
// A class on Unk_23f4e40 (vtable 0x7102433fe8): a holder (Unk_236d3d8) and
// four references. Its destructor is its key function: its vtable and thunks
// are emitted here. Placeholder names: rename once the class is known.
#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23f4e40.h"

class Unk_2433fe8 : public Unk_23f4e40 {
public:
    ~Unk_2433fe8() override;
    const Unk_239a418_Type* vf_type() override;
    u32 vf7() override;
    void vf8() override;
    u32 vf9() override;
    void vf10() override;

    u64 field_88;
    Unk_239a418_Ref<Unk_239a418> field_90;
    u64 field_98;
    Unk_236d3d8 field_a0;
    Unk_239a418_Ref<Unk_239a418> field_1b0;
    Unk_239a418_Ref<Unk_239a418> field_1b8;
    u64 field_1c0;
    Unk_239a418_Ref<Unk_239a418> field_1c8;
};
static_assert(sizeof(Unk_2433fe8) == 0x1d0, "Unk_2433fe8");
static_assert(__builtin_offsetof(Unk_2433fe8, field_a0) == 0xa0, "Unk_2433fe8::field_a0");

// 0x71013a78f0, its D0 and thunks for +0x48 and +0x50
Unk_2433fe8::~Unk_2433fe8() {}
