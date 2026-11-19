// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102437418): a
// vector of words. Its destructor is its key function: its vtable and thunks
// are emitted here. Placeholder names: rename once the class is known.
#include <vector>

#include "gflib3/Unk_239a418.h"

class Unk_2437418 : public Unk_239a418 {
public:
    ~Unk_2437418() override;
    const Unk_239a418_Type* vf_type() override;

    std::vector<u64, Unk_239a418_StdAllocator<u64>> field_60;
};
static_assert(sizeof(Unk_2437418) == 0x80, "Unk_2437418");

// 0x7101400940, its D0 and thunks for +0x48 and +0x50
Unk_2437418::~Unk_2437418() {}
