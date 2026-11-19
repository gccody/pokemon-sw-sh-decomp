// Scope: common
//
// A class on gflib3's reference-counted object (vtable 0x7102435cb8): a
// vector of 0x40-byte elements that start with a reference. Its destructor is
// its key function: its vtable and thunks are emitted here. Placeholder
// names: rename once the class is known.
#include <vector>

#include "gflib3/Unk_239a418.h"

// The vector's element: 16-aligned (the vector frees it with that alignment).
struct alignas(16) Unk_2435cb8_Element {
    Unk_239a418_Ref<Unk_239a418> field_0;
    u8 _8[0x38];
};
static_assert(sizeof(Unk_2435cb8_Element) == 0x40, "Unk_2435cb8_Element");

class Unk_2435cb8 : public Unk_239a418 {
public:
    ~Unk_2435cb8() override;
    const Unk_239a418_Type* vf_type() override;

    std::vector<Unk_2435cb8_Element, Unk_239a418_StdAllocator<Unk_2435cb8_Element>> field_60;
};
static_assert(sizeof(Unk_2435cb8) == 0x80, "Unk_2435cb8");

// 0x71013d39c0, 0x71013d3aa0 (D0), thunks 0x71013d3c70/0x71013d3d50 (+0x48)
// and 0x71013d3e50/0x71013d3f30 (+0x50)
Unk_2435cb8::~Unk_2435cb8() {}
