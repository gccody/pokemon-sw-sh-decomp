// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x7102438308): a holder (Unk_236d3d8) and two objects it owns, freed
// through allocators, each an array of words and a list. Its destructor is
// its key function: its vtable and thunks are emitted here. Placeholder
// names: rename once the classes are known.
#include <memory>

#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23f4660.h"
#include "unsorted/Unk_2438308.h"

struct Unk_2438308_Node {
    Unk_2438308_Node* m_next;
    u64 field_8;
    u64 field_10;
    u64 field_18;
};

struct Unk_2438308_Owned {
    Unk_2438308_Words<u64> field_0;
    u64 field_18;
    u64 field_20;
    Unk_2438308_List<Unk_2438308_Node> field_28;
};
static_assert(sizeof(Unk_2438308_Owned) == 0x38, "Unk_2438308_Owned");

class Unk_2438308 : public Unk_239a4c0 {
public:
    ~Unk_2438308() override;

    u64 field_58;
    Unk_236d3d8 field_60;
    u64 field_170;
    u64 field_178;
    u64 field_180;
    u64 field_188;
    u64 field_190;
    std::unique_ptr<Unk_2438308_Owned, Unk_23f4660_Deleter> field_198;
    u64 field_1b8;
    std::unique_ptr<Unk_2438308_Owned, Unk_23f4660_Deleter> field_1c0;
};
static_assert(sizeof(Unk_2438308) == 0x1e0, "Unk_2438308");
static_assert(__builtin_offsetof(Unk_2438308, field_198) == 0x198, "Unk_2438308::field_198");
static_assert(__builtin_offsetof(Unk_2438308, field_1c0) == 0x1c0, "Unk_2438308::field_1c0");

// 0x710140c1d0, its D0 and thunks for +0x48
Unk_2438308::~Unk_2438308() {}
