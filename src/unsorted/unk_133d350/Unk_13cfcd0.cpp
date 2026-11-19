// Scope: common
//
// A class on Unk_2434918 (vtable 0x7102435880): a vector of references and a
// reference. Its destructor is its key function: its vtable and thunks are
// emitted here. Placeholder names: rename once the class is known.
#include <vector>

#include "unsorted/unk_133d350/Unk_2434918.h"

class Unk_2435880 : public Unk_2434918 {
public:
    ~Unk_2435880() override;
    const Unk_239a418_Type* vf_type() override;
    bool vf7(bool value) override;

    u64 field_100;
    std::vector<Unk_239a418_Ref<Unk_239a418>,
                Unk_239a418_StdAllocator<Unk_239a418_Ref<Unk_239a418>>>
        field_108;
    u64 field_128;
    u64 field_130;
    u64 field_138;
    Unk_239a418_Ref<Unk_239a418> field_140;
};
static_assert(sizeof(Unk_2435880) == 0x150, "Unk_2435880");
static_assert(__builtin_offsetof(Unk_2435880, field_108) == 0x108, "Unk_2435880::field_108");
static_assert(__builtin_offsetof(Unk_2435880, field_140) == 0x140, "Unk_2435880::field_140");

// 0x71013cfcd0, its D0 and thunks for +0x48 and +0x50
Unk_2435880::~Unk_2435880() {}
