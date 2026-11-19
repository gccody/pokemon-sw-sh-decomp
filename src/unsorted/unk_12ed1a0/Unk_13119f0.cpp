// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x710242f860): a holder (Unk_236d3d8), five references, and an array and
// three objects it owns, freed through allocators. Its destructor is its key
// function: its vtable and thunks are emitted here. Placeholder names: rename
// once the classes are known.
#include <memory>

#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23c9470.h"

struct Unk_242f860_Element {
    Unk_239a418_Ref<Unk_239a418> field_0;
    u64 field_8;
    u64 field_10;
};
static_assert(sizeof(Unk_242f860_Element) == 0x18, "Unk_242f860_Element");

struct Unk_242f860_1c0 {
    Unk_239a418_Ref<Unk_239a418> field_0;
};

struct Unk_242f860_Words {
    u64 field_0;
};

class Unk_242f860 : public Unk_239a4c0 {
public:
    ~Unk_242f860() override;

    u64 field_58;
    Unk_236d3d8 field_60;
    Unk_239a418_Ref<Unk_239a418> field_170;
    Unk_239a418_Ref<Unk_239a418> field_178;
    Unk_239a418_Ref<Unk_239a418> field_180;
    Unk_239a418_Ref<Unk_239a418> field_188;
    Unk_239a418_Ref<Unk_239a418> field_190;
    u64 field_198;
    std::unique_ptr<Unk_242f860_Element[], Unk_23c9470_ArrayDeleter> field_1a0;
    std::unique_ptr<Unk_242f860_1c0, Unk_23f4660_Deleter> field_1c0;
    std::unique_ptr<Unk_242f860_Words, Unk_23f4660_Deleter> field_1e0;
    std::unique_ptr<Unk_242f860_Words, Unk_23f4660_Deleter> field_200;
};
static_assert(sizeof(Unk_242f860) == 0x220, "Unk_242f860");
static_assert(__builtin_offsetof(Unk_242f860, field_1a0) == 0x1a0, "Unk_242f860::field_1a0");
static_assert(__builtin_offsetof(Unk_242f860, field_200) == 0x200, "Unk_242f860::field_200");

// 0x71013119f0, its D0 and thunks for +0x48
Unk_242f860::~Unk_242f860() {}
