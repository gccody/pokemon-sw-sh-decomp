// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102437048): a
// callback, an array of references (emptied first) and a reference. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the class is known.
#include "unsorted/Unk_131fb20_Array.h"

class Unk_2437048 : public Unk_239a418 {
public:
    ~Unk_2437048() override;
    const Unk_239a418_Type* vf_type() override;

    u8 _60[0x20];
    std::function<void()> field_80;
    Unk_131fb20_Array<Unk_239a418_Ref<Unk_239a418>> field_b0;
    u64 field_110;
    u64 field_118;
    u64 field_120;
    u64 field_128;
    Unk_239a418_Ref<Unk_239a418> field_130;
};
static_assert(sizeof(Unk_2437048) == 0x140, "Unk_2437048");
static_assert(__builtin_offsetof(Unk_2437048, field_b0) == 0xb0, "Unk_2437048::field_b0");
static_assert(__builtin_offsetof(Unk_2437048, field_130) == 0x130, "Unk_2437048::field_130");

// 0x71013fbdc0, its D0 and thunks for +0x48 and +0x50
Unk_2437048::~Unk_2437048() {
    field_b0.clear();
}
