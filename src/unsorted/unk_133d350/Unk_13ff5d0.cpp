// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102437338): a
// member with a destructor of its own (0x71013ff7b0), eight references and a
// holder (Unk_236d3d8). Its destructor is its key function: its vtable and
// thunks are emitted here. Placeholder names: rename once the classes are
// known.
#include "unsorted/Unk_236d3d8.h"

// A member with an out-of-line destructor (0x71013ff7b0), not decompiled
// yet.
struct Unk_13ff7b0 {
    ~Unk_13ff7b0();

    u8 _0[0x150];
};

class Unk_2437338 : public Unk_239a418 {
public:
    ~Unk_2437338() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_60;
    u64 field_68;
    Unk_13ff7b0 field_70;
    Unk_239a418_Ref<Unk_239a418> field_1c0;
    Unk_239a418_Ref<Unk_239a418> field_1c8;
    Unk_239a418_Ref<Unk_239a418> field_1d0;
    Unk_239a418_Ref<Unk_239a418> field_1d8;
    Unk_239a418_Ref<Unk_239a418> field_1e0;
    Unk_239a418_Ref<Unk_239a418> field_1e8;
    Unk_239a418_Ref<Unk_239a418> field_1f0;
    u64 field_1f8;
    u64 field_200;
    u64 field_208;
    u64 field_210;
    u64 field_218;
    u64 field_220;
    Unk_239a418_Ref<Unk_239a418> field_228;
    Unk_236d3d8 field_230;
};
static_assert(sizeof(Unk_2437338) == 0x340, "Unk_2437338");
static_assert(__builtin_offsetof(Unk_2437338, field_70) == 0x70, "Unk_2437338::field_70");
static_assert(__builtin_offsetof(Unk_2437338, field_230) == 0x230, "Unk_2437338::field_230");

// 0x71013ff5d0, its D0 and thunks for +0x48 and +0x50
Unk_2437338::~Unk_2437338() {}
