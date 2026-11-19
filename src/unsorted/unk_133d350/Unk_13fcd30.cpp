// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x71024370f8): a
// callback, an array and a vector of references, both emptied first. Its
// destructor is its key function: its vtable and thunks are emitted here.
// Placeholder names: rename once the class is known.
#include <vector>

#include "unsorted/Unk_131fb20_Array.h"

class Unk_24370f8 : public Unk_239a418 {
public:
    ~Unk_24370f8() override;
    const Unk_239a418_Type* vf_type() override;

    u64 field_60;
    u64 field_68;
    u64 field_70;
    u64 field_78;
    std::function<void()> field_80;
    Unk_131fb20_Array<Unk_239a418_Ref<Unk_239a418>> field_b0;
    std::vector<Unk_239a418_Ref<Unk_239a418>,
                Unk_239a418_StdAllocator<Unk_239a418_Ref<Unk_239a418>>>
        field_110;
};
static_assert(sizeof(Unk_24370f8) == 0x130, "Unk_24370f8");
static_assert(__builtin_offsetof(Unk_24370f8, field_b0) == 0xb0, "Unk_24370f8::field_b0");
static_assert(__builtin_offsetof(Unk_24370f8, field_110) == 0x110, "Unk_24370f8::field_110");

// 0x71013fcd30, its D0 and thunks for +0x48 and +0x50
Unk_24370f8::~Unk_24370f8() {
    field_b0.clear();
    field_110.clear();
}
