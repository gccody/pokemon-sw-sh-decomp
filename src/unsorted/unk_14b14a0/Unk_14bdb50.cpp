// Scope: common
//
// A class on gflib3's other reference-counted object, Unk_239a4c0 (vtable
// 0x7102443150): a holder (Unk_236d3d8) and an array of polymorphic 0x3d0-byte
// elements it owns, freed through an allocator. Its destructor is its key
// function: its vtable and thunks are emitted here. Placeholder names: rename
// once the classes are known.
#include <memory>

#include "gflib3/Unk_239a4c0.h"
#include "unsorted/Unk_236d3d8.h"
#include "unsorted/Unk_23c9470.h"

// The elements: destroyed through their vtables.
class Unk_2443150_Element {
public:
    virtual ~Unk_2443150_Element();

    u8 _8[0x3c8];
};
static_assert(sizeof(Unk_2443150_Element) == 0x3d0, "Unk_2443150_Element");

class Unk_2443150 : public Unk_239a4c0 {
public:
    ~Unk_2443150() override;

    u64 field_58;
    Unk_236d3d8 field_60;
    u64 field_170;
    u64 field_178;
    std::unique_ptr<Unk_2443150_Element[], Unk_23c9470_ArrayDeleter> field_180;
};
static_assert(sizeof(Unk_2443150) == 0x1a0, "Unk_2443150");
static_assert(__builtin_offsetof(Unk_2443150, field_60) == 0x60, "Unk_2443150::field_60");
static_assert(__builtin_offsetof(Unk_2443150, field_180) == 0x180, "Unk_2443150::field_180");

// 0x71014bdb50, its D0 and thunks for +0x48
Unk_2443150::~Unk_2443150() {}
